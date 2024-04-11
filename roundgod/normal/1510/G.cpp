#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,rem;
vector<int> G[MAXN];
int fa[MAXN],depth[MAXN];
vector<int> order;
bool mark[MAXN];
void dfs(int v)
{
    for(auto to:G[v])
    {
        depth[to]=depth[v]+1;
        dfs(to);
    }
}
void dfs2(int v)
{
    order.push_back(v);
    if(!mark[v]) rem--;
    if(rem)
    {
        for(auto to:G[v])
        {
            if(!rem) break;
            if(!mark[to])
            {
                dfs2(to);
                order.push_back(v);
            }
        }
    }
    for(auto to:G[v]) if(mark[to]) dfs2(to);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&fa[i]);
            G[fa[i]].push_back(i);
        }
        depth[1]=0;
        dfs(1);
        memset(mark,false,sizeof(mark));
        int res=0;
        for(int i=1;i<=n;i++) res=max(res,depth[i]); 
        res=min(res,k-1);
        int id=-1;
        for(int i=1;i<=n;i++) if(depth[i]==res) {id=i; break;}
        rem=k-(depth[id]+1);
        while(id)
        {
            mark[id]=true;
            id=fa[id];
        }
        order.clear();
        dfs2(1);
        printf("%d\n",(int)order.size()-1);
        for(auto x:order) printf("%d ",x);
        puts("");
    }
    return 0;
}