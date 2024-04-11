#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 500000+10;
char s[N]; int n, m, v1[N], v2[N], dep[N];
vector<int> g[N], query[N];
map<int,int> mp[N];
map< pair<int,int>, int > ans;
bool ok[67108865];
void dfs(int u,int p) {
    dep[u] = dep[p] + 1;
    mp[u][dep[u]] |= (1<<(s[u]-'a'));
    for(auto v: g[u]) {
        dfs(v,u);
        if(mp[u].size() < mp[v].size()) {
            mp[u].swap(mp[v]);
        }
        for(auto p: mp[v]) {
            mp[u][p.first] ^= p.second;
        }
        mp[v].clear();
    }
    for(auto x: query[u]) {
        if (ok[mp[u][x]]) 
            ans[make_pair(u, x)] = 1;
        else
            ans[make_pair(u, x)] = 0;
    }
}

int main() {
    ok[0] = 1;
    for(int i=0;i<26;i++) {
        ok[1<<i] = 1;
    }
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++) {
        int p; scanf("%d",&p);
        g[p].push_back(i);
    }
    scanf("%s", s+1);
    for(int i=1;i<=m;i++) {
        scanf("%d%d",&v1[i],&v2[i]);
        query[v1[i]].push_back(v2[i]);
    }
    dfs(1,0);
    for(int i=1;i<=m;i++) {
        printf("%s\n", ans[make_pair(v1[i], v2[i])] ? "Yes" : "No");
    }
}