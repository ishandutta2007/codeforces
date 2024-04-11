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
int n,k,p[MAXN],inv[MAXN];
vector<P> ans;
void go(int x,int y)
{
    ans.push_back(P(x,y));
}
void change(int x,int y)
{
    if(2*abs(x-y)>=n) go(x,y);
    else if(x<=n/2&&y<=n/2)
    {
        go(x,n); go(y,n); go(x,n);
    }
    else if(x>n/2&&y>n/2)
    {
        go(x,1); go(y,1); go(x,1);
    }
    else if(x<=n/2&&y>n/2)
    {
        go(x,n); go(y,1); go(1,n); go(x,n); go(y,1);
    }
    else if(y<=n/2&&x>n/2)
    {
        go(y,n); go(x,1); go(1,n); go(y,n); go(x,1);
    }
    swap(p[x],p[y]);
    inv[p[x]]=x; inv[p[y]]=y;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&p[i]);
        inv[p[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(inv[i]==i) continue;
        else change(inv[i],i);
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}