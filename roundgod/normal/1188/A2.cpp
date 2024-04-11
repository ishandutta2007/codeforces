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
int n;
int a[MAXN],b[MAXN],w[MAXN];
vector<int> G[MAXN];
bool isleaf[MAXN];
vector<int> leaves;
struct node
{
    int x,y,w;
};
vector<node> ans;
int get_leaf(int v,int p)
{
    if(isleaf[v]) return v;
    for(auto to:G[v])
    {
        if(to==p) continue;
        return get_leaf(to,v);
    }
    return -1;
}
void add_edge(int u,int v,int w)
{
    ans.push_back((node){u,v,w});
}
void solve1(int u,int v,int w)//u is a leaf
{
    if(isleaf[v]) add_edge(u,v,w);
    else
    {
        leaves.clear();
        for(auto to:G[v])
        {
            int l=get_leaf(to,v);
            if(l!=u) leaves.push_back(l);
        }
        assert(leaves.size()>=2);
        int l1=leaves[0],l2=leaves[1];
        add_edge(l1,u,w/2); add_edge(l2,u,w/2); add_edge(l1,l2,-w/2);
    }
}
void solve2(int u,int v,int w)
{
    if(isleaf[u]) solve1(u,v,w);
    else if(isleaf[v]) solve1(v,u,w);
    else 
    {
        int l=get_leaf(u,v);
        solve1(l,u,-w); solve1(l,v,w);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&w[i]);
        G[a[i]].push_back(b[i]); G[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        isleaf[i]=((int)G[i].size()==1);
        if((int)G[i].size()==2)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for(int i=0;i<n-1;i++) solve2(a[i],b[i],w[i]);
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d %d\n",p.x,p.y,p.w);
    return 0;
}