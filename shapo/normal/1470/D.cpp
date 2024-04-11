#include <bits/stdc++.h>

using namespace std;

#define ve vector

typedef ve<int> vi;
typedef ve<vi> v2i;

void
solve()
{
    int n, m;
    cin >> n >> m;
    v2i g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<int> q = {0};
    vi color(n, -1);
    while (!q.empty()) {
        int u = *(q.begin());
        color[u] = 1;
        q.erase(u);
        vi int_q;
        for (int v : g[u]) {
            if (color[v] == -1) {
                color[v] = 0;
                q.erase(v);
                for (int uu : g[v]) {
                    if (color[uu] == -1) {
                        q.insert(uu);
                    }
                }
            }
        }
    }
    if (find(color.begin(), color.end(), -1) != color.end()) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        cout << count(color.begin(), color.end(), 1) << '\n';
        for (int i = 0; i < n; ++i) {
            if (color[i] == 1) {
                cout << i + 1 << ' ';
            }
        }
        cout << '\n';
    }
}

int
main()
{
    cin.sync_with_stdio(false);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
    return 0;
}