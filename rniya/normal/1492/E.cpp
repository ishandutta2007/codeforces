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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    auto diff = [](const vector<int>& a, const vector<int>& b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) cnt += (a[i] != b[i]);
        return cnt;
    };
    auto check = [&](const vector<int>& v) {
        for (int i = 0; i < n; i++) {
            if (diff(v, a[i]) > 2) {
                return;
            }
        }
        cout << "Yes" << '\n';
        cout << v << '\n';
        exit(0);
    };

    for (int i = 1; i < n; i++) {
        int x = diff(a[0], a[i]);
        if (x <= 2) continue;
        if (x > 4) {
            cout << "No" << '\n';
            return 0;
        }
        vector<int> pos;
        for (int j = 0; j < m; j++) {
            if (a[0][j] != a[i][j]) {
                pos.emplace_back(j);
            }
        }

        if (x == 4) {
            for (int j = 0; j < 4; j++) {
                for (int k = j + 1; k < 4; k++) {
                    vector<int> v(a[0]);
                    v[pos[j]] = a[i][pos[j]];
                    v[pos[k]] = a[i][pos[k]];
                    check(v);
                }
            }
            cout << "No" << '\n';
            return 0;
        } else {
            // change 2 positions
            for (int j = 0; j < 3; j++) {
                for (int k = j + 1; k < 3; k++) {
                    vector<int> v(a[0]);
                    v[pos[j]] = a[i][pos[j]];
                    v[pos[k]] = a[i][pos[k]];
                    check(v);
                }
            }

            // change 1 position
            for (int j = 0; j < 3; j++) {
                vector<int> v(a[0]);
                v[pos[j]] = a[i][pos[j]];
                check(v);
            }

            // change 1 position and other position is from other array
            auto check2 = [&](vector<int>& v, int x) {
                for (int i = 0; i < n; i++) {
                    int diff = 0;
                    for (int j = 0; j < m; j++) {
                        if (j == x) continue;
                        diff += (v[j] != a[i][j]);
                    }
                    if (diff > 2) return;
                    if (diff == 2) {
                        v[x] = a[i][x];
                        check(v);
                    }
                }
                v[x] = a[0][x];
                check(v);
            };
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    vector<int> v(a[0]);
                    v[pos[j]] = a[i][pos[j]];
                    check2(v, pos[k]);
                }
            }
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';
    cout << a[0] << '\n';
    return 0;
}