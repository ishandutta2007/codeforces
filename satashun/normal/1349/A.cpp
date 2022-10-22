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

const int MX = 200010;

V<int> pw[MX];

int main() {
    int n;
    cin >> n;
    V<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                int k = 0;
                while (a[i] % j == 0) {
                    a[i] /= j;
                    k++;
                }
                pw[j].pb(k);
            }
        }
        if (a[i] != 1) {
            pw[a[i]].pb(1);
        }
    }

    ll ans = 1;
    for (int i = 1; i < MX; ++i) {
        if (pw[i].size() < n - 1) continue;
        if (pw[i].size() != n) {
            pw[i].pb(0);
        }
        sort(ALL(pw[i]));
        int k = pw[i][1];
        rep(t, k) { ans *= i; }
    }
    cout << ans << endl;

    return 0;
}