#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define INF 10000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,m,ta,tb,k,a[MAXN],b[MAXN];
int main()
{
    scanf("%lld%lld%lld%lld%lld",&n,&m,&ta,&tb,&k);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=m;i++) scanf("%lld",&b[i]);
    ll ans=0;
    for(ll i=0;i<=k;i++)
    {
        ll x=i,y=k-i;
        if(n<=x||m<=y) ans=max(ans,INF);
        else
        {
            ll id=lower_bound(b+1,b+m+1,a[x+1]+ta)-b;
            if(id+y>m) ans=max(ans,INF); else ans=max(ans,b[id+y]+tb);
        }
    }
    if(ans==INF) puts("-1"); else printf("%lld\n",ans);
    return 0;
}