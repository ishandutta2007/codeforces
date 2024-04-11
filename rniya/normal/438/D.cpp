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

const int SQRT = 256;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;

    int sz = (n + SQRT - 1) / SQRT;
    vector<ll> block_sum(sz, 0);
    vector<set<pair<int, int>>> block_num(sz);
    for (int i = 0; i < n; i++) {
        block_sum[i / SQRT] += a[i];
        block_num[i / SQRT].emplace(a[i], i);
    }

    auto query1 = [&](int l, int r) {
        ll res = 0;
        for (int k = 0; k < sz; k++) {
            int L = k * SQRT, R = (k + 1) * SQRT;
            if (r <= L || R <= l) continue;
            if (l <= L && R <= r)
                res += block_sum[k];
            else {
                for (int i = max(l, L); i < min(r, R); i++) {
                    res += a[i];
                }
            }
        }
        return res;
    };
    auto query2 = [&](int l, int r, int x) {
        for (int k = 0; k < sz; k++) {
            int L = k * SQRT, R = (k + 1) * SQRT;
            if (r <= L || R <= l) continue;
            if (l <= L && R <= r) {
                auto& s = block_num[k];
                vector<pair<int, int>> add;
                for (auto itr = s.lower_bound({x, -1}); itr != s.end(); itr = s.erase(itr)) {
                    int idx = (*itr).second;
                    assert(a[idx] >= x);
                    block_sum[k] -= a[idx];
                    a[idx] %= x;
                    add.emplace_back(a[idx], idx);
                    block_sum[k] += a[idx];
                }
                for (auto& p : add) s.emplace(p);
            } else {
                for (int i = max(l, L); i < min(r, R); i++) {
                    if (a[i] < x) continue;
                    block_num[k].erase({a[i], i});
                    block_sum[k] -= a[i];
                    a[i] %= x;
                    block_num[k].emplace(a[i], i);
                    block_sum[k] += a[i];
                }
            }
        }
    };
    auto query3 = [&](int k, int x) {
        int s = k / SQRT;
        block_num[s].erase({a[k], k});
        block_sum[s] -= a[k];
        a[k] = x;
        block_num[s].emplace(a[k], k);
        block_sum[s] += a[k];
    };

    for (; m--;) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            cout << query1(--l, r) << '\n';
        } else if (t == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            query2(--l, r, x);
        } else {
            int k, x;
            cin >> k >> x;
            query3(--k, x);
        }
    }
    return 0;
}