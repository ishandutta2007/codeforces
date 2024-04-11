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

#include <cassert>
#include <queue>

template <typename T, bool isMin = true> struct ConvexHullTrick {
    bool empty() const { return lines.empty(); }

    void add(T a, T b) {
        if (!isMin) a *= -1, b *= -1;
        std::pair<T, T> l(a, b);
        if (empty()) {
            lines.emplace_back(a, b);
            return;
        }
        if (lines.front().first <= a) {
            if (lines.front().first == a) {
                if (lines.front().second <= b) return;
                lines.pop_back();
            }
            while (lines.size() >= 2 && check(l, lines.front(), lines[1])) lines.pop_front();
            lines.emplace_front(l);
        } else if (a <= lines.back().first) {
            if (lines.back().first == a) {
                if (lines.back().second <= b) return;
                lines.pop_back();
            }
            while (lines.size() >= 2 && check(lines[lines.size() - 2], lines.back(), l)) lines.pop_back();
            lines.emplace_back(l);
        } else
            assert(false);
    }

    T query(T x) {
        assert(!called_query_monotonic_inc && !called_query_monotonic_dec);
        assert(!empty());
        called_query = true;
        int lb = -1, ub = lines.size() - 1;
        while (ub - lb > 1) {
            int mid = (ub + lb) >> 1;
            (f(lines[mid], x) >= f(lines[mid + 1], x) ? lb : ub) = mid;
        }
        T res = f(lines[ub], x);
        return isMin ? res : -res;
    }

    T query_monotone_inc(T x) {
        assert(!called_query && !called_query_monotonic_dec);
        assert(!empty());
        if (!called_query_monotonic_inc)
            called_query_monotonic_inc = true;
        else
            assert(prev_query <= x);
        prev_query = x;
        while (lines.size() >= 2 && f(lines.front(), x) >= f(lines[1], x)) lines.pop_front();
        T res = f(lines.front(), x);
        return isMin ? res : -res;
    }

    T query_monotone_dec(T x) {
        assert(!called_query && !called_query_monotonic_inc);
        assert(!empty());
        if (!called_query_monotonic_dec)
            called_query_monotonic_dec = true;
        else
            assert(x <= prev_query);
        prev_query = x;
        while (lines.size() >= 2 && f(lines.back(), x) >= f(lines[lines.size() - 2], x)) lines.pop_back();
        T res = f(lines.back(), x);
        return isMin ? res : -res;
    }

private:
    std::deque<std::pair<T, T>> lines;  // slope decreases as index increases
    bool called_query = false, called_query_monotonic_inc = false, called_query_monotonic_dec = false;
    T prev_query;

    using D = long double;

    // check if b is unnecessary
    inline bool check(const std::pair<T, T>& a, const std::pair<T, T>& b, const std::pair<T, T>& c) {
        // return (b.first - a.first) * (c.second - b.second) >= (c.first - b.first) * (b.second - a.second);
        // note that slopes are distinct and decrease
        return D(c.second - b.second) / (c.first - b.first) >= D(b.second - a.second) / (b.first - a.first);
    }

    inline T f(const std::pair<T, T>& l, T x) { return l.first * x + l.second; }
};

/**
 * @brief Convex Hull Trick (Add-Monotonic Slope Optimization)
 * @docs docs/datastructure/ConvexHullTrick.md
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
    int n, m;
    cin >> n >> m;
    n++, m++;
    vector<string> a(n);
    for (auto& s : a) cin >> s;

    vector<ConvexHullTrick<double>> CHT_row(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += ll(i + 1) * (i + 1) + ll(j) * j;
            if (a[i][j] == '1') {
                double x = i + 1, y = j;
                CHT_row[i].add(-2 * y / x, x + y * y / x);
            }
        }
    }

    for (int j = 0; j < m; j++) {
        ConvexHullTrick<int> CHT_col;
        for (int i = 0; i < n; i++) {
            if (CHT_row[i].empty()) continue;
            double X = CHT_row[i].query_monotone_inc(j);
            int x = i + 1;
            CHT_col.add(-2 * x, round(X * x));
        }
        for (int i = 0; i < n; i++) ans += CHT_col.query_monotone_inc(i + 1);
    }

    cout << ans << '\n';
    return 0;
}