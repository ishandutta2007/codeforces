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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    auto Rotate = [&](const vector<vector<int>>& v) {
        int h = v.size(), w = v[0].size();
        vector<vector<int>> res(w, vector<int>(h));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                res[w - 1 - j][i] = v[i][j];
            }
        }
        return res;
    };
    auto Calc = [&](const vector<vector<int>>& v) {
        int h = v.size(), w = v[0].size();
        vector<vector<int>> res(h, vector<int>(w));
        for (int i = 0; i < h; i++) res[i][w - 1] = v[i][w - 1];
        for (int j = w - 2; j >= 0; j--) {
            for (int i = 0; i < h; i++) {
                res[i][j] = (v[i][j] ? res[i][j + 1] + 1 : 0);
            }
        }
        return res;
    };
    vector<vector<vector<int>>> A, B;
    A.emplace_back(a);
    for (int _ = 0; _ < 3; _++) A.emplace_back(Rotate(A.back()));
    for (int _ = 0; _ < 4; _++) B.emplace_back(Calc(A[_]));

    auto rotate = [&](int x, int y, int w) -> pair<int, int> { return {w - 1 - y, x}; };
    auto query1 = [&](int x, int y) {
        for (int _ = 0; _ < 4; _++) {
            A[_][x][y] ^= 1;
            B[_][x][y] = A[_][x][y];
            for (int j = y - 1; j >= 0; j--) B[_][x][j] = (A[_][x][j] ? B[_][x][j + 1] + 1 : 0);

            auto nxt = rotate(x, y, m);
            x = nxt.first, y = nxt.second;
            swap(n, m);
        }
    };
    auto query2 = [&](int x, int y) {
        int res = 0;
        for (int _ = 0; _ < 4; _++) {
            vector<int> v;
            for (int i = 0; i < n; i++) v.emplace_back(B[_][i][y]);

            stack<int> st;
            vector<int> L(n), R(n);
            for (int i = 0; i < n; i++) {
                while (!st.empty() && v[st.top()] >= v[i]) st.pop();
                L[i] = (st.empty() ? -1 : st.top());
                st.emplace(i);
            }
            while (!st.empty()) st.pop();
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && v[st.top()] >= v[i]) st.pop();
                R[i] = (st.empty() ? n : st.top());
                st.emplace(i);
            }

            for (int i = 0; i < n; i++) {
                if (L[i] < x && x < R[i]) {
                    chmax(res, v[i] * (R[i] - L[i] - 1));
                }
            }

            auto nxt = rotate(x, y, m);
            x = nxt.first, y = nxt.second;
            swap(n, m);
        }
        return res;
    };

    for (; q--;) {
        int op, x, y;
        cin >> op >> x >> y;
        x--, y--;
        if (op == 1)
            query1(x, y);
        else
            cout << query2(x, y) << '\n';
    }
    return 0;
}