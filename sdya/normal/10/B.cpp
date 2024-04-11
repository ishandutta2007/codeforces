#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int a[200][200];
int s[200][200];

int used[200][200];

int x0, y0;

int ab(int x) {return (x > 0 ? x : -x);}

int main()
{
    scanf("%d%d", &n, &k);
    x0 = (k + 1) / 2, y0 = (k + 1) / 2;

    for (int i = 1; i <= k; i ++)
    {
        for (int j = 1; j <= k; j ++)
            a[i][j] = a[i][j - 1] + ab(x0 - i) + ab(y0 - j);
    }

    for (int it = 1; it <= n; it ++)
    {
        int m;
        scanf("%d", &m);

        int best = 1000000000, u = 0, v = 0;

        for (int i = 1; i <= k; i ++)
            for (int j = 1; j <= k - m + 1; j ++)
                if (s[i][j + m - 1] - s[i][j - 1] == 0 && a[i][j + m - 1] - a[i][j - 1] < best)
                    best = a[i][j + m - 1] - a[i][j - 1], u = i, v = j;

        if (best == 1000000000) printf("-1\n"); else
        {
            printf("%d %d %d\n", u, v, v + m - 1);
            for (int i = v; i <= v + m - 1; i ++)
                used[u][i] = 1;
            for (int i = 1; i <= k; i ++)
                s[u][i] = s[u][i - 1] + used[u][i];
        }
    }
    return 0;
}