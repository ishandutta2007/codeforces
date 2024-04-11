#include <bits/stdc++.h>

#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define sqr(a) ((a) * (a))
#define sz(a) ((int) (a).size())
const double PI = acos(-1.0);

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef unsigned int uint;
typedef long long llong;
typedef long double ldouble;
typedef unsigned long long ullong;

#define TASK "task"

using namespace std;

const int MAXN = 200117;

int n, p, arr[MAXN];
llong dp[MAXN][2][2];
vector<int> g[MAXN];

void dfs(int v)
{
    dp[v][0][0] = 0;
    dp[v][1][0] = -LLINF;
    dp[v][0][1] = -LLINF;
    dp[v][1][1] = arr[v];
    for (auto u : g[v])
    {
        dfs(u);
        llong cur00 = max(dp[v][0][0], max(dp[v][0][0] + dp[u][0][0],
                                           dp[v][0][1] + max(dp[u][1][1], dp[u][0][1])));
        llong cur01 = max(dp[v][0][1], max(dp[v][0][0] + max(dp[u][1][1], dp[u][0][1]),
                                           dp[v][0][1] + dp[u][0][0]));
        llong cur10 = max(dp[v][1][0], max(dp[v][1][0] + dp[u][0][0],
                                           dp[v][1][1] + max(dp[u][0][1], dp[u][1][1])));
        llong cur11 = max(dp[v][1][1], max(dp[v][1][0] + max(dp[u][0][1], dp[u][1][1]),
                                           dp[v][1][1] + dp[u][0][0]));
        dp[v][0][0] = cur00;
        dp[v][1][0] = cur10;
        dp[v][0][1] = cur01;
        dp[v][1][1] = cur11;
    }
}

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p, &arr[i]);
        if (i)
        {
            p--;
            g[p].pb(i);
        }
    }

    dfs(0);

    cout << max(dp[0][1][1], max(dp[0][0][0], dp[0][0][1]));

    return 0;
}