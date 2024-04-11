#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void dfs(vector < vector < int > >& g, int v, vector < int > &c, vector < bool >& used) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    c.push_back(v);

    for (int i = 0; i < g[v].size(); ++i) {
        if (!used[g[v][i]]) {
            dfs(g, g[v][i], c, used);
        }
    }
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector < vector < int > > g(n);
    vector < bool > have(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        if (x == y) {
            continue;
        }
        have[x] = true;
        g[x].push_back(y);
        g[y].push_back(x);
    }


    vector < bool > used(n, false);
    int res = 0;
    for (int i = 0; i < n; ++i) {;
        if (!used[i]) {
            vector < int > c;
            dfs(g, i, c, used);

            int cnt = 0;
            for (int j = 0; j < c.size(); ++j) {
                if (have[c[j]]) {
                    ++cnt;
                }
            }
            if (cnt == 0) {
                continue;
            }
            if (cnt < c.size()) {
                res += cnt;
            } else {
                res += cnt + 1;
            }
        }
    }
    printf("%d\n", res);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}