#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;

vector <vector <pair <int, int> > > neighbours, neighb;
vector <vector <int> > dp, parent;

set <int> q;

const int INF = 1e9 + 7;

int n, m, t;

vector <int> used;
vector <int> pos;
void dfs(int v) {
    pos[v] = 1;
    //cout << v << endl;
    for (int i = 0; i < neighb[v].size(); i++) {
        int u = neighb[v][i].first, k = neighb[v][i].second;
        if (!pos[u]) dfs(u);
        //cout << v << " " << u << " " << k << endl;
        for (int j = 2; j <= n; j++) {
            if (dp[v][j] > dp[u][j - 1] + k) {
                dp[v][j] = dp[u][j - 1] + k;
                parent[v][j] = u;
                //cout << u << " " << v << " " << j + 1 << endl;
            }
        }
    }
}

void dfs1(int v) {
    if (used[v]) return;
    used[v] = 1;
    for (int i = 0; i < neighbours[v].size(); i++) {
        int u = neighbours[v][i].first;
        dfs1(u);
    }
}


int main() {
    cin >> n >> m >> t;
    dp.resize(n + 1, vector <int> (n + 1, INF));
    parent.resize(n + 1, vector <int> (n + 1, INF));
    used.resize(n + 1, 0);
    pos.resize(n + 1, 0);
    neighbours.resize(n + 1);
    neighb.resize(n + 1);
    for (int i = 0; i < m; i++) {
       int l, r, c;
       cin >> l >> r >> c;
       neighbours[l].push_back({r, c});
    }
    dp[1][1] = 0;
    dfs1(1);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            neighbours[i].clear();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < neighbours[i].size(); j++) {
            int u = neighbours[i][j].first, k = neighbours[i][j].second;
            neighb[u].push_back({i, k});
        }
    }
    pos[1] = 1;
    dfs(n);
    for (int i = n; i >= 1; i--) {
        //cout << dp[n][i] << " " << i << endl;
        if (dp[n][i] <= t) {
            cout << i << endl;
            vector <int> ans;
            ans.push_back(n);
            int x = n;
            while (i != 1) {
                x = parent[x][i];
                i--;
                ans.push_back(x);
            }
            for (int i = ans.size() - 1; i >= 0; i--) {
                cout << ans[i] << " ";
            }
            return 0;
        }
    }
}