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

#include <algorithm>
#include <cassert>
#include <vector>

template <bool directed> struct EulerianTrail {
    std::vector<std::vector<std::pair<int, int>>> G;

    EulerianTrail(int n) : G(n), n(n), m(0), deg(n, 0), used_vertex(n, false) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        edges.emplace_back(u, v);
        used_edge.emplace_back(false);
        G[u].emplace_back(v, m);
        deg[u]++;
        if (directed)
            deg[v]--;
        else {
            G[v].emplace_back(u, m);
            deg[v]++;
        }
        m++;
    }

    std::vector<std::vector<int>> solve() {
        if (directed) {
            if (std::count_if(deg.begin(), deg.end(), [](int x) { return x != 0; })) return {};
        } else {
            if (std::count_if(deg.begin(), deg.end(), [](int x) { return (x & 1) != 0; })) return {};
        }
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (G[i].empty() or used_vertex[i]) continue;
            res.emplace_back(go(i));
        }
        return res;
    }

    std::vector<std::vector<int>> solve_semi() {
        checked_vertex.assign(n, false);
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (checked_vertex[i]) continue;
            int s = -1, t = -1;
            if (!dfs(i, s, t)) return {};
            res.emplace_back(go(s >= 0 ? s : i));
            if (res.back().empty()) res.pop_back();
        }
        return res;
    }

    std::pair<int, int> operator[](int k) const { return edges[k]; }

private:
    int n, m;
    std::vector<int> deg;
    std::vector<std::pair<int, int>> edges;
    std::vector<bool> used_vertex, used_edge, checked_vertex;

    bool dfs(int v, int& s, int& t) {
        if (directed) {
            if (deg[v] < -1 or 1 < deg[v]) return false;
            if (deg[v] == 1) {
                if (s >= 0) return false;
                s = v;
            }
        } else {
            if (deg[v] & 1) {
                if (s == -1)
                    s = v;
                else if (t == -1)
                    t = v;
                else
                    return false;
            }
        }
        for (const auto& e : G[v]) {
            int u = e.first;
            if (checked_vertex[u]) continue;
            if (!dfs(u, s, t)) return false;
        }
        return true;
    }

    std::vector<int> go(int s) {
        std::vector<std::pair<int, int>> st;
        std::vector<int> order;
        st.emplace_back(s, -1);
        while (!st.empty()) {
            int v = st.back().first;
            used_vertex[v] = true;
            if (G[v].empty()) {
                order.emplace_back(st.back().second);
                st.pop_back();
            } else {
                auto e = G[v].back();
                G[v].pop_back();
                if (used_edge[e.second]) continue;
                used_edge[e.second] = true;
                st.emplace_back(e);
            }
        }
        order.pop_back();
        reverse(order.begin(), order.end());
        return order;
    }
};

/**
 * @brief Eulerian Trail
 * @docs docs/graph/EulerianTrail.md
 */

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    vector<int> c;
    for (int i = 0; i < n; ++i) {
        c.emplace_back(a[i]);
        c.emplace_back(b[i]);
    }

    auto calc = [&](int mask) {
        EulerianTrail<false> ET(mask + 1);
        for (int i = 0; i < n; ++i) {
            a[i] &= mask;
            b[i] &= mask;
            c[i << 1 | 0] &= mask;
            c[i << 1 | 1] &= mask;
            ET.add_edge(a[i], b[i]);
        }
        return ET.solve();
    };

    for (int j = 20; j >= 0; --j) {
        vector<vector<int>> res = calc((1 << j) - 1);
        if (res.size() != 1) continue;
        cout << j << '\n';
        auto& v = res[0];
        for (int _ = 0; _ < 2; ++_) {
            vector<int> ans;
            ans.emplace_back(v[0] << 1 | _);
            ans.emplace_back(v[0] << 1 | (_ ^ 1));
            int ok = 1;
            for (int i = 1; i < n; ++i) {
                if (c[v[i] << 1 | 0] == c[ans.back()]) {
                    ans.emplace_back(v[i] << 1 | 0);
                    ans.emplace_back(v[i] << 1 | 1);
                } else if (c[v[i] << 1 | 1] == c[ans.back()]) {
                    ans.emplace_back(v[i] << 1 | 1);
                    ans.emplace_back(v[i] << 1 | 0);
                    continue;
                } else {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            for (int i = 0; i < 2 * n; ++i) cout << ans[i] + 1 << (i + 1 == 2 * n ? '\n' : ' ');
            return 0;
        }
    }
    return 0;
}