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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n); for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector<int> v;
        for(int i=1;i<=n-1;i++) if(a[i]==a[i+1]) v.push_back(i);
        if(v.size()<=1) puts("0"); else printf("%d\n",max(1,v.back()-v[0]-1));
    }
    return 0;
}