#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
#define INF 400000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,a[MAXN];
ll sum[MAXN],dp[MAXN];
vector<ll> v;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    ll ans=1LL*sum[n]*k;
    for(int i=1;i<=n-1;i++) v.push_back(sum[i]);
    sort(v.begin(),v.end());
    for(int i=0;i<k-1;i++) ans-=v[i];
    printf("%lld\n",ans);
    return 0;
}