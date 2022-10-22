#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;

vector<vector<int>> a;
vector<int> c;

void dfs(int v, int col) {
    c[v] = col;

    for(auto u : a[v])
        if(c[u] == -1)
            dfs(u, col);
}

int main() {
    int n, m;
    cin >> n >> m;

    a.resize(n);
    c.resize(n, -1);
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        a[v].push_back(u);
        a[u].push_back(v);
    }

    int col = 0;
    for(int i = 0; i < n; i++) {
        if(c[i] == -1)
            dfs(i, col++);
    }

    vector<pair<int, int>> lr(col, {n, 0});
    for(int i = 0; i < n; i++) {
        lr[c[i]].f = min(lr[c[i]].f, i);
        lr[c[i]].s = max(lr[c[i]].s, i);
    }

    vector<int> bp(n, 0), bm(n, 0);

    for(int i = 0; i < col; i++) {
        bp[lr[i].f]++;
        bm[lr[i].s]++;
    }

    int cnt = 0, ans = 0, c = 0;
    for(int i = 0; i < n; i++) {
        cnt += bp[i];
        c += bp[i] - bm[i];

        if(c == 0) {
            ans += cnt - 1;
            cnt = 0;
            c = 0;
        }
    }

    cout << ans;
}