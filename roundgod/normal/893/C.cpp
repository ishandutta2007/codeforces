#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll p[MAXN],r[MAXN],cost[MAXN],n,m;
bool used[MAXN];
void init(ll n)
{
    for(ll i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
ll find(ll x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(ll x,ll y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; cost[y]=min(cost[y],cost[x]);}
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        cost[x]=min(cost[x],cost[y]);
    }
}
bool same(ll x,ll y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%I64d%I64d",&n,&m);
    for(ll i=0;i<n;i++)
        scanf("%I64d",&cost[i]);
    init(n);
    for(ll i=0;i<m;i++)
    {
        ll x,y;
        scanf("%I64d%I64d",&x,&y);
        unite(x-1,y-1);
    }
    memset(used,false,sizeof(used));
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ll x=find(i);
        if(!used[x])
        {
            ans+=cost[x];
            used[x]=true;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}