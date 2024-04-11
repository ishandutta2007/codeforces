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

template <int i, typename T> void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(ostream& os, const T& t) {
    if (i) os << ',';
    os << get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '{';
    print_tuple<0, tuple<Args...>, Args...>(os, t);
    return os << '}';
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

int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    cin >> a;

    auto calc = [&](int sx, int sy, int d1, int d2) -> vector<vector<int>> {
        vector<vector<int>> dp(n, vector<int>(m, -INF));
        queue<pair<int, int>> que;
        dp[sx][sy] = 0;
        que.emplace(sx, sy);
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        while (!que.empty()) {
            auto p = que.front();
            que.pop();
            int x = p.first, y = p.second;
            if (seen[x][y]) continue;
            seen[x][y] = true;
            dp[x][y] += a[x][y];
            for (int i : {d1, d2}) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                chmax(dp[nx][ny], dp[x][y]);
                que.emplace(nx, ny);
            }
        }
        return dp;
    };

    vector<vector<vector<int>>> path;
    path.emplace_back(calc(0, 0, 0, 1));
    path.emplace_back(calc(n - 1, m - 1, 2, 3));
    path.emplace_back(calc(n - 1, 0, 1, 2));
    path.emplace_back(calc(0, m - 1, 0, 3));

    auto calc2 = [&](int x, int y) {  // 2  (x,y) 
        int res = 0;
        for (int i : {0, 1}) {
            for (int j : {1, 2}) {
                if (i == j) continue;
                if (i == 0 && j == 2) continue;
                int sum = 0;
                bool ok = true;
                for (int p : {i, j}) {
                    int px = x - dx[p], py = y - dy[p];
                    if (px < 0 || n <= px || py < 0 || m <= py) {
                        ok = false;
                        break;
                    }
                    sum += path[p == i ? 0 : 2][px][py];
                }
                if (!ok) continue;
                for (int k : {0, 1}) {
                    for (int l : {1, 2}) {
                        if (k == l) continue;
                        if (k == 0 && l == 2) continue;
                        if (i == 0 && l == 2) continue;
                        if (k == 0 && j == 2) continue;
                        int sum2 = 0;
                        bool ok2 = true;
                        for (int p : {k, l}) {
                            int nx = x + dx[p], ny = y + dy[p];
                            if (nx < 0 || n <= nx || ny < 0 || m <= ny) {
                                ok2 = false;
                                break;
                            }
                            sum2 += path[p == k ? 1 : 3][nx][ny];
                        }
                        if (!ok2) continue;
                        chmax(res, sum + sum2);
                    }
                }
            }
        }
        return res;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            chmax(ans, calc2(i, j));
        }
    }

    cout << ans << '\n';
    return 0;
}