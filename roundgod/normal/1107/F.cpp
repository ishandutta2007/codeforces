#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define MAXV 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
ll a[MAXN],b[MAXN],k[MAXN];
ll w[MAXN][MAXN];
//minimum weight bipartite matching
ll km(ll n,ll m)
{
    vector<int> u(n+1),v(m+1),p(m+1),way(m+1);
    for(ll i=1;i<=n;i++) 
    {
        p[0]=i;
        ll j0=0;
        vector<int> minv(m+1,INF);
        vector<char> used(m+1,false);
        do 
        {
            used[j0]=true;
            ll i0=p[j0],delta=INF,j1=0;
            for(ll j=1;j<=m;++j)
                if(!used[j]) 
                {
                    ll cur=w[i0][j]-u[i0]-v[j];
                    if(cur<minv[j]) minv[j]=cur,way[j]=j0;
                    if(minv[j]<delta) delta=minv[j],j1=j;
                }
            for(ll j=0;j<=m;++j) if(used[j]) u[p[j]]+=delta,v[j]-=delta; else minv[j]-=delta;
            j0=j1;
        }while(p[j0]!=0);
        do 
        {
            ll j1=way[j0];
            p[j0]=p[j1];
            j0=j1;
        }while(j0);
    }
    ll res=0;
    for(ll i=1;i<=m;i++) res+=w[p[i]][i];
    return -res;
}
int main()
{
    scanf("%lld",&n);
    for(ll i=0;i<n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&k[i]);
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            w[i+1][j+1]=-(max(0LL,a[j]-min(i,k[j])*b[j]));
    printf("%lld\n",km(n,n));
    return 0;
}