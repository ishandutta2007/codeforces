#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n,m,k,mx;
vector<int> G[N];
bool vis[N];
int idx = 0;
vector<int> res[N];

void add(int v) {
    res[idx].push_back(v);
    if(res[idx].size() == mx) idx++;
}

void dfs(int v) {
    vis[v] = true;
    add(v);
    for(int nxt : G[v]) {
        if(vis[nxt]) continue;
        dfs(nxt);
        add(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    mx = (2 * n + k - 1) / k;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0);
    for(int i = 0; i < k; i++) {
        if(res[i].empty()) cout << "1 1\n";
        else {
            cout << res[i].size() << " ";
            for(int x : res[i]) cout << x + 1 << " ";
            cout << "\n";
        }
    }
}