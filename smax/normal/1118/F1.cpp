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

int a[300005], szRed[300005], szBlue[300005];
vector<int> adj[300005];

void dfs1(int u, int p) {
    szRed[u] = (a[u] == 1);
    szBlue[u] = (a[u] == 2);
    for (int v : adj[u])
        if (v != p) {
            dfs1(v, u);
            szRed[u] += szRed[v];
            szBlue[u] += szBlue[v];
        }
}

int dfs2(int u, int p) {
    int ret = 0;
    for (int v : adj[u])
        if (v != p) {
            ret += dfs2(v, u);
            if (!(szRed[v] && szBlue[v]) && !(szRed[0] - szRed[v] && szBlue[0] - szBlue[v]))
                ret++;
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0, -1);
    cout << dfs2(0, -1) << "\n";

    return 0;
}