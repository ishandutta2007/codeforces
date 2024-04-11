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

const int SQRT = 400;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<string> S(n);
    for (auto& s : S) cin >> s;

    int sz = (n + SQRT - 1) / SQRT;
    while ((int)S.size() < sz * SQRT) {
        string up(m, '^');
        S.emplace_back(up);
    }

    vector<vector<pair<int, int>>> dp(sz, vector<pair<int, int>>(m));
    auto dfs = [&](auto self, int x, int y, int z, int px, int py) -> pair<int, int> {
        if (S[x][y] == '^') {
            if (x - 1 < z * SQRT) return {x - 1, y};
            return self(self, x - 1, y, z, x, y);
        } else if (S[x][y] == '>') {
            if (y + 1 == m) return {x, y + 1};
            if (x == px && y + 1 == py) return {-2, -2};
            return self(self, x, y + 1, z, x, y);
        } else {
            if (y - 1 == -1) return {x, y - 1};
            if (x == px && y - 1 == py) return {-2, -2};
            return self(self, x, y - 1, z, x, y);
        }
    };
    auto update = [&](int z) {
        int x = (z + 1) * SQRT - 1;
        for (int y = 0; y < m; y++) {
            auto p = dfs(dfs, x, y, z, -1, -1);
            dp[z][y] = p;
        }
    };
    auto query1 = [&](int x, int y) -> pair<int, int> {
        for (int i = sz - 1; i >= 0; i--) {
            if (x < i * SQRT || (i + 1) * SQRT <= x) continue;
            if (x == (i + 1) * SQRT - 1) {
                auto p = dp[i][y];
                x = p.first;
                y = p.second;
            } else {
                auto p = dfs(dfs, x, y, i, -1, -1);
                x = p.first;
                y = p.second;
            }
            if (x < 0 || n <= x || y < 0 || m <= y) break;
        }
        return {x, y};
    };
    auto query2 = [&](int x, int y, char c) {
        S[x][y] = c;
        update(x / SQRT);
    };

    for (int i = 0; i < sz; i++) update(i);
    for (; q--;) {
        char t;
        int x, y;
        cin >> t >> x >> y;
        if (t == 'A') {
            auto ans = query1(--x, --y);
            cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
        } else {
            char c;
            cin >> c;
            query2(--x, --y, c);
        }
    }
    return 0;
}