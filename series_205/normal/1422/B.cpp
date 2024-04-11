// #include <atcoder/all>
#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

int n, m;
int a[101][101];

void solve() {
    cin >> n >> m;
    rep(i, n) rep(j, m) cin >> a[i][j];

    ll ans = 0;

    rep(i, n - i) rep(j, m - j) {
        int ii = n - 1 - i, jj = m - 1 - j;
        if(i < ii && j < jj) {
            int ar[]{a[i][j], a[i][jj], a[ii][j], a[ii][jj]};
            sort(ar, ar + 4);
            rep(k, 4) ans += abs(ar[k] - ar[1]);
        } else if(i < ii) {
            ans += abs(a[i][j] - a[ii][j]);
        } else if(j < jj)
            ans += abs(a[i][j] - a[i][jj]);
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}