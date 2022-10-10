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

int maxDepth[100005], maxDepth2[100005];
vector<int> adj[100005];

void dfs1(int u, int p) {
    maxDepth[u] = maxDepth2[u] = 0;
    for (int v : adj[u])
        if (v != p) {
            dfs1(v, u);
            if (maxDepth[v] + 1 > maxDepth[u]) {
                maxDepth2[u] = maxDepth[u];
                maxDepth[u] = maxDepth[v] + 1;
            } else if (maxDepth[v] + 1 > maxDepth2[u]) {
                maxDepth2[u] = maxDepth[v] + 1;
            }
        }
}

int k, center = -1;

void dfs2(int u, int p) {
    if (maxDepth[u] == k && adj[u].size() >= 3) {
        if (center != -1) {
            cout << "No\n";
            exit(0);
        }
        center = u;
    }
    for (int v : adj[u])
        if (v != p) {
            int old = maxDepth[v], old2 = maxDepth2[v];
            int quant = (maxDepth[v] + 1 == maxDepth[u] ? maxDepth2[u] + 1 : maxDepth[u] + 1);
            if (quant > maxDepth[v]) {
                maxDepth2[v] = maxDepth[v];
                maxDepth[v] = quant;
            } else if (maxDepth2[u] + 1 > maxDepth2[v]) {
                maxDepth2[v] = quant;
            }
            dfs2(v, u);
            maxDepth[v] = old;
            maxDepth2[v] = old2;
        }
}

void dfs3(int u, int p, int d) {
    if (d == k) {
        if (adj[u].size() != 1) {
            DEBUG("LEAF", u, d)
            cout << "No\n";
            exit(0);
        }
        return;
    }
    if ((d == 0 && adj[u].size() < 3) || (d != 0 && adj[u].size() < 4)) {
        DEBUG(u, d)
        cout << "No\n";
        exit(0);
    }
    for (int v : adj[u])
        if (v != p)
            dfs3(v, u, d + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0, -1);
    dfs2(0, -1);
    if (center == -1) {
        cout << "No\n";
        return 0;
    }
    DEBUG(center)

    dfs3(center, -1, 0);
    cout << "Yes\n";

    return 0;
}