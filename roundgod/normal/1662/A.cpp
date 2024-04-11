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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=10;i++) a[i]=0;
        for(int i=0;i<n;i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            a[y]=max(a[y],x);
        }
        bool f=true;
        int sum=0;
        for(int i=1;i<=10;i++) if(!a[i]) f=false; else sum+=a[i];
        if(!f) puts("MOREPROBLEMS"); else printf("%d\n",sum);
    }
    return 0;
}