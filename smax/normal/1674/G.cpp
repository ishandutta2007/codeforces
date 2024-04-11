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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> in(n), out(n), deg(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        in[v]++;
        out[u]++;
        deg[v]++;
    }

    queue<int> que;
    for (int i=0; i<n; i++)
        if (deg[i] == 0)
            que.push(i);

    vector<int> order;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--deg[v] == 0)
                que.push(v);
    }

    vector<int> dp(n);
    for (int i=n-1; i>=0; i--) {
        int u = order[i];
        dp[u] = 1;
        for (int v : adj[u])
            if (in[v] > 1 && out[u] > 1)
                dp[u] = max(dp[u], dp[v] + 1);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}