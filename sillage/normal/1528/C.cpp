#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
vector<int> g[maxn], p[maxn];
int a[maxn], b[maxn], dfn[maxn], Dfn[maxn];
int times = 0;
void dfs(int u) {
    dfn[u] = ++times;
    for (auto v: p[u]) dfs(v);
    Dfn[u] = times;
}
int del[maxn], add[maxn], ans;
set<pair<int, int> > orz;
void dfs2(int u){
    //printf("%d\n", u);
    del[u] = 0;
    add[u] = u;
    if (!orz.empty()) {
        auto p = orz.lower_bound(make_pair(dfn[u], 0));
        if (p != orz.end() && (*p).first <= Dfn[u]) add[u] = 0;
        if (add[u]){
            auto p = orz.upper_bound(make_pair(dfn[u], 0));
            if (p != orz.begin()) {
                p--;
                if (Dfn[(*p).second] >= dfn[u]) {
                    del[u] = (*p).second;
                    orz.erase(p);
                }
            }
        }
    }
    if (add[u]) orz.insert(make_pair(dfn[u], u));
    //printf("%d %d %d\n",u,  del[u], add[u]);
    if (orz.size() > ans) ans = orz.size();
    for (auto v: g[u]) {
        dfs2(v);
    }
    //printf("%d\n", u);
    if (add[u]) orz.erase(orz.find(make_pair(dfn[u], u)));
    if (del[u]) orz.insert(make_pair(dfn[del[u]], del[u]));
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear(), p[i].clear();
    for (int i = 2; i <= n; i++) scanf("%d", &a[i]), g[a[i]].push_back(i);
    for (int i = 2; i <= n; i++) scanf("%d", &b[i]), p[b[i]].push_back(i);
    times = 0;
    dfs(1);
    //cout << "FUK "<< endl;
    orz.clear();
    ans = 0;
    dfs2(1);
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}