#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int MAX = 3e5 + 5;
const int ALPHA = 26;
const int LOG = 20;

string s[MAX];

struct AhoCorasick {
    int id;
    vector<int> link, dict;
    vector<long long> cnt;
    vector<vector<int>> trie;
    queue<int> q;

    void clear() {
        id = 1;
        link.clear();
        dict.clear();
        cnt.clear();
        trie.clear();
        link.emplace_back();
        cnt.emplace_back();
        trie.emplace_back(ALPHA);
    }

    void add(int i) {
        dict.push_back(i);
        int u = 0;
        for (char c : s[i]) {
            if (!trie[u][c-'a']) {
                u = trie[u][c-'a'] = id++;
                link.emplace_back();
                cnt.emplace_back();
                trie.emplace_back(ALPHA);
            } else
                u = trie[u][c-'a'];
        }
        cnt[u]++;
    }

    void gen() {
        link[0] = -1;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int j=0; j<ALPHA; j++) {
                int v = trie[u][j];
                if (v) {
                    link[v] = (link[u] == -1 ? 0 : trie[link[u]][j]);
                    q.push(v);
                } else if (u) {
                    trie[u][j] = trie[link[u]][j];
                }
            }
            if (link[u] != -1)
                cnt[u] += cnt[link[u]];
        }
    }

    long long query(int i) {
        int u = 0;
        long long ret = 0;
        for (char c : s[i]) {
            u = trie[u][c-'a'];
            ret += cnt[u];
        }
        return ret;
    }
};

struct Blocks {
    AhoCorasick ac[LOG];

    Blocks() {
        for (int i=0; i<LOG; i++)
            ac[i].clear();
    }

    void add(int x) {
        for (int i=0; i<LOG; i++)
            if (ac[i].dict.empty()) {
                ac[i].add(x);
                for (int j=0; j<i; j++) {
                    for (int y : ac[j].dict)
                        ac[i].add(y);
                    ac[j].clear();
                }
                ac[i].gen();
                break;
            }
    }

    long long query(int x) {
        long long ret = 0;
        for (int i=0; i<LOG; i++)
            ret += ac[i].query(x);
        return ret;
    }
};

Blocks add, rem;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int t;
        cin >> t >> s[i];
        if (t == 1)
            add.add(i);
        else if (t == 2)
            rem.add(i);
        else
            cout << add.query(i) - rem.query(i) << endl;
    }

    return 0;
}