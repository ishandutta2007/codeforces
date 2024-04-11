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

int n, k;

int query(const vector<int>& b) {
    assert((int)b.size() == k);
    for (int x : b) assert(0 <= x && x < n);
    cout << '?';
    for (int x : b) cout << ' ' << x + 1;
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void answer(int x) { cout << "! " << x << endl; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;

    vector<vector<int>> G(n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(k, i); j++) {
            if (n - i < k - j) continue;
            int ni = (i - j) + (k - j);
            G[i].emplace_back(ni);
        }
    }

    vector<int> par(n + 1, -2);
    queue<int> que;
    que.emplace(0);
    par[0] = -1;

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int& u : G[v]) {
            if (par[u] > -2) continue;
            par[u] = v;
            que.emplace(u);
        }
    }

    if (par[n] < 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> path;
    for (int cur = n; cur >= 0; cur = par[cur]) path.emplace_back(cur);
    reverse(path.begin(), path.end());

    vector<vector<int>> flag(2), moved(2);
    for (int i = 0; i < n; i++) flag[0].emplace_back(i);

    int XOR = 0;
    for (size_t i = 1; i < path.size(); i++) {
        int cur = path[i - 1], nxt = path[i];
        int one = (cur + k - nxt) / 2;
        vector<int> b;
        for (int _ = 0; _ < k - one; _++) {
            int x = flag[0].back();
            flag[0].pop_back();
            moved[0].emplace_back(x);
            b.emplace_back(x);
        }
        for (int _ = 0; _ < one; _++) {
            int x = flag[1].back();
            flag[1].pop_back();
            moved[1].emplace_back(x);
            b.emplace_back(x);
        }
        XOR ^= query(b);
        for (int j = 0; j < 2; j++) {
            while (!moved[j].empty()) {
                flag[j ^ 1].emplace_back(moved[j].back());
                moved[j].pop_back();
            }
        }
    }

    answer(XOR);
    return 0;
}