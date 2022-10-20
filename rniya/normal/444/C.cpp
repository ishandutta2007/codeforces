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

const int SQRT = 300;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    int sz = (n + SQRT - 1) / SQRT;
    vector<ll> color(n),      // 
        color_block(sz, -1),  // 
        sum(n, 0),            // 
        sum_block(sz, 0),     // 
        sum_lazy(sz, 0);      // 
    iota(color.begin(), color.end(), 1);
    vector<bool> same(sz, false);

    auto update = [&](int l, int r, int x) {
        for (int k = 0; k < sz; k++) {
            int L = k * SQRT, R = min(n, (k + 1) * SQRT);
            if (R <= l || r <= L) continue;
            if (l <= L && R <= r) {
                if (same[k]) {
                    sum_block[k] += abs(x - color_block[k]) * (R - L);
                    sum_lazy[k] += abs(x - color_block[k]);
                    color_block[k] = x;
                } else {
                    for (int i = L; i < R; i++) {
                        sum[i] += sum_lazy[k];
                        sum[i] += abs(x - color[i]);
                        sum_block[k] += abs(x - color[i]);
                    }
                    sum_lazy[k] = 0;
                    color_block[k] = x;
                    same[k] = true;
                }
                continue;
            }
            for (int i = L; i < R; i++) {
                sum[i] += sum_lazy[k];
                if (same[k]) color[i] = color_block[k];
                if (l <= i && i < r) {
                    sum[i] += abs(x - color[i]);
                    sum_block[k] += abs(x - color[i]);
                    color[i] = x;
                }
            }
            sum_lazy[k] = 0;
            same[k] = false;
        }
    };
    auto query = [&](int l, int r) {
        ll res = 0;
        for (int k = 0; k < sz; k++) {
            int L = k * SQRT, R = min(n, (k + 1) * SQRT);
            if (R <= l || r <= L) continue;
            if (l <= L && R <= r) {
                res += sum_block[k];
                continue;
            }
            for (int i = max(l, L); i < min(r, R); i++) res += sum[i] + sum_lazy[k];
        }
        return res;
    };

    for (; m--;) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update(--l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(--l, r) << '\n';
        }
        // debug(color);
        // debug(sum);
    }
    return 0;
}