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

#include <algorithm>
#include <cassert>
#include <vector>

struct UnionFind {
    UnionFind(int n) : n(n), num(n), data(n, -1) {}

    int find(int x) {
        assert(0 <= x && x < n);
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    bool merge(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        if ((x = find(x)) == (y = find(y))) return false;
        if (-data[x] < -data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        num--;
        return true;
    }

    bool same(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return find(x) == find(y);
    }

    int size(int x) {
        assert(0 <= x && x < n);
        return -data[find(x)];
    }

    int count() const { return num; }

    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> res(n);
        for (int i = 0; i < n; i++) res[find(i)].emplace_back(i);
        res.erase(std::remove_if(res.begin(), res.end(), [&](const std::vector<int>& v) { return v.empty(); }));
        return res;
    }

    int operator[](int x) { return find(x); }

private:
    int n, num;
    // root node : -1 * component size
    // otherwise : parent
    std::vector<int> data;
};

/**
 * @brief Union Find (Disjoint Set Union)
 * @docs docs/datastructure/UnionFind.md
 */

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n), timer(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> timer[i];

    UnionFind UF(n);
    map<int, vector<pair<int, int>>> mx, my;
    for (int i = 0; i < n; i++) {
        mx[x[i]].emplace_back(y[i], i);
        my[y[i]].emplace_back(x[i], i);
    }
    for (auto p : mx) {
        auto& v = p.second;
        sort(ALL(v));
        for (size_t i = 0; i + 1 < v.size(); i++) {
            if (v[i + 1].first - v[i].first <= k) {
                UF.merge(v[i].second, v[i + 1].second);
            }
        }
    }
    for (auto p : my) {
        auto& v = p.second;
        sort(ALL(v));
        for (size_t i = 0; i + 1 < v.size(); i++) {
            if (v[i + 1].first - v[i].first <= k) {
                UF.merge(v[i].second, v[i + 1].second);
            }
        }
    }
    map<int, int> limit;
    for (int i = 0; i < n; i++) {
        if (limit.count(UF[i]))
            limit[UF[i]] = min(limit[UF[i]], timer[i]);
        else
            limit[UF[i]] = timer[i];
    }
    vector<int> ts;
    for (auto p : limit) ts.emplace_back(p.second);

    auto check = [&](int time) {
        int cnt = 0;
        for (int& t : ts) {
            if (t <= time) continue;
            cnt++;
        }
        return cnt <= time + 1;
    };

    int lb = -1, ub = INF;
    while (ub - lb > 1) {
        int mid = (ub + lb) >> 1;
        (check(mid) ? ub : lb) = mid;
    }

    cout << ub << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (; t--;) solve();
    return 0;
}