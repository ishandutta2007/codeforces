#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> used(n, false);
    vector<int> p;
    deque<int> q = {0};
    used[0] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        p.push_back(u);
        for (int v : g[u]) {
            if (!used[v]) {
                q.push_back(v);
                used[v] = true;
            }
        }
    }

    if (p.size() != n) {
        cout << "NO\n";
    } else {
        vector<int> a(n, -1);
        for (int u : p) {
            bool has = false;
            for (int v : g[u]) {
                if (a[v] == 1)
                    has = true;
            }

            a[u] = has ? 0 : 1;
        }

        vector<int> answer;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1)
                answer.push_back(i);
        }

        cout << "YES\n" << answer.size() << "\n";
        for (int u : answer)
            cout << u + 1 << " ";
        cout << "\n";
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}