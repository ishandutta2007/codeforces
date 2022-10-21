#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e5 + 50, K = 500;
const ll INF = (ll)1e18;

int n;
int a[N];
ll psum[N];
ll dp[N][K];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 1, n + 1) cin >> a[i], psum[i] = psum[i - 1] + a[i];
        rep(i, 0, n + 2) fill(dp[i], dp[i] + K, -INF);
        dp[n + 1][0] = INF;
        int res = 0;
        for (int i = n; i >= 1; i--) {
            for (int k = 0; i + k <= n + 1 && k < K; k++) {
                dp[i][k] = dp[i + 1][k];
                if(k && psum[i + k - 1] - psum[i - 1] < dp[i + k][k - 1]) {
                    dp[i][k] = max(dp[i][k], psum[i + k - 1] - psum[i - 1]);
                }
                if(dp[i][k] > 0) res = max(res, k);
            }
        }
        cout << res << '\n';
    }
}