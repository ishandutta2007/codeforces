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
 * @brief Slope Trick
 * @docs docs/datastructure/SlopeTrick.md
 */
template <typename T> class SlopeTrick {
    const T inf = numeric_limits<T>::max() / 3;
    T min_f;
    priority_queue<T, vector<T>, less<>> L;
    priority_queue<T, vector<T>, greater<>> R;
    T add_l, add_r;

    void push_L(const T& x) { L.emplace(x - add_l); }
    T top_L() const { return !L.empty() ? L.top() + add_l : -inf; }
    T pop_L() {
        T res = top_L();
        if (!L.empty()) L.pop();
        return res;
    }
    void clear_left() {
        while (!L.empty()) L.pop();
    }
    void push_R(const T& x) { R.emplace(x - add_r); }
    T top_R() const { return !R.empty() ? R.top() + add_r : inf; }
    T pop_R() {
        T res = top_R();
        if (!R.empty()) R.pop();
        return res;
    }
    void clear_right() {
        while (!R.empty()) R.pop();
    }
    size_t size() const { return L.size() + R.size(); }

public:
    SlopeTrick() : min_f(0), add_l(0), add_r(0) {}
    tuple<T, T, T> query() const { return make_tuple(top_L(), top_R(), min_f); }
    // f(x) += a
    void add_all(const T& a) { min_f += a; }
    // add _/
    // f(x) += max(x - a, 0)
    void add_x_minus_a(const T& a) {
        min_f += max(top_L() - a, T(0));
        push_L(a);
        push_R(pop_L());
    }
    // add \_
    // f(x) += max(a - x, 0)
    void add_a_minus_x(const T& a) {
        min_f += max(a - top_R(), T(0));
        push_R(a);
        push_L(pop_R());
    }
    // add \/
    // f(x) += abs(x - a)
    void add_abs(const T& a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }

    // \/ -> \_
    // f(x) <- min_{y <= x} f(y)
    void cumulative_min_left() { clear_right(); }
    // \/ -> _/
    // f(x) <- min_{x <= y} f(y)
    void cumulative_min_right() { clear_left(); }

    // f(x) <- min_{x- b <= y <= x - a} f(y)
    void shift(const T& a, const T& b) {
        assert(a <= b);
        add_l += a;
        add_r += b;
    }
    // f(x) <- f(x - a)
    // note after this operation, L and R are empty
    void shift(const T& a) { shift(a, a); }

    T get(const T& x) {
        T res = min_f;
        while (!L.empty()) res += max(pop_L() - x, T(0));
        while (!R.empty()) res += max(x - pop_R(), T(0));
        return res;
    }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, d;
    cin >> n >> m >> d;

    SlopeTrick<ll> ST;
    int pre = 0;
    ll sum = 0;
    for (; m--;) {
        int a, b, t;
        cin >> a >> b >> t;
        ll delta = ll(t - pre) * d;
        ST.shift(-delta, delta);
        ST.add_abs(a);
        sum += b;
        pre = t;
    }

    ll ans = sum - get<2>(ST.query());
    cout << ans << '\n';
    return 0;
}