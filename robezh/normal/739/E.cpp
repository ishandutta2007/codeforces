#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<int, int> P;
const int N = 2005;
const ll INF = (ll)1e18;

int n, a, b;
int p0[N], p1[N], p01[N];
pll dp[N][N];

pll solve(int c) {
    rep(i, 0, n + 1) rep(j, 0, a + 1) dp[i][j] = {-INF, 0};
    dp[0][0] = {0, 0};
    rep(i, 1, n + 1) {
        rep(j, 0, a + 1) {
            dp[i][j] = max(dp[i - 1][j], {dp[i - 1][j].first + p1[i] - c, dp[i - 1][j].second - 1});
            if(j) dp[i][j] = max(dp[i][j], {dp[i - 1][j - 1].first + p0[i], dp[i - 1][j - 1].second});
            if(j) dp[i][j] = max(dp[i][j], {dp[i - 1][j - 1].first + p0[i] + p1[i] - p01[i] - c, dp[i - 1][j - 1].second - 1});
        }
    }
    return {dp[n][a].first, -dp[n][a].second};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> a >> b;
    rep(i, 1, n + 1) {
        double x; cin >> x;
        p0[i] = (int)floor(x * 1000 + 0.5);
    }
    rep(i, 1, n + 1) {
        double x; cin >> x;
        p1[i] = (int)floor(x * 1000 + 0.5);
    }
    rep(i, 1, n + 1) {
        p01[i] = p0[i] * p1[i];
        p0[i] *= 1000;
        p1[i] *= 1000;
    }
    int l = -(int)1e6 - 50, r = (int)1e6 + 50, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(solve(mid).second <= b) r = mid;
        else l = mid;
    }
//    assert(r < (int)1e6 + 5);
    pll p = solve(r);
//    assert(1LL * b * r <= (ll)1e6 * 2000 && b * r >= 0);
//    cout << p.first << " " << p.second << endl;
    cout << fixed << setprecision(10) << (double)(p.first + b * r) / 1e6 << "\n";


}