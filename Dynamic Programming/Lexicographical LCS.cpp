string dp[N][N];
void lexicographicalLCS(string A,string B)
{
    int i,j,m=A.size(),n=B.size();
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
                dp[i][j]="";
            else if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1]+A[i-1];
            else if(dp[i-1][j].size()>dp[i][j-1].size())
                dp[i][j]=dp[i-1][j];
            else if(dp[i-1][j].size()<dp[i][j-1].size())
                dp[i][j]=dp[i][j-1];
            else if(dp[i-1][j]<dp[i][j-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    if(dp[m][n].size()==0)
        cout<<"No solution"<<endl;
    else
        cout<<dp[m][n]<<endl;
}