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

// template <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }
// template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

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

#include <numeric>
#include <vector>

namespace elementary_math {

template <typename T> std::vector<T> divisor(T n) {
    std::vector<T> res;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) res.emplace_back(n / i);
        }
    }
    return res;
}

template <typename T> std::vector<std::pair<T, int>> prime_factor(T n) {
    std::vector<std::pair<T, int>> res;
    for (T p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            res.emplace_back(p, 0);
            while (n % p == 0) {
                res.back().second++;
                n /= p;
            }
        }
    }
    if (n > 1) res.emplace_back(n, 1);
    return res;
}

std::vector<int> osa_k(int n) {
    std::vector<int> min_factor(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (min_factor[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (!min_factor[j]) {
                min_factor[j] = i;
            }
        }
    }
    return min_factor;
}

std::vector<int> prime_factor(const std::vector<int>& min_factor, int n) {
    std::vector<int> res;
    while (n > 1) {
        res.emplace_back(min_factor[n]);
        n /= min_factor[n];
    }
    return res;
}

long long modpow(long long x, long long n, long long mod) {
    assert(0 <= n && 1 <= mod && mod < (1LL << 31));
    if (mod == 1) return 0;
    x %= mod;
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else
        x = 1, y = 0;
    return d;
}

long long inv_mod(long long a, long long mod) {
    assert(1 <= mod);
    long long x, y;
    if (extgcd(a, mod, x, y) != 1) return -1;
    return (mod + x % mod) % mod;
}

template <typename T> T euler_phi(T n) {
    auto pf = prime_factor(n);
    T res = n;
    for (const auto& p : pf) {
        res /= p.first;
        res *= p.first - 1;
    }
    return res;
}

std::vector<int> euler_phi_table(int n) {
    std::vector<int> res(n + 1, 0);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (res[i] != i) continue;
        for (int j = i; j <= n; j += i) res[j] = res[j] / i * (i - 1);
    }
    return res;
}

// minimum i > 0 s.t. x^i \equiv 1 \pmod{m}
template <typename T> T order(T x, T m) {
    T n = euler_phi(m);
    auto cand = divisor(n);
    sort(cand.begin(), cand.end());
    for (auto& i : cand) {
        if (modpow(x, i, m) == 1) {
            return i;
        }
    }
    return -1;
}

}  // namespace elementary_math

/**
 * @brief elementary math
 * @docs docs/math/elementary_math.md
 */

template <typename T> T gcd(T x_, T y_) {
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

template <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }

/**
 * @brief binary gcd
 * @docs docs/math/binary_gcd.md
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
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    cin >> a >> b;

    int g = p - 1;
    for (int& x : b) g = gcd(g, x);

    auto e = p - 1;
    auto cand = elementary_math::divisor(e);
    sort(cand.begin(), cand.end());
    vector<ll> order;
    for (int i = 0; i < n; i++) {
        for (int& j : cand) {
            if (elementary_math::modpow(a[i], j, p) == 1) {
                // order.emplace_back((ll(p - 1) / j) * g % (p - 1));
                order.emplace_back((ll(p - 1) / j) * g);
                break;
            }
        }
    }

    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());
    int sz = order.size();
    vector<ll> norder;
    for (int i = 0; i < sz; i++) {
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (order[j] == 0) continue;
            if (order[i] % order[j] == 0) {
                ok = false;
                break;
            }
        }
        if (ok) norder.emplace_back(order[i]);
    }
    swap(order, norder);
    sz = order.size();
    assert(sz <= 25);

    ll ans = 0;
    for (int mask = 1; mask < (1 << sz); mask++) {
        ll cur = 1;
        if (order[0] == 0 and (mask & 1)) continue;
        for (int i = 0; i < sz; i++) {
            if (mask >> i & 1) {
                cur = lcm(cur, order[i]);
                assert(0 <= cur and cur < 9 * IINF);
            }
        }
        ll add = lcm(cur, ll(p - 1)) / cur;
        if (popcount(mask) & 1)
            ans += add;
        else
            ans -= add;
    }
    if (order[0] == 0 and order.size() == 1) ans++;

    cout << ans << '\n';
    return 0;
}