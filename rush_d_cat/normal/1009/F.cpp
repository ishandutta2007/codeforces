#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 1000000 + 10;
int n, dep[N],ans[N];

vector<int> g[N];
unordered_map<int,int> mp[N];

void dfs(int u,int p) {
    dep[u]=dep[p]+1;
    mp[u][dep[u]] ++;
    ans[u] = dep[u];
    for(auto v: g[u]) {
        if(v==p) continue;
        dfs(v,u);
        if(mp[u].size() < mp[v].size()) {
            mp[u].swap(mp[v]);
            ans[u] = ans[v];
        }
        for(auto p: mp[v]) {
            mp[u][p.first] += p.second;
            if (mp[u][ans[u]] < mp[u][p.first] || (mp[u][ans[u]] == mp[u][p.first] && p.first < ans[u])) {
                ans[u] = p.first;
            }
        }
        mp[v].clear();
    }
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<n;i++) {
        int u, v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) {
        printf("%d\n", ans[i]-dep[i]);
    }
}