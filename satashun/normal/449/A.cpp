#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

V<pair<ll, ll>> enum_quotient(ll N) {
    V<pair<ll, ll>> res;
    ll l = 1;
    while (l <= N) {
        ll r = N / (N / l) + 1;
        //[l, r)
        res.emplace_back(l, r);
        l = r;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    if (k > n - 1 + m - 1) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    if (k < m - 1) chmax(ans, n * (m / (k + 1)));
    if (k < n - 1) chmax(ans, m * (n / (k + 1)));

    auto vec = enum_quotient(n);

    for (auto rng : vec) {
        ll a = rng.fi, b = rng.se;
        ll x = min({b - 1, k + 1});
        ll y = k + 2 - x;
        if (y <= m && y > 0) {
            chmax(ans, (n / x) * (m / y));
        }
    }
    cout << ans << endl;

    return 0;
}