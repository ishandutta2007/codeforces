#include <bits/stdc++.h>

#define int int64_t

using namespace std;

vector<int> scores;
vector<vector<int>> sons;
vector<vector<int>> dp;

void dfs(int v, int minx, int maxx) {
    int s = sons[v].size();
    if (s == 0) {
        dp[v][0] = minx * scores[v];
        dp[v][1] = maxx * scores[v];
        return;
    }
    int miny = minx / s, maxy = (maxx + s - 1) / s;
    vector<int> dif;
    int def = 0;
    for (int to: sons[v]) {
        dfs(to, miny, maxy);
        def += dp[to][0];
        dif.push_back(dp[to][1] - dp[to][0]);
    }
    sort(dif.rbegin(), dif.rend());
    dp[v][0] = scores[v] * minx + def;
    for (int i = 0; i < minx % s; i++) {
        dp[v][0] += dif[i];
    }
    dp[v][1] = scores[v] * maxx + def;
    for (int i = 0; i < (maxx % s != 0 ? maxx % s : s); i++) {
        dp[v][1] += dif[i];
    }
}

int32_t main() {
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, k;
        cin >> n >> k;
        sons.clear();
        sons.resize(n);
        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            p--;
            sons[p].push_back(i);
        }
        scores.clear();
        scores.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> scores[i];
        }
        dp.clear();
        dp.resize(n, vector<int>(2));
        dfs(0, k, k);
        cout << dp[0][0] << '\n';
    }
}