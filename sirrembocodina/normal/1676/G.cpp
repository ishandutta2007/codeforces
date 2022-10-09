#include <bits/stdc++.h>

using namespace std;

#define int int64_t

string s;
vector<vector<int>> sons;
vector<int> w, b;
int ans = 0;

void dfs(int v) {
    if (s[v] == 'W') {
        w[v]++;
    } else {
        b[v]++;
    }
    for (int to: sons[v]) {
        dfs(to);
        w[v] += w[to];
        b[v] += b[to];
    }
    if (w[v] == b[v]) {
        ans++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        sons.clear();
        sons.resize(n);
        w.assign(n, 0);
        b.assign(n, 0);
        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            p--;
            sons[p].push_back(i);
        }
        cin >> s;
        ans = 0;
        dfs(0);
        cout << ans << '\n';
    }
}