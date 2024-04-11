#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
vector<int> G[2][MAXN];
int st[MAXN],ed[MAXN];
int cur,ans,tot;
//key: to choose a maximum subset where no two vertices are ancesters of each other
//just sort by starting time of dfs order, one is chosen if it doesn't conflict with next one
//proof: think of greedy scheduling algorithm, noting that in dfs order, no two intervals intersect except containing
void dfs(int v)
{
    st[v]=++tot;
    for(auto to:G[1][v]) dfs(to);
    ed[v]=tot;
}
bool is_anc(int x,int y)
{
    return st[x]<=st[y]&&ed[x]>=ed[y];
}
set<P> s;
void dfs2(int v)
{
    int save=cur;
    auto it=s.lower_bound(P(st[v],0));
    if(it!=s.end()) cur+=(1-is_anc(v,it->S));
    if(it!=s.begin())
    {
        auto tmp=it; tmp--;
        if(it!=s.end()) cur-=(1-is_anc(tmp->S,it->S));
        cur+=(1-is_anc(tmp->S,v));
    }
    ans=max(ans,cur);
    s.insert(P(st[v],v));
    for(auto to:G[0][v]) dfs2(to);
    s.erase(s.find(P(st[v],v)));
    cur=save;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[0][i].clear(),G[1][i].clear();
        for(int i=2;i<=n;i++)
        {
            int p;
            scanf("%d",&p);
            G[0][p].push_back(i); 
        }
        for(int i=2;i<=n;i++)
        {
            int p;
            scanf("%d",&p);
            G[1][p].push_back(i); 
        }
        tot=0; dfs(1);
        cur=1; ans=0; s.clear();
        dfs2(1);
        printf("%d\n",ans);
    }
    return 0;
}