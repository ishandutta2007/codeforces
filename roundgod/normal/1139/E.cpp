#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 5005
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
int n,m,p[MAXN],c[MAXN],d,k[MAXN],res;
vector<int> G[2*MAXN];
int match[2*MAXN];
bool used[2*MAXN];
bool del[2*MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||(!used[w]&&dfs(w)))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
void bipartite_matching()
{
    for(int v=res+1;v<=m;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
            else return;
        }
    }
    return;
}
vector<int> ans;
int main()
{
    scanf("%d%d",&n,&m);
    memset(del,false,sizeof(del));
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    scanf("%d",&d);
    for(int i=1;i<=d;i++) {scanf("%d",&k[i]); del[k[i]]=true;}
    for(int i=1;i<=n;i++)
    {
        if(!del[i]) 
        {
            if(p[i]<m) add_edge(p[i]+1,m+c[i]);
        }
    }
    memset(match,-1,sizeof(match));
    for(int i=d;i>=1;i--)
    {
        bipartite_matching();
        ans.push_back(res);
        int v=k[i];
        if(p[v]<m) add_edge(p[v]+1,m+c[v]);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans) printf("%d\n",x);
    return 0;
}