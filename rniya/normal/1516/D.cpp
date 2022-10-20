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
 * @brief osa_k
 * @docs docs/math/prime_factor_table.md
 */
vector<int> prime_factor_table(int n) {
    vector<int> res(n + 1, 0);
    for (int i = 2; i <= n; i++)
        if (!res[i]) {
            for (int j = i; j <= n; j += i) {
                if (!res[j]) res[j] = i;
            }
        }
    return res;
}

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_A = 100010, MAX_LOG = 20;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> PFT = prime_factor_table(MAX_A);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> fac(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (a > 1) {
            fac[i].emplace_back(PFT[a]);
            a /= PFT[a];
        }
        sort(ALL(fac[i]));
        fac[i].erase(unique(ALL(fac[i])), fac[i].end());
    }

    vector<int> R(n);
    vector<int> cnt(MAX_A, 0);
    for (int i = 0, j = 0; i < n; i++) {
        if (j == i) {
            for (int& x : fac[i]) cnt[x]++;
            j++;
        }
        while (j < n) {
            bool ok = true;
            for (int& x : fac[j]) {
                if (cnt[x]) {
                    ok = false;
                }
            }
            if (!ok) break;
            for (int& x : fac[j]) cnt[x]++;
            j++;
        }
        R[i] = j;
        for (int& x : fac[i]) cnt[x]--;
    }

    vector<vector<int>> v(MAX_LOG, vector<int>(n + 1, INF));
    for (int i = 0; i < n; i++) v[0][i] = R[i];
    for (int i = 0; i + 1 < MAX_LOG; i++) {
        for (int j = 0; j < n; j++) {
            int x = v[i][j];
            if (x < INF) v[i + 1][j] = v[i][x];
        }
    }

    auto query = [&](int l, int r) {
        int ans = 0, cur = l;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            if (v[i][cur] <= r) {
                ans += 1 << i;
                cur = v[i][cur];
            }
        }
        if (cur != r) ans++;
        return ans;
    };

    for (; q--;) {
        int l, r;
        cin >> l >> r;
        cout << query(--l, r) << '\n';
    }
    return 0;
}