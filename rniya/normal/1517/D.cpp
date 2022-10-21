#define LOCAL
#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(), (x).end()

template <typename T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& x : v) is >> x;
    return is;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template <typename T, typename U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template <typename T, typename U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m) {
    os << '{';
    for (auto itr = m.begin(); itr != m.end();) {
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr != m.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const unordered_set<T>& s) {
    os << '{';
    for (auto itr = s.begin(); itr != s.end();) {
        os << *itr;
        if (++itr != s.end()) os << ',';
    }
    os << '}';
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const deque<T>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
    }
    return os;
}

void debug_out() { cerr << '\n'; }
template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {
    cerr << head;
    if (sizeof...(Tail) > 0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...)                                                                   \
    cerr << " ";                                                                     \
    cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n'; \
    cerr << " ";                                                                     \
    debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }
template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

template <class T1, class T2> inline bool chmin(T1& a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2> inline bool chmax(T1& a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#pragma endregion

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_K = 11, MAX_N = 510;
int dp[MAX_K / 2 + 1][MAX_K][MAX_K];
int ndp[MAX_K / 2 + 1][MAX_N][MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, K;
    cin >> n >> m >> K;
    vector<vector<int>> a(n, vector<int>(m - 1));
    vector<vector<int>> b(n - 1, vector<int>(m));
    cin >> a >> b;

    if (K & 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << -1 << (j + 1 == m ? '\n' : ' ');
            }
        }
        return 0;
    }
    K /= 2;

    auto out = [&](int x, int y) { return x < 0 || n <= x || y < 0 || m <= y; };
    auto calc = [&](int x, int y) {
        for (int i = 0; i <= MAX_K / 2; i++) {
            for (int j = 0; j < MAX_K; j++) {
                for (int k = 0; k < MAX_K; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
        dp[0][MAX_K / 2][MAX_K / 2] = 0;
        for (int i = 0; i < MAX_K / 2; i++) {
            for (int j = MAX_K / 2 - i; j <= MAX_K / 2 + i; j++) {
                for (int k = MAX_K / 2 - i; k <= MAX_K / 2 + i; k++) {
                    if (dp[i][j][k] == INF) continue;
                    if (out(x + j - MAX_K / 2, y + k - MAX_K / 2)) continue;
                    for (int l = 0; l < 4; l++) {
                        int nx = j + dx[l], ny = k + dy[l];
                        if (out(x + nx - MAX_K / 2, y + ny - MAX_K / 2)) continue;
                        int cost = 0;
                        // debug(l, x + j - MAX_K / 2, y + k - MAX_K / 2, x + nx - MAX_K / 2, y + ny - MAX_K / 2);
                        if (l == 0) cost = b[x + j - MAX_K / 2][y + k - MAX_K / 2];
                        if (l == 1) cost = a[x + j - MAX_K / 2][y + k - MAX_K / 2];
                        if (l == 2) cost = b[x + nx - MAX_K / 2][y + ny - MAX_K / 2];
                        if (l == 3) cost = a[x + nx - MAX_K / 2][y + ny - MAX_K / 2];
                        chmin(dp[i + 1][nx][ny], dp[i][j][k] + cost);
                    }
                }
            }
        }
    };

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int i = 0; i <= MAX_K / 2; i++) ndp[i][x][y] = INF;
            calc(x, y);
            for (int i = 0; i <= MAX_K / 2; i++) {
                for (int j = 0; j < MAX_K; j++) {
                    for (int k = 0; k < MAX_K; k++) {
                        chmin(ndp[i][x][y], dp[i][j][k]);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(n, vector<int>(m, INF));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            calc(x, y);
            for (int j = 0; j < MAX_K; j++) {
                for (int k = 0; k < MAX_K; k++) {
                    int nx = x + j - MAX_K / 2, ny = y + k - MAX_K / 2;
                    if (out(nx, ny)) continue;
                    chmin(ans[x][y], dp[K / 2][j][k] + ndp[K - K / 2][nx][ny]);
                    // debug(dp[K][j][k], ndp[K][nx][ny]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] * 2 << (j + 1 == m ? '\n' : ' ');
        }
    }
    return 0;
}