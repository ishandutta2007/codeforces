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
const int N = (int)1e5 + 50, K = 512, INF = (int)1e9;

int n, a[N];
int dp[N][K], good[K];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];

    rep(i, 0, n + 1) rep(j, 0, K) dp[i][j] = INF;
    rep(i, 1, n + 1) {
        rep(k, 0, K) {
            if(dp[i - 1][k ^ a[i]] < a[i]) {
                dp[i][k] = min(dp[i][k], a[i]);
            }
        }
        dp[i][a[i]] = min(dp[i][a[i]], a[i]);
        rep(k, 0, K) dp[i][k] = min(dp[i - 1][k], dp[i][k]);
        rep(k, 0, K) good[k] |= dp[i][k] < INF;
    }

    good[0] = 1;
    int cnt = 0;
    rep(i, 0, K) cnt += good[i];
    cout << cnt << '\n';
    rep(i, 0, K) if(good[i]) cout << i << " ";
    cout << endl;
}