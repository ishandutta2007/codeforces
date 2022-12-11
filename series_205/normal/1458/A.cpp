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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    rep(i, n) cin >> a[i];
    rep(j, m) cin >> b[j];

    ll g = 0;
    rep(i, n - 1) g = gcd(g, abs(a[i] - a[i + 1]));

    rep(i, m) cout << gcd(g, a[0] + b[i]) << " \n"[i + 1 == m];

    return 0;
}