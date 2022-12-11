#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;
constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

ll a[4];

ll cnt[1000009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    rep(i, 4) cin >> a[i];

    FOR(i, a[0] + a[1], a[1] + a[2] + 1) cnt[i] = cnt[i - 1] + 1;
    FORR(i, 1000008)
    chmin(cnt[i], min({cnt[i + 1] + 1, a[2] - a[1] + 1, a[1] - a[0] + 1}));

    FORR(i, 1000008) cnt[i] += cnt[i + 1];

    // rep(i, 10) { cout << cnt[i] << endl; }

    ll ans = 0;
    FOR(i, a[2], a[3] + 1) ans += cnt[i + 1];

    cout << ans << endl;

    return 0;
}