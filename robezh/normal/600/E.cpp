#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n, c[N];
int idx[N];
ll dom_sum[N];
ll res[N];
int dcnt[N];
map<int, int> mp[N];
vector<int> G[N];

int unite(int u, int v) {
    if(mp[u].size() > mp[v].size()) swap(u, v);
    for(const auto &p : mp[u]) {
        int &cnt = mp[v][p.first];
        int add = p.second;
        cnt += p.second;
        if(cnt > dcnt[v]) dcnt[v] = cnt, dom_sum[v] = 1LL * p.first;
        else if(cnt == dcnt[v]) dom_sum[v] += 1LL * p.first;
    }
    return v;
}

int dfs(int v, int p) {
    int cur = v;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        cur = unite(cur, dfs(nxt, v));
    }
    res[v] = dom_sum[cur];
    return cur;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        dom_sum[i] = c[i];
        dcnt[i] = 1;
        idx[i] = i;
        mp[i][c[i]] ++;
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}