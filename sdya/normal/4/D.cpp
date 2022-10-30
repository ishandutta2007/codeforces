#include <iostream>
#include <vector>

using namespace std;

int n, m = 0;
int a, b;
int w[6000], h[6000];
bool used[6000];
int dp[6000], pr[6000];

int r[6000];
vector < int > ans;

void dfs(int v)
{
    if (used[v]) return;
    used[v] = true;

    for (int i = 1; i <= n; i ++)
        if (w[v] > w[i] && h[v] > h[i]) dfs(i);

    m ++, r[m] = v;
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i ++)
        scanf("%d%d", &w[i], &h[i]);
    for (int i = 1; i <= n; i ++)
        if (!used[i]) dfs(i);

    for (int i = 1; i <= n; i ++)
        if (w[r[i]] > a && h[r[i]] > b) 
        {
            dp[i] = 1;
            pr[i] = -1;
            for (int j = 1; j < i; j ++)
                if (w[r[i]] > w[r[j]] && h[r[i]] > h[r[j]] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1, pr[i] = j;
        } else dp[i] = 0, pr[i] = -1;

    int res = 0, v = -1;
    for (int i = 1; i <= n; i ++)
        if (dp[i] > res) res = dp[i], v = i;
    printf("%d\n", res);
    if (v != -1)
    {
        while (v != -1)
        {
            ans.push_back(r[v]);
            v = pr[v];
        }
        for (int i = res - 1; i >= 0; i --)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}