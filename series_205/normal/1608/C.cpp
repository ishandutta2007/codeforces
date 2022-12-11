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
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << ' ' << p.second;
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for(T &x : v) is >> x;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for(size_t i = 0; i < v.size(); i++) os << (i ? " " : "") << v[i];
    return os;
}
struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;
/*-------------------------------------------*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    cin >> a >> b;

    vector<int> p(n);
    iota(ALL(p), 0);
    sort(ALL(p), [&](int i, int j) { return a[i] < a[j]; });
    vector<int> q(n);
    iota(ALL(q), 0);
    sort(ALL(q), [&](int i, int j) { return b[i] < b[j]; });

    rep(i, n) a[p[i]] = i;
    rep(i, n) b[q[i]] = i;

    vector<int> _a(n), _b(n);
    rep(i, n) {
        _a[i] = b[p[i]];
        _b[i] = a[q[i]];
    }
    FORR(i, n - 1) {
        chmin(_a[i], _a[i + 1]);
        chmin(_b[i], _b[i + 1]);
    }

    int mna = n - 1, mnb = n - 1;
    while(true) {
        if(!chmin(mna, _b[mnb]) && !chmin(mnb, _a[mna])) break;
    }

    vector<int> ans(n);
    FOR(i, mna, n) ans[p[i]] = 1;
    FOR(i, mnb, n) ans[q[i]] = 1;

    rep(i, n) cout << ans[i];
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}