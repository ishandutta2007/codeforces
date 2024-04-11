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

#include <array>
#include <cassert>
#include <vector>

template <typename T, int MAX_LOG> struct BinaryTrie {
    struct Node {
        std::array<int, 2> nxt;
        int count;
        Node() : nxt{-1, -1}, count(0) {}
    };

    std::vector<Node> nodes;

    inline int& next(int i, int j) { return nodes[i].nxt[j]; }

    BinaryTrie() { nodes.emplace_back(); }

    void insert(const T& x) {
        int cur = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int f = x >> i & 1;
            int nxt = next(cur, f);
            if (nxt == -1) {
                nxt = nodes.size();
                next(cur, f) = nxt;
                nodes.emplace_back();
            }
            nodes[cur].count++;
            cur = nxt;
        }
        nodes[cur].count++;
    }

    void erase(const T& x) {
        assert(count(x));
        int cur = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int f = x >> i & 1;
            nodes[cur].count--;
            cur = next(cur, f);
        }
        nodes[cur].count--;
    }

    int find(const T& x) {
        int cur = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int f = x >> i & 1;
            cur = next(cur, f);
            if (cur == -1) return -1;
        }
        return cur;
    }

    int count(const T& x) {
        int idx = find(x);
        return idx == -1 ? 0 : nodes[idx].count;
    }

    T min_element(const T& xor_val = 0) {
        int cur = 0;
        T res = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int f = xor_val >> i & 1;
            int l = next(cur, f), r = next(cur, f ^ 1);
            if (l == -1 or nodes[l].count == 0) {
                cur = r;
                res |= T(f ^ 1) << i;
            } else {
                cur = l;
                res |= T(f) << i;
            }
        }
        return res;
    }

    T max_element(const T& xor_val = 0) { return min_element(~xor_val); }

    T kth_element(int k, const T& xor_val = 0) const {
        int cur = 0;
        T res = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int f = xor_val >> i & 1;
            int l = next(cur, f), r = next(cur, f ^ 1);
            if (l == -1 or nodes[l].count <= k) {
                cur = r;
                k -= (l == -1 ? 0 : nodes[l].count);
                res |= T(f ^ 1) << i;
            } else {
                cur = l;
                res |= T(f) << i;
            }
        }
        return res;
    }

    int count_less(const T& x, const T& xor_val = 0) const {
        int cur = 0;
        int res = 0;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            int f = xor_val >> i & 1, g = x >> i & 1;
            int l = next(cur, f), r = next(cur, f ^ 1);
            if (f != g and l != -1) res += nodes[l].count;
            cur = next(cur, g);
            if (cur == -1) break;
        }
        return res;
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_LOG = 17;

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> a(r - l + 1);
    cin >> a;

    BinaryTrie<int, MAX_LOG> BT;
    for (auto& x : a) BT.insert(x);
    for (auto& x : a) {
        int cand = (x ^ l);
        int Min = BT.min_element(cand) ^ cand, Max = BT.max_element(cand) ^ cand;
        if (Min == l and Max == r) {
            cout << cand << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t--;) solve();
    return 0;
}