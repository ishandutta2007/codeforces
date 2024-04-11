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
#include <vector>

struct TopologicalSort {
    std::vector<std::vector<int>> G;

    TopologicalSort(int n) : G(n), n(n), indeg(n, 0) {}

    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v);
        indeg[v]++;
    }

    std::vector<int> build() {
        std::queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                que.emplace(i);
            }
        }
        std::vector<int> order;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            order.emplace_back(v);
            for (int& u : G[v]) {
                if (--indeg[u] == 0) {
                    que.emplace(u);
                }
            }
        }
        if (*std::max_element(indeg.begin(), indeg.end()) != 0) return {};
        return order;
    }

private:
    int n;
    std::vector<int> indeg;
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> u(n - 1), v(n - 1);
    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        G[u[i]].emplace_back(v[i], i);
        G[v[i]].emplace_back(u[i], i);
    }

    bool ok = true;
    vector<int> type(n - 1, -1);
    auto dfs = [&](auto self, int v, int p) -> int {
        if (!ok) return 0;
        int deg = G[v].size();
        vector<int> cnt(2, 0);
        cnt[0] = deg / 2;
        cnt[1] = deg - cnt[0];
        for (auto& e : G[v]) {
            int u = e.first, idx = e.second;
            if (idx == p) continue;
            cnt[self(self, u, idx)]--;
        }
        if (cnt[0] < 0 or cnt[1] < 0) {
            ok = false;
            return 0;
        }
        if (p == -1) return 0;
        return type[p] = (cnt[0] > 0 ? 0 : 1);
    };
    dfs(dfs, 0, -1);

    if (!ok) {
        cout << "NO" << '\n';
        return;
    }

    TopologicalSort TS(n - 1);
    for (int v = 0; v < n; v++) {
        vector<vector<int>> order(2);
        for (auto& e : G[v]) {
            int idx = e.second;
            order[type[idx]].emplace_back(idx);
        }
        vector<int> tmp;
        for (int i = (int(G[v].size()) & 1); !order[i].empty(); i ^= 1) {
            tmp.emplace_back(order[i].back());
            order[i].pop_back();
        }
        for (size_t i = 0; i + 1 < tmp.size(); i++) TS.add_edge(tmp[i], tmp[i + 1]);
    }

    auto res = TS.build();
    assert(!res.empty());
    cout << "YES" << '\n';
    for (int& x : res) cout << u[x] + 1 << ' ' << v[x] + 1 << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t--;) solve();
    return 0;
}