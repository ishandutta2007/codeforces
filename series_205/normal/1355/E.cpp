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

ll n, a, r, m;
V<ll> v, le, ri;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> a >> r >> m;
    chmin(m, a + r);

    ll sum = 0;
    rep(i, n) {
        ll x;
        cin >> x;
        le.push_back(x);
        sum += x;
    }
    sort(ALL(le));
    v = ri = le;

    ll res = inf;

    rep(i, n - 1) le[i + 1] += le[i];
    FORR(i, n - 1) ri[i] += ri[i + 1];

    rep(i, n) {
        ll ca = v[i] * (i + 1) - le[i];
        ll cr = ri[i] - v[i] * (n - i);
        ll mn = min(ca, cr);
        ca -= mn;
        cr -= mn;
        chmin(res, mn * m + ca * a + cr * r);
    }

    rep(i, 2) {
        ll mid = sum / n + i;
        ll ca = 0, cr = 0, mn;
        for(ll x : v) {
            if(x < mid) ca += mid - x;
            if(x > mid) cr += x - mid;
        }
        mn = min(ca, cr);
        ca -= mn;
        cr -= mn;
        chmin(res, mn * m + ca * a + cr * r);
    }

    cout << res << endl;

    return 0;
}