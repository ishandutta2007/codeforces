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
ll n,m;
ll cnt[MAXN],sum[MAXN];
ll solve(ll x)
{
    ll rest=m-x,ret=0;
    for(ll i=1;i<=100;i++)
    {
        if(cnt[i]*i>rest) return ret+rest/i;
        else 
        {
            rest-=cnt[i]*i;
            ret+=cnt[i];
        }
    }
    return ret;
}
void add(ll x)
{
    cnt[x]++;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
    {
        ll x;
        scanf("%lld",&x);
        printf("%lld ",i-1-solve(x));
        add(x);
    }
    return 0;
}