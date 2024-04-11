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

const double EPS = 1e-9;
const int maxn = 102;
const int S = 102 * 102;

double dp[maxn][S], ndp[maxn][S];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;
    V<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    int bsum = 0;
    rep(i, n) bsum += b[i];

    rep(i, maxn) rep(j, S) dp[i][j] = -1;
    dp[0][0] = 0;

    rep(i, n) {
        rep(j, i + 2) {
            rep(k, S) { ndp[j][k] = dp[j][k]; }
        }
        rep(j, i + 2) {
            rep(k, S) {
                if (dp[j][k] < -EPS) continue;
                chmax(ndp[j + 1][k + b[i]], dp[j][k] + a[i] - b[i]);
            }
        }
        rep(j, i + 2) {
            rep(k, S) { dp[j][k] = ndp[j][k]; }
        }
    }

    for (int i = 1; i <= n; ++i) {
        double ans = -1;

        rep(j, S) if (dp[i][j] > -EPS) {
            double x = j + min((double)(bsum - j) / 2.0, dp[i][j]);
            chmax(ans, x);
        }
        cout << ans << (i == n ? '\n' : ' ');
    }

    return 0;
}