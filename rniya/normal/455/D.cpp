// #define LOCAL
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

const int SQRT = 400, MAX_N = 100010;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    int sz = (n + SQRT - 1) / SQRT;
    vector<vector<int>> cnt(sz, vector<int>(MAX_N, 0));
    vector<deque<int>> deq(sz);
    for (int k = 0; k < sz; k++) {
        int l = k * SQRT, r = min(n, (k + 1) * SQRT);
        for (int i = l; i < r; i++) {
            cnt[k][a[i]]++;
            deq[k].emplace_back(a[i]);
        }
    }

    auto shift = [&](int l, int r) {
        debug(l, r);
        int suf = deq[(r - 1) / SQRT][(r - 1) % SQRT];
        for (int k = sz - 1; k >= 0; k--) {
            int L = k * SQRT, R = min(n, (k + 1) * SQRT);
            if (R <= l || r <= L) continue;
            if (l <= L && R <= r) {
                cnt[k][deq[k].back()]--;
                deq[k].pop_back();
                if (l == L)
                    deq[k].emplace_front(suf);
                else
                    deq[k].emplace_front(deq[k - 1].back());
                cnt[k][deq[k].front()]++;
            } else {
                for (int i = R - 1; i >= L; i--) {
                    if (i < l || r <= i) continue;
                    cnt[k][deq[k][i - L]]--;
                    if (i != l) {
                        if (i != L)
                            deq[k][i - L] = deq[k][i - L - 1];
                        else
                            deq[k][i - L] = deq[k - 1].back();
                    } else
                        deq[k][i - L] = suf;
                    cnt[k][deq[k][i - L]]++;
                }
            }
        }
    };
    auto query = [&](int l, int r, int x) {
        debug(l, r, x);
        int res = 0;
        for (int k = 0; k < sz; k++) {
            int L = k * SQRT, R = min(n, (k + 1) * SQRT);
            if (R <= l || r <= L) continue;
            if (l <= L && R <= r)
                res += cnt[k][x];
            else {
                for (int i = L; i < R; i++) {
                    if (l <= i && i < r) {
                        res += (deq[k][i - L] == x);
                    }
                }
            }
        }
        return res;
    };

    int ans = 0, q;
    cin >> q;
    for (; q--;) {
        int t, l, r;
        cin >> t >> l >> r;
        l = (l + ans - 1) % n + 1;
        r = (r + ans - 1) % n + 1;
        if (l > r) swap(l, r);
        if (t == 1) {
            shift(--l, r);
        } else {
            int x;
            cin >> x;
            x = (x + ans - 1) % n + 1;
            ans = query(--l, r, x);
            cout << ans << '\n';
        }
        debug(deq[0]);
    }
    return 0;
}