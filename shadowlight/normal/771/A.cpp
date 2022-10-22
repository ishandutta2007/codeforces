#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<bool> used;
vector<vector<int>> g;

int cntNow = 0;
int cnt = 0;

void dfs(int v, bool isFirst = true) {
    used[v] = true;
    ++cnt;
    if (isFirst) {
        cntNow = g[v].size();
    } else {
        if (g[v].size() != cntNow) {
            cout << "NO\n";
            exit(0);
        }
    }
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs(to, false);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    used.resize(n, false);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            cnt = 0;
            dfs(i);
            if (cntNow != cnt - 1) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}