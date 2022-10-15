#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,k,a,b;
int main()
{
    scanf("%lld%lld%lld%lld",&n,&k,&a,&b);
    ll minx=INF,maxx=-INF;
    for(ll i=0;i<2;i++)
        for(ll j=0;j<2;j++)
        {
            ll dis1=(i?a:k-a),dis2=(j?b:k-b);
            ll d=dis2-dis1;
            while(d<=0) d+=k; 
            while(d>k) d-=k;
            ll moves=k/__gcd(d,k);
            ll num=d*moves/k;
            for(ll cyc=0;cyc<n;cyc++) 
            {
                ll res=(cyc*moves+num)%n;
                ll ans=n/__gcd(n,res)*moves;
                minx=min(minx,ans); maxx=max(maxx,ans);
            }
        }
    printf("%lld %lld\n",minx,maxx);
    return 0;
}