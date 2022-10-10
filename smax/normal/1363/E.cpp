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

int a[200000], b[200000], c[200000];
long long ans = 0;
vector<int> adj[200000];

pair<int, int> dfs(int u, int p) {
    pair<int, int> ret;
    if (b[u] != c[u]) {
        if (b[u] == 1) ret.first++;
        else ret.second++;
    }
    bool take = true;
    if (p != -1 && a[p] < a[u]) {
        a[u] = a[p];
        take = false;
    }
    for (int v : adj[u])
        if (v != p) {
            auto pi = dfs(v, u);
            ret.first += pi.first;
            ret.second += pi.second;
        }
    if (take) {
        int change = min(ret.first, ret.second);
        ans += 2LL * change * a[u];
        ret.first -= change;
        ret.second -= change;
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
        cin >> a[i] >> b[i] >> c[i];
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto p = dfs(0, -1);

    cout << (p.first || p.second ? -1 : ans) << "\n";

    return 0;
}