#include<bits/stdc++.h>
using namespace std;
#define ll long long
int g[200001];
vector<int> divs[200001];
int m = 2e5;
int U[200000];
int V[200000];
vector<int> E[200001];
vector<int> adj[200001];
bool vis[200001];
ll sz=0;
void dfs(int v){
    sz++;
    vis[v]=1;
    for (auto u:adj[v])
        if(!vis[u])dfs(u);
}
ll ret[1000000];
ll ans[1000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&g[i]);
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j+=i)
            divs[j].push_back(i);
    for (int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        U[i]=u;
        V[i]=v;
        int l=0,r=0;
        while(l<divs[g[u]].size() && r<divs[g[v]].size()) {
            if (divs[g[u]][l] == divs[g[v]][r])E[divs[g[u]][l]].push_back(i),l++,r++;
            else if (divs[g[u]][l]<divs[g[v]][r])l++;
            else r++;
        }
    }
    for (int i=1;i<=m;i++) {
        for (auto e:E[i]) {
            adj[U[e]].push_back(V[e]);
            adj[V[e]].push_back(U[e]);
        }
        for (auto e:E[i]) {
            if (!vis[U[e]]){
                sz=0;
                dfs(U[e]);
                ret[i]+=sz*(sz-1)/2;
            }
            if (!vis[V[e]]){
                sz=0;
                dfs(V[e]);
                ret[i]+=sz*(sz-1)/2;
            }
        }
        for (auto e:E[i]) {
            adj[U[e]].clear();
            adj[V[e]].clear();
            vis[U[e]]=0;
            vis[V[e]]=0;
        }
    }
    for (int i=m;i>=1;i--) {
        ans[i]=ret[i];
        for (int j=i+i;j<=m;j+=i)
            ans[i]-=ans[j];
    }
    for (int i=1;i<=n;i++)ans[g[i]]++;
    for (int i=1;i<=m;i++) {
        if (ans[i]) {
            printf("%d %lld\n",i,ans[i]);
        }
    }

}