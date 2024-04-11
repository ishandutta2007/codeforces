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
template <typename T, typename U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template <typename T, typename U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
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
 * @brief Sparse table
 * @docs docs/datastructure/SparseTable.md
 */
template <typename T> struct SparseTable {
    typedef function<T(T, T)> F;
    vector<vector<T>> dat;
    vector<int> lookup;
    const F f;
    SparseTable(F f) : f(f) {}
    void build(const vector<T>& v) {
        int n = v.size(), h = 1;
        while ((1 << h) <= n) h++;
        dat.assign(h, vector<T>(n));
        lookup.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) lookup[i] = lookup[i >> 1] + 1;
        for (int j = 0; j < n; j++) dat[0][j] = v[j];
        for (int i = 1, mask = 1; i < h; i++, mask <<= 1) {
            for (int j = 0; j < n; j++) {
                dat[i][j] = f(dat[i - 1][j], dat[i - 1][min(j + mask, n - 1)]);
            }
        }
    }
    T query(int a, int b) {
        if (b <= a) return 0;
        int d = lookup[b - a];
        return f(dat[d][a], dat[d][b - (1 << d)]);
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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& x : p) cin >> x, x--;

    vector<vector<int>> left(2, vector<int>(n)), right(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        left[i][0] = 0;
        for (int j = 1; j < n; j++) {
            if (i == 0) {
                if (p[j] > p[j - 1])
                    left[i][j] = left[i][j - 1] + 1;
                else
                    left[i][j] = 0;
            } else {
                if (p[j] < p[j - 1])
                    left[i][j] = left[i][j - 1] + 1;
                else
                    left[i][j] = 0;
            }
        }
        right[i][n - 1] = 0;
        for (int j = n - 2; j >= 0; j--) {
            if (i == 0) {
                if (p[j] > p[j + 1])
                    right[i][j] = right[i][j + 1] + 1;
                else
                    right[i][j] = 0;
            } else {
                if (p[j] < p[j + 1])
                    right[i][j] = right[i][j + 1] + 1;
                else
                    right[i][j] = 0;
            }
        }
    }

    vector<int> other(n);
    for (int i = 0; i < n; i++) other[i] = max(left[1][i], right[1][i]);
    SparseTable<int> ST([](int a, int b) { return max(a, b); });
    ST.build(other);

    auto check = [&](int x) {
        int l = left[0][x], r = right[0][x];
        if (x == 0 || x == n - 1) return 0;
        if (r == 0) return 0;
        if (l == 0) return 0;
        int L = x - l, R = x + r;
        int Max = max(l, r);
        int out_range = max(ST.query(0, L), ST.query(R + 1, n));
        if (out_range >= Max) return 0;
        int diagl = (l & 1 ? l : l - 1), diagr = (r & 1 ? r : r - 1);
        if (diagl >= r) return 0;
        if (diagr >= l) return 0;
        if (l & 1) {
            if (max(left[1][L], right[1][L]) >= r) {
                return 0;
            }
        } else {
            if (max(left[1][L], right[1][L]) >= r && left[1][L] >= l) {
                return 0;
            }
        }
        if (r & 1) {
            if (max(left[1][R], right[1][R]) >= l) {
                return 0;
            }
        } else {
            if (max(left[1][R], right[1][R]) >= l && right[1][R] >= r) {
                return 0;
            }
        }
        return 1;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) ans += check(i);
    cout << ans << '\n';
    return 0;
}