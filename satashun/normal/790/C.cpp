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

const int maxn = 80;
const int INF = TEN(9);

int dp[maxn][maxn][maxn][3];

int main() {
    rep(i, maxn) rep(j, maxn) rep(k, maxn) rep(l, 3) dp[i][j][k][l] = INF;

    int n;
    string s;
    cin >> n >> s;
    V<int> vv, vk, vo;

    rep(i, n) {
        if (s[i] == 'V') {
            vv.pb(i);
        } else if (s[i] == 'K') {
            vk.pb(i);
        } else {
            vo.pb(i);
        }
    }

    dp[0][0][0][0] = 0;

    auto f = [&](int pos, int j, int k, const V<int>& v1, const V<int>& v2) {
        int c = 0;
        for (int p = j; p < v1.size(); ++p) {
            if (v1[p] < pos) {
                ++c;
            }
        }
        for (int p = k; p < v2.size(); ++p) {
            if (v2[p] < pos) {
                ++c;
            }
        }
        return c;
    };

    rep(i, vv.size() + 1) {
        rep(j, vk.size() + 1) {
            rep(k, vo.size() + 1) {
                rep(l, 3) {
                    if (dp[i][j][k][l] == INF) continue;
                    if (i < vv.size()) {
                        int nc = dp[i][j][k][l] + f(vv[i], j, k, vk, vo);
                        chmin(dp[i + 1][j][k][0], nc);
                    }
                    if (j < vk.size() && (i + j + k == 0 || l != 0)) {
                        int nc = dp[i][j][k][l] + f(vk[j], i, k, vv, vo);
                        chmin(dp[i][j + 1][k][1], nc);
                    }
                    if (k < vo.size()) {
                        int nc = dp[i][j][k][l] + f(vo[k], i, j, vv, vk);
                        chmin(dp[i][j][k + 1][2], nc);
                    }
                }
            }
        }
    }
    int ans = INF;
    rep(l, 3) { chmin(ans, dp[vv.size()][vk.size()][vo.size()][l]); }
    cout << ans << endl;

    return 0;
}