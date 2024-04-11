#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353, N = 505;
const ll INF = (ll)1e18;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
ll dp[N][N];
int a[N], b[N];

void umax(ll &to, ll val) {
    to = max(to, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 1, n + 1) cin >> a[i] >> b[i];
    int sum = 0;
    for(int i = 0; i <= n; i++) fill(dp[i], dp[i] + N, -INF);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        int nxtsum = (sum + a[i] + b[i]) % k;
        for(int arem = 0; arem < k; arem++) {
            int brem = (sum - arem + k) % k;
            for(int j = max(1, k - b[i]); j <= min(a[i], k - 1); j++) {
                umax(dp[i][(arem + (a[i] - j)) % k], dp[i - 1][arem] + 1 + (arem + (a[i] - j)) / k + (brem + (b[i] - (k - j))) / k);
            }
            umax(dp[i][(arem + a[i]) % k], dp[i - 1][arem] + (arem + a[i]) / k + (brem + b[i]) / k);
        }
        sum = nxtsum;
    }
    ll res = -1;
    for(int arem = 0; arem < k; arem++) umax(res, dp[n][arem]);
    cout << res << '\n';
}