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
#define ALL(c) (c).begin(), (c).end()

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

int main() {
    int n;
    cin >> n;
    V<ll> a(n), b(n);
    map<ll, V<ll>> T;

    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) { T[a[i]].pb(b[i]); }
    ll ans = 0;
    V<pair<ll, ll>> cand;
    V<ll> used;
    for (auto& p : T) {
        if (p.se.size() == 1) {
            cand.eb(p.fi, p.se[0]);
        } else {
            for (auto& x : p.se) {
                ans += x;
            }
            used.pb(p.fi);
        }
    }

    if (used.size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (auto& p : cand) {
        bool ok = 0;
        for (ll x : used) {
            if ((x & p.fi) == p.fi) {
                ok = 1;
            }
        }
        if (ok) {
            ans += p.se;
        }
    }
    cout << ans << endl;

    return 0;
}