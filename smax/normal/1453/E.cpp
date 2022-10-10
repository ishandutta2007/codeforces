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

int k;
vector<int> adj[200005];

int dfs(int u, int p) {
    vector<int> ret;
    for (int v : adj[u])
        if (v != p) {
            ret.push_back(dfs(v, u));
            if (ret.back() == -1)
                return -1;
        }
    sort(ret.rbegin(), ret.rend());
    if ((!ret.empty() && ret[0] > k) || (ret.size() > 1 && ret[1] + 1 > k))
        return -1;
    if (!ret.empty() && ret[0] == k)
        return ret[0] + 1;
    return (ret.empty() ? 0 : ret.back()) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int l = 0, r = n;
        while (l < r) {
            k = (l + r) / 2;
            if (dfs(0, -1) != -1)
                r = k;
            else
                l = k + 1;
        }
        cout << l << "\n";
    }

    return 0;
}