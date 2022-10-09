#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<vector<int>> g;
vector<bool> used;
vector<bool> bad;
int m;
int ans = 0;

void dfs(int v, int cnt) {
    if (bad[v]) {
        cnt++;
    } else {
        cnt = 0;
    }
    if (cnt > m) {
        return;
    }
    used[v] = true;
    int sons = 0;
    for (int to: g[v]) {
        if (!used[to]) {
            sons++;
            dfs(to, cnt);
        }
    }
    if (sons == 0) {
        ans++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n >> m;
    g.resize(n);
    bad.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            bad[i] = true;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);
    cout << ans << endl;
}