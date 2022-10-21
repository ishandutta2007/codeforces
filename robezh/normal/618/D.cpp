#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, INF = (int)1e9;

int n, x, y;
vector<int> G[N];
int dp[3][N];

int dif(int i, int j, int v) {
    return dp[i][v] - dp[j][v];
}

void dfs(int v, int p) {
    int sum2 = 0;
    int mx1_fir = -1, mx1_sec = -1;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        dfs(nxt, v);
        sum2 += dp[2][nxt];
        if(mx1_fir == -1 || dif(1, 2, nxt) < dif(1, 2, mx1_fir)) mx1_sec = mx1_fir, mx1_fir = nxt;
        else if(mx1_sec == -1 || dif(1, 2, nxt) < dif(1, 2, mx1_sec)) mx1_sec = nxt;
    }
    if(mx1_fir == -1) {
        dp[0][v] = INF;
        dp[1][v] = 1;
        dp[2][v] = 1;
        return ;
    }
    dp[0][v] = sum2 + dif(1, 2, mx1_fir) + (mx1_sec == -1 ? 0 : dif(1, 2, mx1_sec) - 1);
    dp[1][v] = min(1 + sum2, sum2 + dif(1, 2, mx1_fir));
    dp[2][v] = min(dp[0][v], dp[1][v]);
//    cout << "dp for " << v + 1 << ": " << dp[0][v] << ", " << dp[1][v] << ", " << dp[2][v] << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x >> y;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll res;
    if(x <= y) {
        dfs(0, -1);
//        cout << dp[2][0] << endl;
        int cnt = dp[2][0];
        res = 1LL * (cnt - 1) * y + 1LL * (n - cnt) * x;
    }
    else {
        bool flag = false;
        for(int i = 0; i < n; i++) if(G[i].size() == n-1) flag = true;
        res = 1LL * (n - 1) * y;
        if(flag) res += (x - y);
    }
    cout << res << endl;

}