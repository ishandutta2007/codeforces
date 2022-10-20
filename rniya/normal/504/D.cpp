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

vector<bool> binary_conversion(const string& s) {
    using u64 = uint64_t;

    vector<u64> num(s.size() / 9 + 10, 0);
    for (size_t i = 0; i < s.size(); i += 9) {
        const string t = s.substr(i, 9);
        u64 add = 0, mul = 1;
        for (const auto c : t) {
            add = add * 10 + (c - '0');
            mul *= 10;
        }
        for (auto& d : num) {
            d = d * mul + add;
            add = d >> 32;
            d -= add << 32;
        }
    }

    vector<bool> res(num.size() * 32);
    for (size_t i = 0; i < num.size(); i++) {
        for (size_t j = 0; j < 32; j++) {
            res[i * 32 + j] = num[i] >> j & 1;
        }
    }

    while (!res.empty() && !res.back()) res.pop_back();
    return res;
};

const int MAX = 2048;
using u64 = uint64_t;
using BS = bitset<2 * MAX>;

BS calc(const string& s) {
    BS res;
    vector<bool> v = binary_conversion(s);
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) {
            res.set(i, 1);
        }
    }
    return res;
}

vector<BS> bases;
vector<int> idx(MAX, -1);

vector<int> solve(BS b, int x) {
    for (int i = MAX - 1; i >= 0; i--) {
        if (!b[i]) continue;
        if (~idx[i])
            b ^= bases[idx[i]];
        else {
            b.set(MAX + x, 1);
            idx[i] = bases.size();
            bases.emplace_back(b);
            return {};
        }
    }

    vector<int> res;
    for (int i = 0; i < MAX; i++) {
        if (b[MAX + i]) {
            res.emplace_back(i);
        }
    }
    return res;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string S;
        cin >> S;
        vector<int> ans = solve(calc(S), i);
        cout << ans.size();
        for (int x : ans) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}