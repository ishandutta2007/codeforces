#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e6;

bool fl = 0;
vector <vector <int> > g(INF);
vector <int> used(INF, 0), used1(INF, 0);
void dfs(int v, int prev) {
    //if (used[v]) return;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        if (used[g[v][i]] && g[v][i] != prev) {
            fl = 1;
            return;
        } else if (!used[g[v][i]]) {
            dfs(g[v][i], v);
            if (fl) return;
        }
    }
}
void dfs1(int v) {
    if (used1[v]) return;
    used1[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        dfs1(g[v][i]);
    }
}
int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (used1[i]) continue;
        fl = 0;
        dfs(i, -1);
        if (!fl) sum++;
        dfs1(i);
    }
    cout << sum << endl;
}