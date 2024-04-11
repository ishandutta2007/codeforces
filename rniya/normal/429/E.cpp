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

/**
 * @brief compress
 */
template <typename T> map<T, int> compress(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    map<T, int> res;
    for (int i = 0; i < (int)v.size(); i++) res[v[i]] = i;
    return res;
}

/**
 * @brief 
 * @docs docs/graph/EulerianTrail.md
 */
template <bool directed> class EulerianTrail {
    void dfs(int v, int& s, int& t, int& check) {
        visited[v] = 1;
        if (directed) {
            if (abs(deg[v]) > 1)
                check = 0;
            else if (deg[v] == 1) {
                if (~s)
                    check = 0;
                else
                    s = v;
            }
        } else {
            if (deg[v] & 1) {
                if (s < 0)
                    s = v;
                else if (t < 0)
                    t = v;
                else
                    check = 0;
            }
        }
        for (int u : BG[v]) {
            if (visited[u]) continue;
            dfs(u, s, t, check);
        }
    }
    vector<int> go(int s) {
        stack<pair<int, int>> st;
        vector<int> ord;
        st.emplace(s, -1);
        while (!st.empty()) {
            int v = st.top().first;
            visited[v] = 1;
            if (G[v].empty()) {
                ord.emplace_back(st.top().second);
                st.pop();
            } else {
                auto e = G[v].back();
                G[v].pop_back();
                if (used[e.second]) continue;
                used[e.second] = 1;
                st.emplace(e);
            }
        }
        ord.pop_back();
        reverse(ord.begin(), ord.end());
        return ord;
    }

public:
    vector<vector<pair<int, int>>> G;
    vector<vector<int>> BG;
    vector<pair<int, int>> es;
    vector<int> used, visited, deg;
    EulerianTrail(int n) : G(n), BG(n), visited(n, 0), deg(n, 0) {}
    void add_edge(int u, int v) {
        int m = es.size();
        es.emplace_back(u, v);
        used.emplace_back(0);
        BG[u].emplace_back(v);
        BG[v].emplace_back(u);
        G[u].emplace_back(v, m);
        deg[u]++;
        if (directed)
            --deg[v];
        else
            G[v].emplace_back(u, m), deg[v]++;
    }
    pair<vector<int>, vector<vector<int>>> build() {
        for (int i = 0; i < (int)G.size(); i++) {
            if (directed && deg[i] != 0) return {};
            if (!directed && (deg[i] & 1)) return {};
        }
        vector<vector<int>> res;
        vector<int> s;
        for (int i = 0; i < (int)G.size(); i++) {
            if (G[i].empty() || visited[i]) continue;
            s.emplace_back(i);
            res.emplace_back(go(i));
        }
        return {s, res};
    }
    vector<vector<int>> build_semi() {
        vector<vector<int>> res;
        for (int i = 0; i < (int)G.size(); i++) {
            if (visited[i]) continue;
            int s = -1, t = -1, check = 1;
            dfs(i, s, t, check);
            if (!check) return {};
            res.emplace_back(go(~s ? s : i));
            if (res.back().empty()) res.pop_back();
        }
        return res;
    }
    pair<int, int> operator[](int i) { return es[i]; }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int check(int sz, const vector<int>& l, const vector<int>& r, const vector<int>& ans) {
    vector<int> imos(sz, 0);
    for (int i = 0; i < (int)ans.size(); i++) {
        if (ans[i]) {
            imos[l[i]]++;
            imos[r[i]]--;
        } else {
            imos[l[i]]--;
            imos[r[i]]++;
        }
    }
    for (int i = 0; i + 1 < sz; i++) imos[i + 1] += imos[i];

    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        if (abs(imos[i]) > 1) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i], r[i]++;

    vector<int> xs;
    for (int& x : l) xs.emplace_back(x);
    for (int& x : r) xs.emplace_back(x);
    map<int, int> mp = compress(xs);
    int sz = mp.size();

    vector<int> deg(sz, 0);
    EulerianTrail<false> ET(sz);
    for (int i = 0; i < n; i++) {
        l[i] = mp[l[i]];
        r[i] = mp[r[i]];
        deg[l[i]]++;
        deg[r[i]]++;
        ET.add_edge(l[i], r[i]);
    }
    vector<int> odd;
    for (int i = 0; i < sz; i++) {
        if (deg[i] & 1) {
            odd.emplace_back(i);
        }
    }
    assert(!((int)odd.size() & 1));
    for (int i = 0; i < (int)odd.size(); i += 2) {
        l.emplace_back(odd[i]);
        r.emplace_back(odd[i + 1]);
        ET.add_edge(odd[i], odd[i + 1]);
    }

    auto p = ET.build();
    vector<int> s = p.first;
    vector<vector<int>> res = p.second;
    vector<int> ans(l.size(), -1);

    auto calc = [&](const vector<int>& es, int cur) {
        assert(es.size() > 1);
        for (auto& e : es) {
            int nxt = l[e] + r[e] - cur;
            assert(ans[e] < 0);
            ans[e] = (cur < nxt);
            cur = nxt;
        }
    };
    for (int i = 0; i < (int)res.size(); i++) calc(res[i], s[i]);

    for (int i = 0; i < n; i++) cout << ans[i] << (i + 1 == n ? '\n' : ' ');
    return 0;
}