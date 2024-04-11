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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    BinaryIndexedTree<int> BIT(n);
    for (int i = 0; i < n; i++) BIT.add(i, 1);
    int flag = 0, len = n, L = 0, R = n;
    auto query1 = [&]() {
        int p;
        cin >> p;
        if (p > len - p) flag ^= 1, p = len - p;
        if (!flag) {
            for (int i = 0; i < p; i++) {
                int x = BIT[L + p - 1 - i];
                BIT.add(L + p + i, x);
                BIT.add(L + p - 1 - i, -x);
            }
            L += p;
        } else {
            for (int i = 0; i < p; i++) {
                int x = BIT[R - p + i];
                BIT.add(R - p - 1 - i, x);
                BIT.add(R - p + i, -x);
            }
            R -= p;
        }
        len -= p;
    };
    auto query2 = [&]() {
        int l, r;
        cin >> l >> r;
        if (!flag)
            return BIT.query(L + l, L + r);
        else
            return BIT.query(R - r, R - l);
    };

    for (; q--;) {
        int t;
        cin >> t;
        if (t == 1)
            query1();
        else
            cout << query2() << '\n';
    }
    return 0;
}