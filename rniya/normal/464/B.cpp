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

const int MAX = 8;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<vector<int>> x(8, vector<int>(3));
    cin >> x;

    vector<vector<int>> cand;
    for (int mask = 0; mask < (1 << (MAX - 1)); mask++) {
        if (__builtin_popcount(mask) != 3) continue;
        vector<int> v;
        for (int i = 0; i < MAX - 1; i++) {
            if (mask >> i & 1) {
                v.emplace_back(i + 1);
            }
        }
        cand.emplace_back(v);
    }

    auto add = [](const vector<int>& a, const vector<int>& b) {
        vector<int> c(3);
        for (int i = 0; i < 3; i++) c[i] = a[i] + b[i];
        return c;
    };
    auto sub = [](const vector<int>& a, const vector<int>& b) {
        vector<int> c(3);
        for (int i = 0; i < 3; i++) c[i] = a[i] - b[i];
        return c;
    };
    auto dot = [](const vector<int>& a, const vector<int>& b) {
        ll res = 0;
        for (int i = 0; i < 3; i++) res += ll(a[i]) * b[i];
        return res;
    };
    auto dist = [&](int a, int b) {
        ll res = 0;
        for (int i = 0; i < 3; i++) {
            res += ll(x[a][i] - x[b][i]) * (x[a][i] - x[b][i]);
        }
        return res;
    };

    auto calc = [&](int i, int j, int k) {
        set<vector<int>> s;
        for (int i = 0; i < MAX; i++) s.emplace(x[i]);
        if (!s.count(add(x[i], sub(x[j], x[0])))) return false;
        if (!s.count(add(x[i], sub(x[k], x[0])))) return false;
        if (!s.count(add(x[k], sub(x[j], x[0])))) return false;
        if (!s.count(add(add(x[i], sub(x[j], x[0])), sub(x[k], x[0])))) return false;
        return true;
    };

    auto check = [&]() {
        for (int i = 0; i < MAX; i++) {
            for (int j = i + 1; j < MAX; j++) {
                if (x[i] == x[j]) {
                    return false;
                }
            }
        }
        for (auto& v : cand) {
            if (dist(0, v[0]) != dist(0, v[1]) || dist(0, v[1]) != dist(0, v[2]) || dist(0, v[2]) != dist(0, v[0]))
                continue;
            bool cube = true;
            for (int i = 0; i < 3; i++) {
                if (dot(sub(x[v[i]], x[0]), sub(x[v[(i + 1) % 3]], x[0])) != 0) {
                    cube = false;
                }
            }
            if (!cube) continue;
            if (calc(v[0], v[1], v[2])) {
                return true;
            }
        }
        return false;
    };

    auto dfs = [&](auto self, int dep) -> void {
        if (dep == MAX) {
            if (check()) {
                cout << "YES" << '\n';
                for (int i = 0; i < MAX; i++) cout << x[i] << '\n';
                exit(0);
            }
            return;
        }
        vector<int> perm(3);
        iota(perm.begin(), perm.end(), 0);
        do {
            vector<int> pre = x[dep], nxt(3);
            for (int i = 0; i < 3; i++) nxt[i] = x[dep][perm[i]];
            x[dep] = nxt;
            self(self, dep + 1);
            x[dep] = pre;
        } while (next_permutation(perm.begin(), perm.end()));
    };
    dfs(dfs, 1);

    cout << "NO" << '\n';
    return 0;
}