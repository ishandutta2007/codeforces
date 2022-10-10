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

const int MAXN = 2e5 + 5;

int r, c[MAXN];
bool vis[MAXN];
vector<pair<int, int>> adj[MAXN];

void dfs(int u, int p) {
    if ((int) adj[u].size() <= r) {
        for (auto [v, i] : adj[u])
            if (c[i] != -1)
                vis[c[i]] = true;
        int nxt = 0;
        while (vis[nxt])
            nxt++;
        for (auto [v, i] : adj[u])
            if (c[i] == -1) {
                c[i] = nxt++;
                while (vis[nxt])
                    nxt++;
            }
        for (auto [v, i] : adj[u])
            vis[c[i]] = false;
    }
    for (auto [v, i] : adj[u])
        if (v != p)
            dfs(v, u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].emplace_back(y, i);
        adj[y].emplace_back(x, i);
    }

    vector<int> deg;
    for (int i=0; i<n; i++)
        deg.push_back(adj[i].size());

    sort(deg.rbegin(), deg.rend());
    r = deg[k];
    memset(c, -1, sizeof(c));
    dfs(0, -1);

    cout << r << "\n";
    for (int i=0; i<n-1; i++)
        cout << max(c[i], 0) + 1 << " ";
    cout << "\n";

    return 0;
}