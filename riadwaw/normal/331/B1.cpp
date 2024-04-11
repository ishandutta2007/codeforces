#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

int a[101], pos[101];

bool check(int x, int y)
{
    if (x > y)
        return 0;
    if (x == y)
        return 1;
    while (x < y)
    {
        if (pos[x] > pos[x + 1])
            return 0;
        x++;
    }
    return 1;
}

int solve(int x, int y)
{
    if (x > y)
        return 0;
    if (x == y)
        return 1;

    int res = 1e9;
    for (int r = y; r >= x; r--)
        if (check(x, r))
            return solve(r + 1, y) + 1;
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif

    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", & a[i]);
        pos[a[i]] = i;
    }
    cin >> m;
    for (int i = 0; i < m; i++) 
    {
        int p, x, y;
        scanf("%d%d%d", &p, &x, &y);
        if (p == 1)
            printf("%d\n", solve(x, y));
        else
        {
            swap(pos[a[x]], pos[a[y]]);
            swap(a[x], a[y]);
        }
    }
}