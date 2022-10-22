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

const int maxn = 300010;
const ll INF = TEN(18);

ll dp[maxn][41];

int main() {
    int n;
    scanf("%d", &n);
    V<int> a(n);
    rep(i, n) scanf("%d", &a[i]);

    rep(i, maxn) rep(j, 41) dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i, n) {
        rep(j, 40) {
            if (dp[i][j] == INF) continue;
            // not use
            int u = min(j + a[i] / 1000, 40);
            chmin(dp[i + 1][u], dp[i][j] + a[i]);

            // use bonus
            int dec = min(j, a[i] / 100);
            chmin(dp[i + 1][j - dec], dp[i][j] + a[i] - dec * 100);
        }
    }

    ll ans = INF;
    rep(i, 41) chmin(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}