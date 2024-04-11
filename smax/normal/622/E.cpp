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

vector<int> depth, adj[500005];

void dfs(int u, int p, int d) {
    bool leaf = true;
    for (int v : adj[u])
        if (v != p) {
            leaf = false;
            dfs(v, u, d + 1);
        }
    if (leaf)
        depth.push_back(d);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ret = 0;
    for (int v : adj[0]) {
        depth.clear();
        dfs(v, 0, 0);
        sort(depth.begin(), depth.end());
        int cur = -1;
        for (int d : depth)
            cur = max(cur + 1, d);
        ret = max(ret, cur + 1);
    }
    cout << ret << "\n";

    return 0;
}