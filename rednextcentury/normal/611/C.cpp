# include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
int row[1000][1000];
int col[1000][1000];
int dp[1000][1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            row[i][j]=row[i][j-1];
            if (a[i][j]=='.' && a[i-1][j]=='.')
                row[i][j]++;
        }
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            col[i][j]=col[i][j-1];
            if (a[j][i]=='.' && a[j][i-1]=='.')
                col[i][j]++;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(a[i][j]==a[i][j-1] && a[i][j]=='.')+(a[i][j]==a[i-1][j] && a[i][j]=='.');
        }
    }
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++)
    {
        int A,B,C,D;
        scanf("%d%d%d%d",&A,&B,&C,&D);
        printf("%d\n",dp[C][D]+dp[A-1][B-1]-dp[A-1][D]-dp[C][B-1]-row[A][D]-col[B][C]+row[A][B-1]+col[B][A-1]);
    }
}