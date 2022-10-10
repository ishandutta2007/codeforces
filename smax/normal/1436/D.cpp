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

int sz[200005];
long long a[200005];
__int128 tot[200005];
vector<int> adj[200005];

long long dfs(int u) {
    // DEBUG(u, p)
    if ((int) adj[u].size() <= 0) {
        sz[u] = 1;
        tot[u] = a[u];
        return a[u];
    }
    long long mx = 0;
    for (int v : adj[u]) {
        // if (v != p) {
            mx = max(mx, dfs(v));
            sz[u] += sz[v];
            tot[u] += tot[v];
        }
    // DEBUG(sz[u], mx, tot[u])
    assert(sz[u] >= 1);
    assert((__int128) mx * sz[u] >= tot[u]);
    __int128 change = min((__int128) mx * sz[u] - tot[u], (__int128) a[u]);
    tot[u] += a[u];
    a[u] -= change;
    return mx + (a[u] + sz[u] - 1) / sz[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=1; i<n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
        // adj[i].push_back(p);
    }
    for (int i=0; i<n; i++)
        cin >> a[i];
    cout << dfs(0) << "\n";

    return 0;
}