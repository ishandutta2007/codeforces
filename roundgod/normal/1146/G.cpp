#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,h,m;
ll a[MAXN],b[MAXN],x[MAXN],c[MAXN];
ll f[MAXN][MAXN][MAXN],g[MAXN][MAXN][MAXN];
ll cost[MAXN][MAXN];
//f[i][j][k]: maximum profit interval[i,j], tallest height = k
//g[i][j][k]: maximum profit interval[i,j] tallest height <= k
int main()
{
    scanf("%lld%lld%lld",&n,&h,&m);
    for(ll i=1;i<=m;i++) 
    {
        scanf("%lld%lld%lld%lld",&a[i],&b[i],&x[i],&c[i]);
    }
    for(ll len=1;len<=n;len++)
    {
        for(ll l=1;l+len-1<=n;l++)
        {
            ll r=l+len-1;
            for(ll k=0;k<=h;k++)
            {
                memset(cost,0,sizeof(cost));
                for(ll i=1;i<=m;i++)
                {
                    if(a[i]>=l&&b[i]<=r)
                        for(ll j=a[i];j<=b[i];j++) cost[j][x[i]+1]+=c[i];
                }
                for(ll i=l;i<=r;i++)
                    for(ll j=1;j<=h;j++)
                        cost[i][j]+=cost[i][j-1];
                f[l][r][k]=g[l][r][k]=-INF;
                for(ll pos=l;pos<=r;pos++)
                {
                    f[l][r][k]=max(f[l][r][k],(pos-1>=l?g[l][pos-1][k]:0)+(r>=pos+1?g[pos+1][r][k]:0)+k*k-cost[pos][k]);
                }
                for(ll i=0;i<=k;i++) g[l][r][k]=max(g[l][r][k],f[l][r][i]);
            }
        }
    }
    printf("%lld\n",g[1][n][h]);
    return 0;
}