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
ll x,y,z;
int main()
{
    scanf("%lld%lld%lld",&x,&y,&z);
    ll maxi=(x+y)/z;
    printf("%lld ",maxi);
    if(x/z+y/z==maxi) printf("0\n"); else printf("%lld\n",min(z-x%z,z-y%z));
    return 0;
}