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
int n,k,a[MAXN];
vector<int> v;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        v.push_back(abs(x));
    }
    sort(v.begin(),v.end());
    ll ans=0;
    int pos=0;
    for(int i=0;i<n;i++)
    {
        while(pos<i&&2*v[pos]<v[i]) pos++;
        ans+=i-pos;
    }
    printf("%lld\n",ans);
    return 0;
}