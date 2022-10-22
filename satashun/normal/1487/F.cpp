//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

const int INF = TEN(9);
const int B = 3000;
const int L = 50;

int dp[60][B * 2][L * 2];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    rep(i, 60) {
        rep(j, B * 2) {
            rep(k, L * 2) { dp[i][j][k] = INF; }
        }
    }

    string s;
    cin >> s;
    int n = s.size();
    debug(n);
    rep(i, 2) { dp[0][B + i][L + i] = (n + 1) * i; }

    rep(i, n) {
        rep(j, B * 2) {
            rep(k, L * 2) {
                if (dp[i][j][k] == INF) continue;
                // debug(i, j - B, k, dp[i][j][k]);
                int x = (s[i] - '0') - ((j - B) + 10 * (k - L));
                // debug(x);
                for (int u = -10; u <= 10; ++u) {
                    int nx = u - x;
                    if (nx + L >= 0 && nx < L) {
                        chmin(dp[i + 1][j + u][nx + L],
                              dp[i][j][k] + abs(u) * (n - i));
                    }
                }
            }
        }
    }
    int ans = INF;
    rep(j, B * 2) chmin(ans, dp[n][j][L]);
    cout << ans << endl;

    return 0;
}