#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,now,a[17][10005];
struct edge {int to,type;};
bool con[17][17];
bool dp[(1<<16)][16][16];
vector<int> G[17];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool C(int x)
{
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            bool f=true;
            for(int k=1;k<=m;k++) if(abs(a[i][k]-a[j][k])<x) {f=false; break;}
            if(f) add_edge(i,j);
        }
    memset(dp,false,sizeof(dp));
    for(int i=0;i<n;i++) dp[(1<<i)][i][i]=true;
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!(i&(1<<j))) continue;
            for(int k=0;k<n;k++)
            {
                if(!dp[i][j][k]) continue;
                for(auto to:G[j+1])
                {
                    if(i&(1<<(to-1))) continue;
                    dp[i|(1<<(to-1))][to-1][k]=true;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(dp[(1<<n)-1][i][j])
            {
                bool f=true;
                for(int k=1;k<=m-1;k++) if(abs(a[i+1][k]-a[j+1][k+1])<x) {f=false; break;}
                if(f) return true;
            }
        }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    if(n==1)
    {
        int ans=INF;
        for(int i=1;i<=m-1;i++) ans=min(ans,abs(a[1][i]-a[1][i+1]));
        printf("%d\n",ans); return 0;
    }
    int l=0,r=INF+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(C(mid)) l=mid; else r=mid;
    }
    printf("%d\n",l);
    return 0;
}