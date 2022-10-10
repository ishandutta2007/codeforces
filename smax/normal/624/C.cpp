#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int sz, color[500];
vector<int> adj[500];
unordered_set<int> in[500];

bool dfs(int u, int c = 0) {
    if (color[u] != -1)
        return color[u] == c;

    color[u] = c;
    sz++;
    bool ret = true;
    for (int v : adj[u])
        ret &= dfs(v, 2 - c);
    if (sz == 1)
        color[u] = 1;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        in[u].insert(v);
        in[v].insert(u);
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i != j && !in[i].count(j))
                adj[i].push_back(j);

    memset(color, -1, sizeof(color));
    for (int i=0; i<n; i++)
        if (color[i] == -1) {
            sz = 0;
            if (!dfs(i)) {
                cout << "No\n";
                return 0;
            }
        }

    for (int i=0; i<n; i++)
        for (int j : in[i])
            if (abs(color[i] - color[j]) > 1) {
                cout << "No\n";
                return 0;
            }

    cout << "Yes\n";
    for (int i=0; i<n; i++) {
        if (color[i] == 0) cout << 'a';
        else if (color[i] == 1) cout << 'b';
        else cout << 'c';
    }
    cout << "\n";

    return 0;
}