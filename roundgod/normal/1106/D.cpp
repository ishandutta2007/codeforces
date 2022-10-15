#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> G[MAXN];
set<int> s;
bool vis[MAXN];
vector<int> ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    s.insert(1);
    for(int i=1;i<=n;i++)
    {
        auto it=s.begin();
        ans.push_back(*it);
        int v=*it;
        s.erase(s.begin());
        vis[v]=true;
        for(auto to:G[v]) if(!vis[to]) s.insert(to);
    }
    for(auto v:ans) printf("%d ",v);
    return 0;
}