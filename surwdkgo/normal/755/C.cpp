#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> edg[20010];
int vis[20010];

void Dfs(int x)
{
    vis[x] = 1;
    for (int i=0; i<edg[x].size(); i++)
    {
        if (!vis[edg[x][i]])
        {
            Dfs(edg[x][i]);
        }
    }
    return;
}

void Solve()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        int k=0;
        scanf("%d", &k);
        edg[i].push_back(k-1);
        edg[k-1].push_back(i);
        vis[i] =0;
    }
    int cnt = 0;
    for (int i=0; i<n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            Dfs(i);
        }
    }
    printf("%d\n", cnt);
    return;
}

int main()
{
    int cas=1;
    for (int i = 0; i < cas; i++)
    {
        Solve();
    }
    return 0;
}