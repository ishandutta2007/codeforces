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
 * @brief (32bit)
 * @docs docs/util/RandomNumberGenerator.md
 */
struct RandomNumberGenerator {
    mt19937 mt;
    RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    uint32_t operator()(uint32_t a, uint32_t b) {
        uniform_int_distribution<uint32_t> dist(a, b - 1);
        return dist(mt);
    }
    uint32_t operator()(uint32_t b) { return (*this)(0, b); }
};

template <typename T> T binary_gcd(T x_, T y_) {
    unsigned long long x = x_ < 0 ? -x_ : x_, y = y_ < 0 ? -y_ : y_;
    if (!x or !y) return x + y;
    int n = __builtin_ctzll(x), m = __builtin_ctzll(y);
    x >>= n, y >>= m;
    while (x != y) {
        if (x > y)
            x = (x - y) >> __builtin_ctzll(x - y);
        else
            y = (y - x) >> __builtin_ctzll(y - x);
    }
    return x << (n > m ? m : n);
}

/**
 * @brief binary $\gcd$
 * @docs docs/math/binary_gcd.md
 */

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_ITER = 25;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;

    map<ll, ll> solved;
    auto calc = [&](ll x) -> ll {  // x  1  Ghd 
        if (solved.count(x)) return solved[x];
        map<ll, int> mp;
        for (auto& val : a) mp[binary_gcd(x, val)]++;
        vector<ll> div;
        vector<int> cnt;
        for (auto p : mp) {
            div.emplace_back(p.first);
            cnt.emplace_back(p.second);
        }
        reverse(div.begin(), div.end());
        reverse(cnt.begin(), cnt.end());
        int sz = div.size();
        for (int i = 0; i < sz; i++) {
            int sum = 0;
            for (int j = 0; j <= i; j++) {
                if (div[j] % div[i] == 0) {
                    sum += cnt[j];
                }
            }
            if (sum >= (n + 1) / 2) return solved[x] = div[i];
        }
        return 1;
    };

    ll ans = 0;
    if (n < MAX_ITER) {
        for (auto& x : a) ans = max(ans, calc(x));
    } else {
        RandomNumberGenerator rng;
        for (int _ = 0; _ < MAX_ITER; _++) {
            int x = rng(0, n);
            ans = max(ans, calc(a[x]));
        }
    }

    cout << ans << '\n';
    return 0;
}