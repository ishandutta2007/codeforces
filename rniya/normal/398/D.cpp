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

const int SQRT = 512;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> state(n, 0), deg(n, 0), a(m), b(m), ans(n, 0);
    vector<bool> big(n);
    vector<vector<int>> G(n);  // !big :  big :  big 
    vector<tuple<char, int, int>> query;

    int o;
    cin >> o;
    for (; o--;) {
        int x;
        cin >> x;
        state[--x] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        deg[--a[i]]++;
        deg[--b[i]]++;
    }
    for (int i = 0; i < q; i++) {
        char c;
        int u, v = -1;
        cin >> c >> u;
        --u;
        if (c == 'A' || c == 'D') {
            cin >> v;
            --v;
            if (c == 'A') {
                deg[u]++;
                deg[v]++;
            }
        }
        query.emplace_back(c, u, v);
    }

    for (int i = 0; i < n; i++) big[i] = (deg[i] >= SQRT);

    auto erase = [](vector<int>& v, int x) {
        for (int i = 0; i < (int)v.size(); i++) {
            if (v[i] == x) {
                v.erase(v.begin() + i);
                break;
            }
        }
    };
    auto online = [&](int u) {
        state[u] = 1;
        if (!big[u]) {
            for (int& v : G[u]) {
                ans[v]++;
            }
        }
    };
    auto offline = [&](int u) {
        state[u] = 0;
        if (!big[u]) {
            for (int& v : G[u]) {
                ans[v]--;
            }
        }
    };
    auto add_friend = [&](int u, int v) {  // add u -> v
        if (!big[u] || big[v]) G[u].emplace_back(v);
        ans[u] += (state[v] & (!big[v]));
    };
    auto del_friend = [&](int u, int v) {  // del u -> v
        if (!big[u] || big[v]) erase(G[u], v);
        ans[u] -= (state[v] & (!big[v]));
    };
    auto count_online_friends = [&](int u) {
        int res = ans[u];
        for (int& v : G[u]) res += (state[v] & big[v]);
        return res;
    };

    for (int i = 0; i < m; i++) {
        add_friend(a[i], b[i]);
        add_friend(b[i], a[i]);
    }

    for (int i = 0; i < q; i++) {
        char c;
        int u, v;
        tie(c, u, v) = query[i];
        if (c == 'O')
            online(u);
        else if (c == 'F')
            offline(u);
        else if (c == 'A') {
            add_friend(u, v);
            add_friend(v, u);
        } else if (c == 'D') {
            del_friend(u, v);
            del_friend(v, u);
        } else
            cout << count_online_friends(u) << '\n';
    }
    return 0;
}