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

#define MAXN 5005

int ii = 0, cnt0, cnt1, dp[MAXN][MAXN], color[MAXN];
pair<int, int> sz[MAXN];
vector<int> adj[MAXN], comp[MAXN];

bool dfs(int u, int c = 0) {
    if (color[u] != -1)
        return color[u] == c;

    bool ret = true;
    color[u] = c;
    comp[ii].push_back(u);
    cnt0 += (c == 0);
    cnt1 += (c == 1);
    for (int v : adj[u])
        ret &= dfs(v, 1 - c);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, n1, n2, n3;
    cin >> n >> m >> n1 >> n2 >> n3;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    memset(dp, -1, sizeof(dp));
    memset(color, -1, sizeof(color));
    dp[0][0] = 0;
    for (int u=0; u<n; u++)
        if (color[u] == -1) {
            cnt0 = cnt1 = 0;
            if (!dfs(u)) {
                cout << "NO\n";
                return 0;
            }

            sz[ii] = {cnt0, cnt1};
            for (int j=0; j<=n; j++)
                if (dp[ii][j] != -1) {
                    if (j + cnt0 <= n) dp[ii+1][j+cnt0] = 0;
                    if (j + cnt1 <= n) dp[ii+1][j+cnt1] = 1;
                }
            ii++;
        }
    if (dp[ii][n2] == -1) {
        cout << "NO\n";
        return 0;
    }

    int j = n2;
    for (int i=ii-1; i>=0; i--) {
        if (dp[i+1][j] == 0) {
            for (int u : comp[i]) {
                if (color[u] == 0) {
                    color[u] = 2;
                } else if (n1) {
                    color[u] = 1;
                    n1--;
                } else {
                    color[u] = 3;
                }
            }
            j -= sz[i].first;
        } else {
            for (int u : comp[i]) {
                if (color[u] == 1) {
                    color[u] = 2;
                } else if (n1) {
                    color[u] = 1;
                    n1--;
                } else {
                    color[u] = 3;
                }
            }
            j -= sz[i].second;
        }
    }

    cout << "YES\n";
    for (int i=0; i<n; i++)
        cout << color[i];
    cout << "\n";

    return 0;
}