#include <bits/stdc++.h>
using namespace std;
long long dp[1<<20][21];
bool adj[101][101];
bool vis[2000000];
int sm[2000000];
int get(int x)
{
    for (int i=0;i<20;i++)
        if ((1<<i)&x)
            return i;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x][y]=adj[y][x]=1;
    }
    get(14);
    int tot=(1<<n)-1;
    for (int i=1;i<=tot;i++)
        sm[i]=get(i);
    for (int i=0;i<n;i++)
        dp[1<<i][i]=1;
    long long ret=0;
    for (int i=1;i<=tot;i++)
    {
        int p=__builtin_popcount(i);
        if (p==1)continue;
        for (int x=0;x<n;x++)
        {
            if ((1<<x)&i && x>sm[i])
            {
                for (int j=0;j<n;j++)
                {
                    if (j!=x && (1<<j)&i && adj[j][x] && (j!=sm[i] || p==2))
                        dp[i][x]+=dp[i-(1<<x)][j];
                }
                if (p!=2 && adj[x][sm[i]])
                    ret+=dp[i][x];
            }
        }
    }
    cout<<ret/2<<endl;
}