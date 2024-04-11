#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int n, m;
vector < int > g[200], c[200];
int used[200];

int res = 0;

void dfs(int v, int pred)
{
    if (used[v])
        return ;

    used[v] = true;
    for (int i = 0; i < g[v].size(); i ++)
        if (g[v][i] != pred)
            res += c[v][i], dfs(g[v][i], v);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        g[a].push_back(b), c[a].push_back(0);
        g[b].push_back(a), c[b].push_back(d);
    }


    int best = 1000000000;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < g[i].size(); j ++)
        {
            for (int k = 1; k <= n; k ++)
                used[k] = false;
            used[i] = true;
            res = c[i][j];
            dfs(g[i][j], i);
            best = min(best, res);
        }

    cout << best << endl;

    return 0;
}