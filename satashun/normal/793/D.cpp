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

const int maxn = 85;
const int INF = 1e9;

int d[maxn][maxn];
int dp[maxn][maxn][maxn][2];
bool vis[maxn][maxn][maxn][2];

int solve(int l, int r, bool f, int num) {
    if (vis[l][r][num][f]) {
        return dp[l][r][num][f];
    }
    int& res = dp[l][r][num][f];
    res = INF;
    vis[l][r][num][f] = true;

    if (num == 0) {
        return res = 0;
    }
    if (!f) {
        for (int m = l + 1; m <= r; ++m) {
            if (d[l][m] != INF) {
                chmin(res, d[l][m] + solve(m, r, 0, num - 1));
                chmin(res, d[l][m] + solve(l + 1, m, 1, num - 1));
            }
        }
    } else {
        for (int m = l; m < r; ++m) {
            if (d[r][m] != INF) {
                chmin(res, d[r][m] + solve(l, m, 1, num - 1));
                chmin(res, d[r][m] + solve(m, r - 1, 0, num - 1));
            }
        }
    }
    return res;
}

int main() {
    rep(i, maxn) rep(j, maxn) d[i][j] = INF;
    int n, k, m;
    cin >> n >> k >> m;
    rep(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        chmin(d[u][v], c);
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        chmin(ans, solve(0, i, 1, k - 1));
        chmin(ans, solve(i, n + 1, 0, k - 1));
    }
    if (ans == INF) {
        puts("-1");
    } else {
        cout << ans << endl;
    }

    return 0;
}