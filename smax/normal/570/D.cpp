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

#define MAXN 500005

int id[MAXN];
bool ret[MAXN];
string s;
vector<int> adj[MAXN];
vector<pair<int, int>> queries[MAXN];
map<int, int> mp[MAXN];

void dfs(int u, int d) {
    mp[id[u]][d] = 1 << (s[u] - 'a');
    for (int v : adj[u]) {
        dfs(v, d + 1);
        if (mp[id[v]].size() > mp[id[u]].size())
            swap(id[u], id[v]);
        for (auto &p : mp[id[v]])
            mp[id[u]][p.first] ^= p.second;
    }
    for (auto &q : queries[u])
        ret[q.second] = !mp[id[u]].count(q.first) || __builtin_popcount(mp[id[u]][q.first]) <= 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=1; i<n; i++) {
        int p;
        cin >> p;
        adj[--p].push_back(i);
    }
    cin >> s;
    for (int i=0; i<m; i++) {
        int v, h;
        cin >> v >> h;
        queries[--v].emplace_back(h, i);
    }

    iota(id, id + n, 0);
    dfs(0, 1);

    for (int i=0; i<m; i++)
        cout << (ret[i] ? "Yes" : "No") << "\n";

    return 0;
}