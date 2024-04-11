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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, n;
    cin >> r >> n;

    V<int> dp(n + 1, -1);
    V<pair<pii, int>> vec(n + 1);
    vec[0] = mp(mp(1, 1), 0);

    rep(i, n) {
        int x, y, t;
        cin >> t >> x >> y;
        vec[i + 1] = mp(mp(x, y), t);
    }
    dp[0] = 0;
    int mx = -1;
    int now = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = max(0, i - r * 2); j < i; ++j) {
            int d = abs(vec[j].fi.fi - vec[i].fi.fi) +
                    abs(vec[j].fi.se - vec[i].fi.se);
            if (d + vec[j].se <= vec[i].se && dp[j] != -1) {
                chmax(dp[i], dp[j] + 1);
            }
        }
        while (now < i && vec[now].se < vec[i].se - r * 2) {
            chmax(mx, dp[now]);
            now++;
        }
        if (mx != -1) {
            chmax(dp[i], mx + 1);
        }
    }

    cout << *max_element(ALL(dp)) << endl;

    return 0;
}