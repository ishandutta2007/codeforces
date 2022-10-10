#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

bool a[100000][20];
long long dp[100000][20][2], ans[20];
vector<int> adj[100000];

void dfs(int u, int p) {
    vector<vector<long long>> single(20, vector<long long>(2));
    for (int i=0; i<20; i++)
        dp[u][i][a[u][i]] = 1;
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u);
            for (int i=0; i<20; i++)
                for (int x=0; x<2; x++) {
                    dp[u][i][x] += dp[v][i][x ^ a[u][i]];
                    single[i][x] += dp[v][i][x];
                }
        }
    for (int i=0; i<20; i++) {
        long long num0 = 0, num1 = 0;
        for (int v : adj[u])
            if (v != p) {
                num0 += (single[i][0] - dp[v][i][0]) * dp[v][i][0] + (single[i][1] - dp[v][i][1]) * dp[v][i][1];
                num1 += (single[i][0] - dp[v][i][0]) * dp[v][i][1] + (single[i][1] - dp[v][i][1]) * dp[v][i][0];
            }
        ans[i] += (a[u][i] ? num0 : num1) / 2 + dp[u][i][1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        for (int j=0; j<20; j++)
            a[i][j] = x & (1 << j);
    }
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    dfs(0, -1);
    long long ret = 0;
    for (int i=0; i<20; i++)
        ret += (1 << i) * ans[i];

    cout << ret << "\n";

    return 0;
}