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
 * @brief modint
 * @docs docs/modulo/modint.md
 */
template <uint32_t mod> class modint {
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

public:
    u32 v;
    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}
    constexpr u32& value() noexcept { return v; }
    constexpr const u32& value() const noexcept { return v; }
    constexpr modint operator+(const modint& rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(const modint& rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(const modint& rhs) const noexcept { return modint(*this) *= rhs; }
    constexpr modint operator/(const modint& rhs) const noexcept { return modint(*this) /= rhs; }
    constexpr modint& operator+=(const modint& rhs) noexcept {
        v += rhs.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    constexpr modint& operator-=(const modint& rhs) noexcept {
        if (v < rhs.v) v += mod;
        v -= rhs.v;
        return *this;
    }
    constexpr modint& operator*=(const modint& rhs) noexcept {
        v = (u64)v * rhs.v % mod;
        return *this;
    }
    constexpr modint& operator/=(const modint& rhs) noexcept { return *this *= rhs.pow(mod - 2); }
    constexpr modint pow(u64 exp) const noexcept {
        modint self(*this), res(1);
        while (exp > 0) {
            if (exp & 1) res *= self;
            self *= self;
            exp >>= 1;
        }
        return res;
    }
    constexpr modint& operator++() noexcept {
        if (++v == mod) v = 0;
        return *this;
    }
    constexpr modint& operator--() noexcept {
        if (v == 0) v = mod;
        return --v, *this;
    }
    constexpr modint operator++(int) noexcept {
        modint t = *this;
        return ++*this, t;
    }
    constexpr modint operator--(int) noexcept {
        modint t = *this;
        return --*this, t;
    }
    constexpr modint operator-() const noexcept { return modint(mod - v); }
    template <class T> friend constexpr modint operator+(T x, modint y) noexcept { return modint(x) + y; }
    template <class T> friend constexpr modint operator-(T x, modint y) noexcept { return modint(x) - y; }
    template <class T> friend constexpr modint operator*(T x, modint y) noexcept { return modint(x) * y; }
    template <class T> friend constexpr modint operator/(T x, modint y) noexcept { return modint(x) / y; }
    constexpr bool operator==(const modint& rhs) const noexcept { return v == rhs.v; }
    constexpr bool operator!=(const modint& rhs) const noexcept { return v != rhs.v; }
    constexpr bool operator!() const noexcept { return !v; }
    friend istream& operator>>(istream& s, modint& rhs) noexcept {
        i64 v;
        rhs = modint{(s >> v, v)};
        return s;
    }
    friend ostream& operator<<(ostream& s, const modint& rhs) noexcept { return s << rhs.v; }
};

/**
 * @brief Trie
 * @docs docs/string/Trie.md
 */
template <int char_size> struct Trie {
    struct TrieNode {
        char c;
        int dep;
        vector<int> nxt, idxs;
        TrieNode(char c, int dep) : c(c), dep(dep), nxt(char_size, -1) {}
    };
    vector<TrieNode> Nodes;
    function<int(char)> ctoi;
    Trie(function<int(char)> ctoi) : ctoi(ctoi) { Nodes.emplace_back('$', 0); }
    inline int& next(int node, int c) { return Nodes[node].nxt[c]; }
    inline int& next(int node, char c) { return next(node, ctoi(c)); }
    void add(const string& s, int x = 0) {
        int node = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int k = ctoi(s[i]);
            if (next(node, k) < 0) {
                next(node, k) = Nodes.size();
                Nodes.emplace_back(s[i], i + 1);
            }
            node = next(node, k);
        }
        Nodes[node].idxs.emplace_back(x);
    }
    int find(const string& s) {
        int node = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int k = ctoi(s[i]);
            if (next(node, k) < 0) return -1;
            node = next(node, k);
        }
        return node;
    }
    template <typename F> void query(const string& s, const F& f, int l) {
        int node = 0;
        for (int i = l; i < (int)s.size(); i++) {
            node = next(node, s[i]);
            if (node < 0) return;
            for (auto& idx : Nodes[node].idxs) f(idx);
        }
    }
    int size() { return Nodes.size(); };
    vector<int> idxs(int node) { return Nodes[node].idxs; }
};

/**
 * @brief Aho Corasick
 * @docs docs/string/AhoCorasick.md
 */
template <int char_size> struct AhoCorasick : Trie<char_size + 1> {
    using Trie<char_size + 1>::Trie;
    using Trie<char_size + 1>::next;
    using Trie<char_size + 1>::ctoi;
    const int FAIL = char_size;
    vector<int> cnt;
    void build(bool heavy = true) {
        auto& Nodes = this->Nodes;
        cnt.resize(Nodes.size());
        for (int i = 0; i < (int)Nodes.size(); i++) {
            cnt[i] = Nodes[i].idxs.size();
        }
        queue<int> que;
        for (int i = 0; i <= char_size; i++) {
            if (~next(0, i)) {
                next(next(0, i), FAIL) = 0;
                que.emplace(next(0, i));
            } else
                next(0, i) = 0;
        }
        while (!que.empty()) {
            auto& node = Nodes[que.front()];
            int fail = node.nxt[FAIL];
            cnt[que.front()] += cnt[fail];
            que.pop();
            for (int i = 0; i < char_size; i++) {
                if (~node.nxt[i]) {
                    next(node.nxt[i], FAIL) = next(fail, i);
                    if (heavy) {
                        auto& u = Nodes[node.nxt[i]].idxs;
                        auto& v = Nodes[next(fail, i)].idxs;
                        vector<int> w;
                        set_union(u.begin(), u.end(), v.begin(), v.end(), back_inserter(w));
                        u = w;
                    }
                    que.emplace(node.nxt[i]);
                } else
                    node.nxt[i] = Nodes[fail].nxt[i];
            }
        }
    }
    map<int, int> match(const string& s, int now = 0) {
        auto& Nodes = this->Nodes;
        map<int, int> res;
        for (auto c : s) {
            now = next(now, ctoi(c));
            for (auto& id : Nodes[now].idxs) res[id]++;
        }
        return res;
    }
    int move(const char& c, int now) {
        while (next(now, ctoi(c)) < 0) now = next(now, FAIL);
        return next(now, ctoi(c));
    }
    pair<long long, int> move(const string& s, int now = 0) {
        long long res = 0;
        for (auto& c : s) {
            int nxt = move(c, now);
            res += cnt[nxt];
            now = nxt;
        }
        return {res, now};
    }
    int count(int node) { return cnt[node]; }
};

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX = 205, MAX_K = 505;
using mint = modint<MOD>;
mint dp[MAX][MAX_K][2], ndp[MAX][MAX_K][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, K;
    cin >> n >> m >> K;
    auto read = []() {
        int len;
        cin >> len;
        vector<int> res;
        for (; len--;) {
            int x;
            cin >> x;
            res.emplace_back(x);
        }
        return res;
    };
    vector<int> L = read(), R = read();

    // L--
    reverse(L.begin(), L.end());
    for (int& x : L) {
        if (x == 0)
            x = m - 1;
        else {
            x--;
            break;
        }
    }
    while (!L.empty() && L.back() == 0) L.pop_back();
    reverse(L.begin(), L.end());

    AhoCorasick<20> AHO([](char c) { return c - '0'; });
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        vector<int> s = read();
        string t = "";
        for (int& x : s) t += char('0' + x);
        cin >> v[i];
        AHO.add(t, i);
    }

    AHO.build();
    int sz = AHO.size();
    vector<int> sum(sz, 0);
    for (int i = 0; i < sz; i++) {
        for (int& idx : AHO.Nodes[i].idxs) {
            sum[i] += v[idx];
        }
    }

    // count among [1, UP]
    auto calc = [&](const vector<int>& UP) -> mint {
        if (UP.empty()) return 0;
        int n = UP.size();

        for (int l = 0; l < n; l++) {
            // front digit exclude leading-zero
            for (int d = 1; d <= (l == 0 ? UP[l] : m - 1); d++) {
                int ni = AHO.move(char('0' + d), 0), nj = sum[ni];
                if (nj <= K) ndp[ni][nj][(l == 0 && d == UP[0])]++;
            }
            for (int i = 0; i < sz; i++) {
                for (int j = 0; j <= K; j++) {
                    for (int k = 0; k < 2; k++) {
                        mint val = dp[i][j][k];
                        if (val == 0) continue;
                        for (int d = 0; d <= (k == 1 ? UP[l] : m - 1); d++) {
                            int ni = AHO.move(char('0' + d), i), nj = j + sum[ni];
                            if (nj <= K) ndp[ni][nj][(k == 1 && d == UP[l])] += val;
                        }
                    }
                }
            }

            swap(dp, ndp);
            for (int i = 0; i < sz; i++) {
                for (int j = 0; j <= K; j++) {
                    for (int k = 0; k < 2; k++) {
                        ndp[i][j][k] = 0;
                    }
                }
            }
        }

        mint res = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j <= K; j++) {
                for (int k = 0; k < 2; k++) {
                    res += dp[i][j][k];
                    dp[i][j][k] = 0;
                }
            }
        }
        return res;
    };

    mint ans = calc(R) - calc(L);
    cout << ans << '\n';
    return 0;
}