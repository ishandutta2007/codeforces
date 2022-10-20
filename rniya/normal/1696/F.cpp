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
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "" : " ");
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
    for (size_t i = 0; i < v.size(); i++) {
        os << v[i] << (i + 1 == v.size() ? "" : " ");
    }
    return os;
}
template <typename T, size_t N> ostream& operator<<(ostream& os, const array<T, N>& v) {
    for (size_t i = 0; i < N; i++) {
        os << v[i] << (i + 1 == N ? "" : " ");
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
#define debug(...) void(0)
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
long long MSK(int n) { return (1LL << n) - 1; }

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

template <typename T> void mkuni(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
template <typename T> int lwb(const vector<T>& v, const T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
#pragma endregion

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

bool check(int n, const vector<vector<string>>& S, const vector<pair<int, int>>& ans) {
    if ((int)ans.size() != n - 1) return false;
    vector<vector<int>> G(n);
    for (const auto& p : ans) {
        int u = p.first, v = p.second;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    auto dfs = [&](auto self, int v, int p, int d, vector<int>& dist) -> void {
        dist[v] = d;
        for (int& u : G[v]) {
            if (u == p) continue;
            self(self, u, v, d + 1, dist);
        }
    };
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) dfs(dfs, i, -1, 0, dp[i]);
    for (int j = 0; j < n; j++) {
        if (dp[0][j] == INF) {
            return false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; i + j < n; j++) {
            for (int k = 0; k < n; k++) {
                int x = (dp[i][k] == dp[i + j][k]);
                if (x != S[i][j - 1][k] - '0') return false;
            }
        }
    }

    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<string>> S(n, vector<string>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 1; i + j < n; j++) {
            cin >> S[i][j - 1];
        }
    }

    vector<pair<int, int>> ans;
    if (n == 2) {
        ans.emplace_back(0, 1);
        if (!check(n, S, ans)) {
            cout << "No" << '\n';
            return;
        }
        cout << "Yes" << '\n';
        for (auto& p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
        return;
    }

    auto query = [&](int i, int j, int k) -> bool {  // d(i, k) = d(j, k)
        if (i == j) return true;
        if (i > j) swap(i, j);
        return S[i][j - i - 1][k] == '1';
    };

    // 
    vector<vector<vector<int>>> dep(n);
    vector<vector<int>> idx(n, vector<int>(n));
    {
        for (int i = 0; i < n; i++) {
            vector<bool> seen(n, false);
            for (int j = 0; j < n; j++) {
                if (seen[j]) continue;
                vector<int> tmp = {j};
                for (int k = j + 1; k < n; k++) {
                    if (query(j, k, i)) {
                        if (seen[k]) {
                            cout << "No" << '\n';
                            return;
                        }
                        seen[k] = true;
                        tmp.emplace_back(k);
                    }
                }
                for (int& k : tmp) idx[i][k] = dep[i].size();
                dep[i].emplace_back(tmp);
            }
        }
    }

    int leaf = -1;
    {
        // 
        int Max = -1;
        for (int i = 0; i < n; i++) {
            if (chmax(Max, (int)dep[i].size())) {
                leaf = i;
            }
        }
    }

    int adj = -1;
    {
        // 
        vector<int> cand;
        for (auto& tmp : dep[leaf]) {
            if (tmp.size() != 1) continue;
            int v = tmp[0];
            if (v == leaf) continue;
            auto& x = dep[v][idx[v][leaf]];
            if (x.size() == 1) continue;
            vector<int> y;
            for (int& val : x) {
                if (val == leaf) continue;
                y.emplace_back(val);
            }
            auto& z = dep[leaf][idx[leaf][y[0]]];
            if (y == z) {
                cand.emplace_back(v);
            }
        }

        for (int& v : cand) {
            if (dep[v].size() != dep[leaf].size() - 1) continue;
            bool ok = true;
            for (int i = 0; i < (int)dep[v].size(); i++) {
                if (i == idx[v][leaf]) continue;
                int x = dep[v][i][0];
                auto& tmp = dep[leaf][idx[leaf][x]];
                if (tmp != dep[v][i]) ok = false;
            }
            if (!ok) continue;
            if (adj != -1) {
                cout << "No" << '\n';
                return;
            }
            adj = v;
        }
        if (adj == -1) {
            cout << "No" << '\n';
            return;
        }
    }

    vector<bool> seen(n, false);
    bool ok = true;
    auto dfs = [&](auto self, int v, int p) -> void {
        if (!ok) return;
        if (seen[v]) {
            ok = false;
            return;
        }
        seen[v] = true;
        ans.emplace_back(v, p);
        if ((int)ans.size() > n - 1) return;
        auto& nxt = dep[v][idx[v][p]];
        for (int& u : nxt) {
            if (u == p) continue;
            self(self, u, v);
        }
    };
    dfs(dfs, adj, leaf);

    if (!ok) {
        cout << "No" << '\n';
        return;
    }
    if (!check(n, S, ans)) {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    for (auto& p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t--;) solve();
    return 0;
}