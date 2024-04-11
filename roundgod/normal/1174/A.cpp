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
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    bool f=false;
    for(int i=2;i<=2*n;i++) if(a[i]!=a[i-1]) f=true;
    if(!f) puts("-1");
    else
    {
        for(int i=1;i<=2*n;i++) printf("%d ",a[i]);
    }
    return 0;
}