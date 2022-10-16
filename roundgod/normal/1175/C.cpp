#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
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
ll T,n,k,a[MAXN];
ll ans=0;
bool check(ll x)
{
    ll l=1,r=1,cnt=0;
    while(r<=n)
    {
        if(a[r]-x<=a[l]+x) 
        {
            cnt++; r++; 
            if(cnt>k) 
            {
                ans=a[l]+x;
                return true;
            }
        }
        else {l++; cnt--;}
    }
    return false;
}
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
        a[n+1]=10LL*INF+1;
        ll l=-1,r=INF+1;
        while(r-l>1)
        {
            ll mid=(l+r)/2;
            if(check(mid)) r=mid; else l=mid;
        }
        printf("%lld\n",ans);
    }
    return 0;
}