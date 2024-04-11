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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int MAXN = 5e6 + 5;

namespace scc {
    int ti, nc, num[MAXN], low[MAXN];
    bool visited[MAXN];
    vector<int> adj[MAXN], st;

    void dfs(int u) {
        num[u] = low[u] = ti++;
        st.push_back(u);
        visited[u] = true;
        for (int v : adj[u]) {
            if (num[v] == -1)
                dfs(v);
            if (visited[v])
                low[u] = min(low[u], low[v]);
        }

        if (low[u] == num[u]) {
            int v = -1;
            while (u != v) {
                v = st.back();
                st.pop_back();
                low[v] = nc;
                visited[v] = false;
            }
            nc++;
        }
    }

    void scc(int n) {
        memset(num, -1, sizeof(num));
        ti = nc = 0;
        for (int i=0; i<n; i++)
            if (num[i] == -1)
                dfs(i);
    }
};

int dp[MAXN], tot[MAXN];
vector<int> adj[MAXN];

int solve(int u) {
    int &ret = dp[u];
    if (ret != -1)
        return ret;
    ret = tot[u];
    for (int v : adj[u])
        ret = max(ret, tot[u] + solve(v));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;
    cin >> n >> m >> d;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        for (int j=0; j<d; j++)
            scc::adj[n * j + u].push_back(n * ((j + 1) % d) + v);
    }

    scc::scc(n * d);
    vector<int> last(scc::nc, -1);
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<d; j++)
            if (s[j] == '1' && last[scc::low[n * j + i]] != i) {
                last[scc::low[n * j + i]] = i;
                tot[scc::low[n * j + i]]++;
            }
    }

    for (int u=0; u<n*d; u++)
        for (int v : scc::adj[u])
            if (scc::low[u] != scc::low[v])
                adj[scc::low[u]].push_back(scc::low[v]);

    memset(dp, -1, sizeof(dp));
    cout << solve(scc::low[0]) << "\n";

    return 0;
}