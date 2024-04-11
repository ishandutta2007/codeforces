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
ll n,q,a[MAXN];
P ans[2*MAXN];
deque<int> deq;
int main()
{
    scanf("%lld%lld",&n,&q);
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);deq.push_back(a[i]);
    }
    for(ll i=1;i<=2*n;i++)
    {
        ll x=deq.front();
        deq.pop_front();
        ll y=deq.front();
        deq.pop_front();
        ans[i]=make_pair(x,y);
        if(x>y)
        {
            deq.push_front(x);
            deq.push_back(y);
        }
        else
        {
            deq.push_front(y);
            deq.push_back(x);
        }
    }
    for(ll i=0;i<q;i++)
    {
        ll x;
        scanf("%lld",&x);
        if(x<=2*n) printf("%d %d\n",ans[x].F,ans[x].S);
        else
        {
            ll shift=(x-2*n-1)%(n-1);
            printf("%d %d\n",deq.front(),deq[shift+1]);
        }
    }
    return 0;
}