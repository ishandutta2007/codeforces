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
int q[2000];
int d[2000];

int g[2000][2000];

int num[2000];

bool comp(int a, int b)
{
    return (q[a] > q[b]);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &q[i]);
    scanf("%d", &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            g[i][j] = 10000000;
    for (int i = 1; i <= m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    for (int i = 1; i <= n; i ++)
        num[i] = i;
    sort(num + 1, num + n + 1, comp);

    d[1] = 0;
    for (int i = 2; i <= n; i ++)
    {
        d[i] = 2000000000;
        for (int j = 1; j < i; j ++)
            if (g[num[j]][num[i]] != 10000000)
                d[i] = min(d[i], d[i - 1] + g[num[j]][num[i]]);
    }

    printf("%d\n", (d[n] == 2000000000 ? -1 : d[n]));
    return 0;
}