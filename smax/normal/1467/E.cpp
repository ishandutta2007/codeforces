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

int ti = 0, a[MAXN], in[MAXN], out[MAXN];
bool dp[MAXN];
vector<int> adj[MAXN];
map<int, set<int>> mp;

bool dfs1(int u, int p) {
    in[u] = ti++;
    dp[u] = true;
    for (int v : adj[u])
        if (v != p)
            dp[u] &= dfs1(v, u);
    out[u] = ti;
    auto it = mp[a[u]].lower_bound(in[u]);
    if (it != mp[a[u]].end() && *it < out[u])
        dp[u] = false;
    mp[a[u]].insert(in[u]);
    return dp[u];
}

int dfs2(int u, int p) {
    int ret = dp[u] && (p == -1 || dp[p]) && (mp[a[u]].size() == 1);
    vector<bool> pref, suff;
    for (int v : adj[u])
        if (v != p)
            pref.push_back(dp[v]);
    for (int j=(int)adj[u].size()-1; j>=0; j--) {
        int v = adj[u][j];
        if (v != p)
            suff.push_back(dp[v]);
    }
    for (int i=1; i<(int)pref.size(); i++) {
        if (!pref[i-1]) pref[i] = false;
        if (!suff[i-1]) suff[i] = false;
    }
    reverse(suff.begin(), suff.end());

    int j = 0;
    for (int v : adj[u])
        if (v != p) {
            dp[u] = (j > 0 ? pref[j-1] : true) && (j + 1 < (int) suff.size() ? suff[j+1] : true) && (p == -1 || dp[p]);
            mp[a[u]].erase(in[u]);
            if (!mp[a[u]].empty() && (*mp[a[u]].begin() < in[v] || *mp[a[u]].rbegin() >= out[v]))
                dp[u] = false;
            mp[a[u]].insert(in[u]);
            ret += dfs2(v, u);
            j++;
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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