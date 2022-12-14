#include <bits/stdc++.h>
using namespace std;
set<int> down[1000000];
set<int> has[1000000];
set<int> up;
set<int> hasUp[1000000];
vector<int> Q[1000000];
int ans[1000000];
vector<int> adj[1000000];
void dfs(int v,int p)
{
    for (auto x:hasUp[v])up.insert(x);
    int mx=has[v].size(),big=-1;
    for (auto u:adj[v])
    {
        if (u!=p) {
            dfs(u,v);
            if (down[u].size()>mx) {
                mx=down[u].size();
                big = u;
            }
        }
    }
    if (big==-1) {
        swap(has[v],down[v]);
    } else {
        swap(down[v],down[big]);
        for (auto x:has[v])down[v].insert(x);
    }
    for (auto u:adj[v]) {
        if (u!=p && u!=big) {
            for (auto x:down[u])down[v].insert(x);
        }
    }
    for (auto q:Q[v]) {
        auto U = up.lower_bound(q);
        int Up = -1;
        if (U!=up.begin())Up = *(--U);
        auto D = down[v].lower_bound(q);
        int Down = -1;
        if (D!=down[v].begin())Down = *(--D);
        if (Up==-1) {
            ans[q]=0;
        } else if (Down>Up) {
            ans[q]=0;
        } else {
            ans[q]=1;
        }
    }
    for (auto x:hasUp[v])up.erase(x);
    //sz[v]=down[v].size();
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    scanf("%d",&q);
    vector<int> ret;
    for (int i=1;i<=q;i++) {
        int t,v;
        scanf("%d%d",&t,&v);
        if (t==1) {
            hasUp[v].insert(i);
        } else if (t==2) {
            has[v].insert(i);
        } else {
            Q[v].push_back(i);
            ret.push_back(i);
        }
    }
    dfs(1,0);
    for (auto x:ret)printf("%d\n",ans[x]);
}