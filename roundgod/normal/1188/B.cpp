#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
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
int n,p,k,a[MAXN];
map<int,int> mp;
void dec(int &a,int b) {a-=b; if(a<0) a+=p;}
int main()
{
    scanf("%d%d%d",&n,&p,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int x=1LL*a[i]*a[i]%p;
        x=1LL*x*x%p;
        dec(x,1LL*a[i]*k%p);
        mp[x]++;
    }
    ll ans=0;
    for(auto p:mp) ans+=1LL*(p.S)*(p.S-1)/2;
    printf("%lld\n",ans);
    return 0;
}