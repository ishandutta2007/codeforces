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

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_LOG = 25;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    int n = q + 1;
    vector<int> a(n), c(n);
    cin >> a[0] >> c[0];

    vector<int> dep(n);
    vector<vector<int>> par(MAX_LOG, vector<int>(n, -1));
    dep[0] = 0;
    auto add = [&](int v, int p) {
        dep[v] = dep[p] + 1;
        par[0][v] = p;
        for (int i = 0; i + 1 < MAX_LOG; i++) {
            int nxt = par[i][v];
            if (~nxt) par[i + 1][v] = par[i][nxt];
        }
    };
    auto ancestor = [&](int v, int d) {
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            if (d >> i & 1) {
                v = par[i][v];
            }
        }
        return v;
    };
    auto query = [&](int v, int w) -> pair<ll, ll> {
        int lb = 0, ub = dep[v] + 1;
        while (ub - lb > 1) {
            int mid = (ub + lb) >> 1;
            int p = ancestor(v, mid);
            (a[p] > 0 ? lb : ub) = mid;
        }
        int to = ancestor(v, lb);
        if (a[to] == 0) return {0, 0};
        ll W = 0, C = 0;
        for (int h = lb; h >= 0; h--) {
            int p = ancestor(v, h);
            if (W + a[p] > w) {
                C += ll(w - W) * c[p];
                a[p] -= w - W;
                W = w;
                return {W, C};
            } else {
                W += a[p];
                C += ll(a[p]) * c[p];
                a[p] = 0;
            }
        }
        return {W, C};
    };

    for (int i = 1; i <= q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p >> a[i] >> c[i];
            add(i, p);
        } else {
            int v, w;
            cin >> v >> w;
            auto ans = query(v, w);
            cout << ans.first << ' ' << ans.second << endl;
        }
    }
    return 0;
}