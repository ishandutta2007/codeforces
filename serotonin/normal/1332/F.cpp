#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5, mod = 998244353;

vector <int> g[sz];

int dp[sz][4];

/*
    0 = not in sub_graph, not in ind_set
    1 = in sub_graph, not in ind_set
    2 = in sub_graph, in ind_set
    3 = sum
*/

inline int add(int x, int y)
{
    int z = x + y;
    z < 0 ? z += mod : 1;
    return z < mod ? z : z - mod;
}

void dfs(int u = 1, int p = 0)
{
    for(int v : g[u]) if(v - p) dfs(v, u);

    int x = 1, y = 1, z = 1;
    for(int v : g[u]) if(v - p) {
        int ex = add(dp[v][3], 1);

        int ey1 = add(dp[v][1], dp[v][2]);
        int ey2 = add(dp[v][0], 1) * 2 % mod;
        int ey = add(ey1, ey2);

        int ez1 = dp[v][1];
        int ez2 = add(dp[v][0], 1);
        int ez = add(ez1, ez2);

        x = 1LL * x * ex % mod;
        y = 1LL * y * add(ex, ey) % mod;
        z = 1LL * z * add(ex, ez) % mod;
    }

    dp[u][0] = (x - 1) % mod;
    dp[u][1] = (y - x) % mod;
    dp[u][2] = (z - x) % mod;

    dp[u][3] = (add(y, z) - add(x, 1)) % mod;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();

    cout << (dp[1][3] < 0 ? dp[1][3] + mod: dp[1][3]);
}