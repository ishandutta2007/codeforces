#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 100000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll a[MAXN],d;
int main()
{
    scanf("%lld%lld%lld%lld",&a[0],&a[1],&a[2],&d);
    sort(a,a+3);
    ll ans=INF;
    if(a[1]-a[0]>=d) ans=max(0LL,d-(a[2]-a[1]));
    else ans=max(0LL,d-(a[2]-a[1]))+max(0LL,d-(a[1]-a[0]));
    printf("%lld\n",ans);
    return 0;
}