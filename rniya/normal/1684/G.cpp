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

#include <algorithm>
#include <cassert>
#include <queue>
#include <random>
#include <utility>
#include <vector>

struct BipartiteMatching {
    BipartiteMatching(int U, int V) : U(U), V(V), t(0), solved(false), G(U), L(U, -1), R(V, -1), visited(U, -1) {}

    void add_edge(int u, int v) {
        assert(0 <= u && u < U);
        assert(0 <= v && v < V);
        G[u].emplace_back(v);
    }

    void shuffle() {
        static std::mt19937 mt;
        for (auto& v : G) std::shuffle(v.begin(), v.end(), mt);
    }

    int solve() {
        for (bool updated = true; std::exchange(updated, false); t++) {
            for (int i = 0; i < U; i++) {
                if (L[i] == -1) {
                    updated |= dfs(i);
                }
            }
        }
        solved = true;
        return U - std::count(L.begin(), L.end(), -1);
    }

    std::vector<std::pair<int, int>> max_matching() const {
        assert(solved);
        std::vector<std::pair<int, int>> res;
        for (int i = 0; i < U; i++) {
            if (~L[i]) {
                res.emplace_back(i, L[i]);
            }
        }
        return res;
    }

private:
    int U, V, t;
    bool solved;
    std::vector<std::vector<int>> G;
    std::vector<int> L, R, visited;

    bool dfs(int u) {
        if (std::exchange(visited[u], t) == t) return false;
        for (int& v : G[u]) {
            if (R[v] == -1) {
                L[u] = v, R[v] = u;
                return true;
            }
        }
        for (int& v : G[u]) {
            if (dfs(R[v])) {
                L[u] = v, R[v] = u;
                return true;
            }
        }
        return false;
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int Euclid(int a, int b, vector<int>& t) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    int r = a % b;
    if (r != 0) t.emplace_back(r);
    return Euclid(b, r, t);
}

bool check(const vector<int>& t, const vector<pair<int, int>>& ans) {
    vector<int> nt;
    for (const auto& p : ans) Euclid(p.first, p.second, nt);
    sort(nt.begin(), nt.end());
    return t == nt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (int& x : t) cin >> x;

    sort(t.begin(), t.end());
    vector<int> small, large;
    for (int& x : t) {
        if (1LL * x * 2 >= m) {
            cout << -1 << '\n';
            return 0;
        }
        if (1LL * x * 3 <= m)
            small.emplace_back(x);
        else
            large.emplace_back(x);
    }

    int l = large.size(), r = small.size();
    BipartiteMatching BM(l, r);
    for (int i = 0; i < l; i++) {
        int x = large[i];
        for (int j = 0; j < r; j++) {
            int y = small[j];
            if (2 * x + y > m) continue;
            if (x % y != 0) continue;
            BM.add_edge(i, j);
        }
    }

    if (BM.solve() != l) {
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<int, int>> ans;
    auto res = BM.max_matching();
    vector<bool> used(r, false);
    for (int i = 0; i < l; i++) {
        int idx = res[i].second;
        used[idx] = true;
        ans.emplace_back(large[i] + small[idx], 2 * large[i] + small[idx]);
    }
    for (int i = 0; i < r; i++) {
        if (!used[i]) {
            ans.emplace_back(2 * small[i], 3 * small[i]);
        }
    }

    // assert(check(t, ans));
    cout << ans.size() << '\n';
    for (auto& p : ans) cout << p.first << ' ' << p.second << '\n';
    return 0;
}