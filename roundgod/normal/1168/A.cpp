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
int n,m,a[MAXN];
bool check(int x)
{
    int last=0;
    for(int i=1;i<=n;i++)
    {
        int l=a[i],r=(a[i]+x)%m;
        if(r>=l)
        {
            if(r<last) return false;
            last=max(last,l);
        }
        else
        {
            if(r<last) last=max(last,l); 
        }
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l=-1,r=m-1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid; else l=mid;
    }
    printf("%d\n",r);
    return 0;
}