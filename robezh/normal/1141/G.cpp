#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

struct edge {
    int to, id;

};

int n, k;
int c[N];
int mx;
vector<edge> G[N];
int deg[N];

void dfs(int v, int p) {
    int cur = 0, cled = -1;
    for(const auto &e: G[v]) {
        if(c[e.id] != -1) cled = c[e.id];
    }
    for(const auto &e : G[v]) {
        if(e.to == p) continue;
        if(cur == cled && cur + 1 < mx) cur++;
        c[e.id] = cur;
        if(cur + 1 < mx) cur++;
        dfs(e.to, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    fill(c, c + n, -1);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        deg[a]++, deg[b]++;
    }
    sort(deg, deg + n);
    mx = deg[n - 1 - k];
    cout << mx << endl;
    dfs(0, -1);
    for(int i = 0; i < n - 1; i++) cout << c[i] + 1 << " ";
}