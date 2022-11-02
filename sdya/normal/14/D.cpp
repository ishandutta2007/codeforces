#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#pragma comment (linker, "/STACK:32000000")

using namespace std;

int g[300][300], n, best = 0;
vector < int > p[300];

bool used[300];
int comp[300], cur;

int dfs(int x)
{
    if (used[x]) return 0;
    used[x] = true;
    int best = 0;
    for (int i = 0; i < p[x].size(); i ++)
        if (!used[p[x][i]] && g[x][p[x][i]]) best = max(best, dfs(p[x][i]) + 1);
    return best;
}

void calc_comp(int x)
{
    if (used[x]) return;
    used[x] = true;
    comp[x] = cur;
    for (int i = 0; i < p[x].size(); i ++)
        if (g[x][p[x][i]]) calc_comp(p[x][i]);
}

void calc(int u, int v)
{
    g[u][v] = g[v][u] = false;
    for (int i = 1; i <= n; i ++)
        used[i] = false, comp[i] = 0;;

    cur = 0;
    for (int i = 1; i <= n; i ++)
        if (!used[i]) cur ++, calc_comp(i);

    int b1 = 0, b2 = 0;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
            used[j] = false;
        int d = dfs(i);
        if (comp[i] == 1) b1 = max(b1, d); else b2 = max(b2, d);
    }
    best = max(best, b1 * b2);
    g[u][v] = g[v][u] = true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; i ++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = 1;
        p[u].push_back(v);
        p[v].push_back(u);
    }

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < p[i].size(); j ++)
            calc(i, p[i][j]);

    printf("%d\n", best);

    return 0;
}