#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<int>> g;
int sum = 0;
int poch = 0;

bool dfs(int v, int p) {
    int cnt = 0;
    for (int to: g[v]) {
        if (to == p) {
            continue;
        }
        cnt += dfs(to, v);
    }
    sum += cnt;
    if (cnt) {
        poch++;
    }
    return cnt == 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        g.clear();
        g.resize(n);
        forn (i, n - 1) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        sum = 0;
        poch = 0;
        dfs(0, -1);
        cout << sum - poch + 1 << '\n';
    }
    return 0;
}