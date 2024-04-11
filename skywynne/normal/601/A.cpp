// In The Name Of The Queen
#include<bits/stdc++.h>
using namespace std;
const int N = 404;
int n, m, D[N][N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        D[v][u] = D[u][v] = 1;
    }
    if (D[1][n] == 1)
    {
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if (i != j) D[i][j] = !D[i][j];
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (i != j && D[i][j] != 1)
                D[i][j] = (int)(1e9);
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    if (D[1][n] == (int)(1e9))
        D[1][n] = -1;
    return !printf("%d\n", D[1][n]);
}