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

int n, sz[100005], par[100005];
vector<int> adj[100005];

int dfsSz(int u) {
    sz[u] = 1;
    for (int v : adj[u])
        if (v != par[u]) {
            par[v] = u;
            sz[u] += dfsSz(v);
        }
    return sz[u];
}

int dfsCentroid(int u) {
    for (int v : adj[u])
        if (v != par[u] && sz[v] > n / 2)
            return dfsCentroid(v);
    return u;
}

bool isCentroid(int u) {
    for (int v : adj[u])
        if ((v == par[u] && n - sz[u] > n / 2) || (v != par[u] && sz[v] > n / 2))
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        par[0] = -1;
        dfsSz(0);
        int u = dfsCentroid(0), second = -1;
        // check if second centroid exists
        for (int v : adj[u])
            if (isCentroid(v)) {
                assert(second == -1);
                second = v;
            }

        if (second == -1) {
            cout << "1 " << adj[0][0] + 1 << "\n1 " << adj[0][0] + 1 << "\n";
        } else {
            // remove subtree under one centroid and attach under other
            if ((int) adj[u].size() > 1) {
                int v = (adj[u][0] == second ? adj[u][1] : adj[u][0]);
                cout << u + 1 << " " << v + 1 << "\n" << second + 1 << " " << v + 1 << "\n";
            } else {
                assert((int) adj[second].size() > 1);
                int v = (adj[second][0] == u ? adj[second][1] : adj[second][0]);
                cout << second + 1 << " " << v + 1 << "\n" << u + 1 << " " << v + 1 << "\n";
            }
        }
    }

    return 0;
}