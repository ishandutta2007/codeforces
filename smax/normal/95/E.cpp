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

const int MAXN = 1e5 + 5;
const int INF = 1e9;

int dp[MAXN];
bool vis[MAXN];
vector<int> adj[MAXN];

int dfs(int u) {
    int ret = 1;
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            ret += dfs(v);
    return ret;
}

bool lucky(int x) {
    while (x > 0) {
        if (x % 10 != 4 && x % 10 != 7)
            return false;
        x /= 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, int> mp;
    for (int i=0; i<n; i++)
        if (!vis[i])
            mp[dfs(i)]++;

    dp[0] = -1;
    for (int j=1; j<=n; j++)
        dp[j] = INF;
    for (auto &p : mp) {
        for (int k=0; k<p.first; k++) {
            deque<pair<int, int>> dq;
            int delta = 0;
            for (int j=k; j<=n; j+=p.first) {
                while (!dq.empty() && dp[j] - delta <= dq.back().first)
                    dq.pop_back();
                dq.emplace_back(dp[j] - delta, j);
                dp[j] = dq.front().first + delta;
                if (dq.front().second == j - p.first * p.second)
                    dq.pop_front();
                delta++;
            }
        }
    }

    int ret = INF;
    for (int j=1; j<=n; j++)
        if (lucky(j))
            ret = min(ret, dp[j]);
    cout << (ret == INF ? -1 : ret) << "\n";

    return 0;
}