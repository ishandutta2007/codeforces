#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

struct DP {
    int ans;
    int lst;
    DP *prev;
    explicit DP(int ans = INF): ans(ans), lst(-1), prev(nullptr) {}
    void update(DP &dp, int shots) {
        if (dp.ans + shots >= ans) return;
        ans = dp.ans + shots;
        lst = shots;
        prev = &dp;
    }
};

const int X = 17;

void solve() {
    vector<vector<vector<DP>>> dp(X, vector<vector<DP>>(X, vector<DP>(X)));
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> hp(n);
    for (int &x : hp) cin >> x;

    if (n == 3) {
        int ans = max(max(hp[0], hp[2]) / b + 1, hp[1] / a + 1);
        cout << ans << "\n";
        while (ans--) cout << "2 ";
        cout << "\n";
        return;
    }

    for (int i = hp[0] / b + 1; i < X; i++) {
        dp[1][0][i].ans = i;
        dp[1][0][i].lst = i;
    }

    DP *bstDp = new DP();
    for (int cur = 1; cur < n - 2; cur++) {
        for (int n1 = 0; n1 < X; n1++) {
            for (int n2 = 0; n2 < X; n2++) {
                auto &curDp = dp[cur][n1][n2];
                if (curDp.ans == INF) continue;

                for (int x = 0; x < X; x++) {
                    if (n1 * b + n2 * a + x * b > hp[cur]) {
                        dp[cur + 1][n2][x].update(curDp, x);

                        if (cur + 3 == n && x > hp[n - 1] / b && x * a + n2 * b > hp[n - 2]) {
                            bstDp->update(curDp, x);
                        }
                    }
                }
            }
        }
    }

    if (bstDp->ans == INF) {
        cout << "fail\n";
        exit(11);
    }
    cout << bstDp->ans << "\n";
    vector<int> path;
    while (bstDp != nullptr) {
        path.push_back(bstDp->lst);
        bstDp = bstDp->prev;
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++) {
        for (int j = 0; j < path[i]; j++) cout << i + 2 << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 2;
#endif
    while (t--) {
        solve();
    }
}