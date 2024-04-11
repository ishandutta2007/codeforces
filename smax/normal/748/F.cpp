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

int n, k, sz[200005];
bool isHome[200005];
vector<int> adj[200005];
vector<vector<int>> gather;

int dfs1(int u, int p) {
    sz[u] = isHome[u];
    for (int v : adj[u])
        if (v != p)
            sz[u] += dfs1(v, u);
    return sz[u];
}

int dfs2(int u, int p) {
    for (int v : adj[u])
        if (v != p && sz[v] > k)
            return dfs2(v, u);
    return u;
}

void dfs3(int u, int p) {
    if (isHome[u])
        gather.back().push_back(u);
    for (int v : adj[u])
        if (v != p)
            dfs3(v, u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<2*k; i++) {
        int c;
        cin >> c;
        c--;
        isHome[c] = true;
    }

    dfs1(0, -1);
    int c = dfs2(0, -1);
    if (isHome[c])
        gather.push_back({c});
    for (int v : adj[c]) {
        gather.emplace_back();
        dfs3(v, c);
        if (gather.back().empty())
            gather.pop_back();
    }

    assert(gather.size() > 1);
    sort(gather.begin(), gather.end(), [] (const vector<int> &a, const vector<int> &b) {
        if (a.size() == b.size())
            return a < b;
        return a.size() > b.size();
    });

    int idx = 0;
    vector<int> si(2 * k);
    for (auto &v : gather)
        for (int u : v)
            si[idx++] = u;

    cout << "1\n" << c + 1 << "\n";
    for (int i=0; i<k; i++)
        cout << si[i] + 1 << " " << si[i+k] + 1 << " " << c + 1 << "\n";

    return 0;
}