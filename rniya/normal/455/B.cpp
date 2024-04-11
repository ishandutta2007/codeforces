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

const int INF = 1e9;
const long long IINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const char dir[4] = {'D', 'R', 'U', 'L'};
const long long MOD = 1000000007;
// const long long MOD = 998244353;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    auto ctoi = [](char c) { return c - 'a'; };
    Trie<26> trie(ctoi);
    for (; n--;) {
        string s;
        cin >> s;
        trie.add(s);
    }
    int sz = trie.size();

    vector<int> grundy(sz);
    auto dfs = [&](auto self, int node, int val) -> int {
        set<int> s;
        for (int i = 0; i < 26; i++) {
            int nxt = trie.next(node, i);
            if (nxt < 0) continue;
            s.emplace(self(self, nxt, val));
        }
        if (s.empty()) return val;
        for (int i = 0;; i++) {
            if (!s.count(i)) {
                return i;
            }
        }
    };

    int win = dfs(dfs, 0, 0), lose = dfs(dfs, 0, 1);
    if (!win) {
        cout << "Second" << '\n';
        return 0;
    } else if (lose) {
        cout << "First" << '\n';
        return 0;
    }
    cout << (k & 1 ? "First" : "Second") << '\n';
    return 0;
}