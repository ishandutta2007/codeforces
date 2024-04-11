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
int ask(int l,int r)
{
    printf("1 %d ",r-l+1);
    printf("%d ",n);
    for(int i=l;i<=r;i++) printf("%d%c",i,i==r?'\n':' ');
    fflush(stdout);
    int x; scanf("%d",&x);
    return x;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int d=ask(1,n-1),l=1,r=n-1;
        while(r>l)
        {
            int mid=(l+r)/2;
            int dd=ask(l,mid);
            if(dd==d) r=mid; else l=mid+1;  
        }
        printf("1 %d ",n-1);
        printf("%d",l);
        for(int i=1;i<=n;i++) 
        {
            if(i==l) continue;
            printf(" %d",i);
        }
        printf("\n");
        fflush(stdout);
        int x; scanf("%d",&x);
        printf("-1 %d\n",x); fflush(stdout);
    }
    return 0;
}