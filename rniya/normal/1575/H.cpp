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

template <int i, typename T> void print_tuple(ostream&, const T&) {}
template <int i, typename T, typename H, class... Args> void print_tuple(ostream& os, const T& t) {
    if (i) os << ',';
    os << get<i>(t);
    print_tuple<i + 1, T, Args...>(os, t);
}
template <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '{';
    print_tuple<0, tuple<Args...>, Args...>(os, t);
    return os << '}';
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

int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

template <class T> T ceil(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T> T floor(T x, T y) {
    assert(y >= 1);
    return (x > 0 ? x / y : (x - y + 1) / y);
}

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

#include <array>
#include <cassert>
#include <string>
#include <vector>

template <size_t char_size, char margin = 'a'> struct Trie {
    struct Node {
        std::array<int, char_size> nxt;
        std::vector<int> idxs;
        int idx, sub;
        char key;
        Node(char c) : idx(-1), key(c) { fill(nxt.begin(), nxt.end(), -1); }
    };

    std::vector<Node> nodes;

    inline int& next(int i, int j) { return nodes[i].nxt[j]; }

    Trie() { nodes.emplace_back('$'); }

    void add(const std::string& s, int x = 0) {
        int cur = 0;
        for (const char& c : s) {
            int k = c - margin;
            if (next(cur, k) < 0) {
                next(cur, k) = nodes.size();
                nodes.emplace_back(c);
            }
            cur = next(cur, k);
            nodes[cur].sub++;
        }
        nodes[cur].idx = x;
        nodes[cur].idxs.emplace_back(x);
    }

    int find(const std::string& s) {
        int cur = 0;
        for (const char& c : s) {
            int k = c - margin;
            if (next(cur, k) < 0) return -1;
            cur = next(cur, k);
        }
        return cur;
    }

    int move(int pos, char c) {
        assert(pos < (int)nodes.size());
        return pos < 0 ? -1 : next(pos, c - margin);
    }

    int size() const { return nodes.size(); }

    int idx(int pos) { return pos < 0 ? -1 : nodes[pos].idx; }

    std::vector<int> idxs(int pos) { return pos < 0 ? std::vector<int>() : nodes[pos].idxs; }
};

/**
 * @brief Trie
 * @docs docs/string/Trie.md
 */

#include <map>
#include <queue>

template <size_t char_size, char margin = 'a'> struct AhoCorasick : Trie<char_size + 1, margin> {
    void build(bool heavy = true) {
        int n = nodes.size();
        cnt.resize(n);
        for (int i = 0; i < n; i++) cnt[i] = nodes[i].idxs.size();
        std::queue<int> que;
        for (size_t i = 0; i <= char_size; i++) {
            if (~next(0, i)) {
                next(next(0, i), FAIL) = 0;
                que.emplace(next(0, i));
            } else
                next(0, i) = 0;
        }
        while (!que.empty()) {
            auto& cur = nodes[que.front()];
            int fail = cur.nxt[FAIL];
            cnt[que.front()] += cnt[fail];
            que.pop();
            for (size_t i = 0; i < char_size; i++) {
                int& nxt = cur.nxt[i];
                if (nxt < 0) {
                    nxt = next(fail, i);
                    continue;
                }
                next(nxt, FAIL) = next(fail, i);
                if (heavy) {
                    auto& u = nodes[nxt].idxs;
                    auto& v = nodes[next(fail, i)].idxs;
                    std::vector<int> w;
                    set_union(u.begin(), u.end(), v.begin(), v.end(), back_inserter(w));
                    u = w;
                }
                que.emplace(nxt);
            }
        }
    }

    long long match(const std::string& s) {
        long long res = 0;
        int cur = 0;
        for (const char& c : s) {
            cur = next(cur, c - margin);
            res += cnt[cur];
        }
        return res;
    }

    std::map<int, int> frequency(const std::string& s) {
        std::map<int, int> res;
        int cur = 0;
        for (const char& c : s) {
            cur = next(cur, c - margin);
            for (auto& idx : nodes[cur].idxs) res[idx]++;
        }
        return res;
    }

    int count(int pos) { return cnt[pos]; }

private:
    using super = Trie<char_size + 1, margin>;
    using super::next;
    using super::nodes;

    const int FAIL = char_size;
    std::vector<int> cnt;
};

/**
 * @brief Aho Corasick
 * @docs docs/string/AhoCorasick.md
 */

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

const int MAX_N = 505;
int dp[MAX_N][MAX_N][MAX_N];  // i  j  k 

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string S, T;
    cin >> S >> T;

    AhoCorasick<2, '0'> AHO;
    AHO.add(T);
    AHO.build(false);
    int sz = AHO.size();
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k <= n - m + 1; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k <= n - m + 1; k++) {
                int val = dp[i][j][k];
                if (val == INF) continue;
                for (int l = 0; l < 2; l++) {
                    int nxt = AHO.move(j, '0' + l);
                    chmin(dp[i + 1][nxt][k + (AHO.count(nxt))], val + (l != (S[i] - '0')));
                }
            }
        }
    }

    vector<int> ans(n - m + 2, INF);
    for (int j = 0; j < sz; j++) {
        for (int k = 0; k <= n - m + 1; k++) {
            chmin(ans[k], dp[n][j][k]);
        }
    }
    for (int i = 0; i <= n - m + 1; i++) cout << (ans[i] == INF ? -1 : ans[i]) << (i == n - m + 1 ? '\n' : ' ');
    return 0;
}