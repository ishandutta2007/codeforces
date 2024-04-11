#include <bits/stdc++.h>
// #include <atcoder/all>
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
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    rep(i, n) { cin >> x[i] >> y[i]; }

    vector<vector<int>> d(n, vector<int>(n, 1 << 29));
    rep(i, n) {
        rep(j, n) if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k) d[i][j] = 1;
        if(*max_element(ALL(d[i])) == 1) {
            cout << 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}