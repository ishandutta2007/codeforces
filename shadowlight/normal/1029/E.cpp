#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <int> > dp;

vector <vector <int> > gr;

void dfs(int v, int p) {
    int sum0 = (p ? 1 : 0), sum1 = 0, sum2 = 0;
    int dmin = INF;
    for (int u : gr[v]) {
        if (u == p) continue;
        dfs(u, v);
        sum0 += dp[2][u];
        sum1 += dp[1][u];
        sum2 += dp[1][u];
        dmin = min(dmin, dp[0][u] - dp[1][u]);
    }
    sum1 += dmin;
    dp[0][v] = sum0;
    dp[1][v] = min(sum0, sum1);
    dp[2][v] = min({sum0, sum1, sum2});
    //cout << v << " " << dp[0][v] << " " << dp[1][v] << " " << dp[2][v] << "\n";
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    dp.resize(3, vector <int> (n, INF));
    gr.resize(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }
    int res = 0;
    for (int v : gr[0]) {
        dfs(v, 0);
        res += dp[2][v];
    }
    cout << res;
}