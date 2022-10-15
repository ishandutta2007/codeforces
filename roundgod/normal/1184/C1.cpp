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
int n,k;
int x[MAXN],y[MAXN];
bool solve(int id)
{
    int minx=INF,maxx=-INF,miny=INF,maxy=-INF;
    for(int i=1;i<=4*n+1;i++)
    {
        if(i==id) continue;
        minx=min(minx,x[i]);
        maxx=max(maxx,x[i]);
        miny=min(miny,y[i]);
        maxy=max(maxy,y[i]);
    }
    if(minx==maxx||miny==maxy) return false;
    if(maxx-minx!=maxy-miny) return false;
    for(int i=1;i<=4*n+1;i++)
    {
        if(i==id) continue;
        if(x[i]!=maxx&&x[i]!=minx&&y[i]!=maxy&&y[i]!=miny) return false;
        if(x[i]>maxx||x[i]<minx) return false;
        if(y[i]>maxy||y[i]<miny) return false;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=4*n+1;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=4*n+1;i++)
    {
        if(solve(i))
        {
            printf("%d %d\n",x[i],y[i]);
            return 0;
        }
    }
    assert(0);
    return 0;
}