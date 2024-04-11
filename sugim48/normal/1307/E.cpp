#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> s(N);
    rep(i, N) cin >> s[i], s[i]--;
    vector<vector<int>> v(N);
    rep(i, N) v[s[i]].pb(i);
    vector<vector<i_i>> lrss(N);
    vector<int> a(N + 1, -1);
    while (M--) {
        int f, h; cin >> f >> h;
        f--;
        int n = v[f].size();
        if (h > n) continue;
        int l = v[f][h - 1];
        int r = v[f][n - h];
        lrss[f].pb(i_i(l, r));
        a[l] = f;
    }
    int ma = -1;
    ll ans = 0;
    rep(m, N + 1) if (m == N || a[m] != -1) {
        int cnt = 0;
        ll prod = 1;
        rep(f, N) {
            vector<i_i>& lrs = lrss[f];
            if (lrs.empty()) continue;
            int dp[4] = {f != a[m], f == a[m], 0, 0};
            for (i_i lr: lrs) {
                int l, r; tie(l, r) = lr;
                if (l == m) continue;
                int pp[4] = {dp[0], dp[1], dp[2], dp[3]};
                if (m != N && l < m) {
                    dp[1] += pp[0];
                    if (dp[1] >= MOD) dp[1] -= MOD;
                    dp[3] += pp[2];
                    if (dp[3] >= MOD) dp[3] -= MOD;
                }
                if (m == N || r > m) {
                    dp[2] += pp[0];
                    if (dp[2] >= MOD) dp[2] -= MOD;
                    dp[3] += pp[1];
                    if (dp[3] >= MOD) dp[3] -= MOD;
                }
            }
            if (dp[3]) {
                cnt += 2;
                prod = prod * dp[3] % MOD;
            } else if (dp[1] + dp[2]) {
                cnt += 1;
                prod = prod * (dp[1] + dp[2]) % MOD;
            } else {
                prod = prod * dp[0] % MOD;
            }
        }
        if (cnt > ma) {
            ma = cnt;
            ans = 0;
        }
        if (cnt == ma) ans = (ans + prod) % MOD;
    }
    cout << ma << ' ' << ans << endl;
}