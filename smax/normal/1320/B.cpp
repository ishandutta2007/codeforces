#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i=0; i<k; i++) {
        cin >> p[i];
        p[i]--;
    }

    vector<int> dist(n, -1);
    vector<set<int>> par(n);
    queue<int> q;
    dist[p[k-1]] = 0;
    q.push(p[k-1]);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (dist[v] == -1 || dist[u] + 1 == dist[v]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
                par[v].insert(u);
            }
    }

    int mn = 0, mx = 0;
    for (int i=0; i<k-1; i++) {
        if (!par[p[i]].count(p[i+1])) mn++;
        if (par[p[i]].size() - par[p[i]].count(p[i+1]) > 0) mx++;
    }
    cout << mn << " " << mx << "\n";

    return 0;
}