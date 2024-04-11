#include <cstdio>
#include <vector>
//
using namespace std;

#define ll long long
#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
#define fix(a) do { if ((a) >= MOD) (a) -= MOD; } while (0)
#define fix2(a) do { if ((a) < 0) (a) += MOD; } while (0)

vector<int> graph[100005];
int f[100005][205];
int g[205][205];
int weight[100005];
int factorial[100005];

int n, k;
int inv2 = 500000004;

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int one_minus[205];

void dfs(int node, int prt)
{
    weight[node] = 1;
    f[node][0] = 2;
    for (int childidx = 0; childidx < graph[node].size(); childidx++) {
        int child = graph[node][childidx];
        if (child == prt) continue;
        dfs(child, node);
        for (int x = min(k, weight[node] - 1); x >= 0; x--) {
            for (int y = min(k - x, weight[child] - 1); y >= 0; y--) {
                int mulv = mul(f[node][x], f[child][y]);
                f[node][x+y] += mulv;
                fix(f[node][x+y]);
                f[node][x+y+1] += mulv;
                fix(f[node][x+y+1]);
            }
        }
        weight[node] += weight[child];
        /*for (int j = min(k, weight[node] - 1); j >= 0; j--) {
            for (int x = 0; x < min(weight[child], j+1); x++) {
                f[node][j] += mul(f[node][j-x], f[child][x]);
                fix(f[node][j]);
                if (j != x) {
                    f[node][j] += mul(f[node][j-x-1], f[child][x]);
                    fix(f[node][j]);
                }
            }
        }*/
    }
    f[node][0]--;
    fix2(f[node][0]);
    if (node != 1) {
        for (int j = 1; j <= min(k, weight[node]); j++) {
            one_minus[j] += f[node][j-1]; fix(one_minus[j]);
        }
    }
}

int C(int a, int b)
{
    return mul(factorial[a], fpow(mul(factorial[b], factorial[a-b]), MOD - 2));
}

int main()
{
    factorial[0] = 1;
    for (int i = 1; i <= 100000; i++) factorial[i] = mul(i, factorial[i-1]);
    scanf("%d%d", &n, &k);
    g[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= min(i, n-1); j++) {
            g[i+1][j+1] += mul(g[i][j], (n - 1) - j);
            fix(g[i+1][j+1]);
            g[i+1][j] += mul(g[i][j], j);
            fix(g[i+1][j]);
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v); graph[v].push_back(u);
    }
    dfs(1, 0);
    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            printf("f[%d][%d] = %d\n", i, j, f[i][j]);
        }
    }*/
    int ans = 0;
    /*for (int i = 1; i <= k; i++) printf("%d ", one_minus[i]);
    printf("\n");*/
    for (int i = 1; i <= min(k, n-1); i++) {
        //printf("%d ", C(n-1, i));
        ans += mul(f[1][i] - one_minus[i] + MOD, mul(g[k][i], fpow(C(n-1, i), MOD-2)));
        fix(ans);
    }
    printf("%d", ans);
    return 0;
}