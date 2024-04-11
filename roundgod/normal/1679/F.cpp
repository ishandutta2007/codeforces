#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
bool has[10][10];
int dp[(1<<10)],ndp[(1<<10)];
int pre[(1<<10)][10];
int get_mask(int mask,int i)
{
    int nmask=0;
    for(int j=0;j<=9;j++) 
    {
        if(j<i&&has[i][j]) nmask|=(1<<j);
        if(mask&(1<<j)&&has[i][j]) nmask|=(1<<j);
    }
    return nmask;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d",&n,&m);
    memset(has,false,sizeof(has));
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        has[u][v]=has[v][u]=true;
    }
    for(int mask=0;mask<(1<<10);mask++)
        for(int i=0;i<=9;i++)
            if(!(mask&(1<<i)))
                pre[mask][i]=get_mask(mask,i);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        memset(ndp,0,sizeof(ndp));
        for(int mask=0;mask<(1<<10);mask++)
        {
            for(int j=0;j<=9;j++)
            {
                if(!(mask&(1<<j)))
                {
                    add(ndp[pre[mask][j]],dp[mask]);
                }
            }
        }
        swap(dp,ndp);
    }
    int ans=0;
    for(int mask=0;mask<(1<<10);mask++) add(ans,dp[mask]);
    printf("%d\n",ans);
    return 0;
}