#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
ll n,h,a[MAXN];
bool check(ll x)
{
    vector<int> v;v.clear();
    for(ll i=1;i<=x;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    if(v.size()&1)
    {
        ll sum1=v[0],sum2=v[x-1];
        for(ll i=2;i<=x-1;i+=2) sum1+=v[i];
        for(ll i=1;i<x-1;i+=2) sum2+=v[i];
        return h>=min(sum1,sum2);
    }
    else
    {
        ll sum=0;
        for(ll i=1;i<=x-1;i+=2) sum+=v[i];
        return h>=sum;
    }
}
int main()
{
    scanf("%lld%lld",&n,&h);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll l=1,r=n+1;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%lld\n",l);
    return 0;
}