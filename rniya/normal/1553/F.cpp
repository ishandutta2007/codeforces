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
 * @brief Binary Indexed Tree
 * @docs docs/datastructure/BinaryIndexedTree.md
 */
template <typename T> class BinaryIndexedTree {
    T sum(int i) {
        T res = T();
        for (; i > 0; i -= (i & -i)) res += dat[i];
        return res;
    }

public:
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n_) : n(n_ + 1), dat(n + 1, 0) {}
    void add(int i, const T& x) {
        for (++i; i <= n; i += (i & -i)) dat[i] += x;
    }
    T query(int l, int r) { return sum(r) - sum(l); }
    int lower_bound(T x) const {
        if (x <= 0) return 0;
        int pos = 0, k = 1;
        while (k < n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (pos + k <= n && dat[pos + k] < x) {
                x -= dat[pos + k];
                pos += k;
            }
        }
        return pos;
    }
    int upper_bound(T x) const { return lower_bound(x + 1); }
    T operator[](int i) { return query(i, i + 1); }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_A = 300010;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    BinaryIndexedTree<ll> BIT_sum(MAX_A);
    BinaryIndexedTree<int> BIT_cnt(MAX_A);
    vector<bool> cnt(MAX_A, false);
    ll ans = 0;

    auto calc1 = [&](int x) {  // \sum_{y \in Y} y % x
        ll res = 0;
        for (int k = 0; k * x < MAX_A; k++) {
            int l = k * x, r = min(MAX_A, l + x);
            ll sum = BIT_sum.query(l, r);
            int cnt = BIT_cnt.query(l, r);
            res += sum - ll(l) * cnt;
        }
        return res;
    };
    auto calc2 = [&](int x) {                          // \sum_{y \in Y} x % y
        ll res = ll(x) * BIT_cnt.query(x + 1, MAX_A);  // y > x
        int r = x;
        for (int k = 2; k * k <= x; k++) {
            int l = x / k + 1;
            if (l >= r) break;
            ll sum = BIT_sum.query(l, r);
            int cnt = BIT_cnt.query(l, r);
            res += ll(x) * cnt - sum * (k - 1);
            // assert(l * (k - 1) <= x);
            // assert((r - 1) * (k - 1) <= x);
            // assert(r * (k - 1) >= x);
            // assert(l * k > x);
            // if (x == a.back() && k < 30) {
            //     debug(l, r, sum, cnt, ll(x) * cnt - sum * (k - 1));
            // }
            r = l;
        }
        for (int i = 1; i < r; i++) {
            if (cnt[i]) {
                res += x % i;
            }
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        ans += calc1(a[i]);
        ans += calc2(a[i]);
        cout << ans << (i + 1 == n ? '\n' : ' ');

        BIT_sum.add(a[i], a[i]);
        BIT_cnt.add(a[i], 1);
        cnt[a[i]] = true;
    }
    return 0;
}