#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <set>
using namespace std;

#define N 42

int n , m , q;
char g[N][N];
int p[N][N] , f[N][N][N][N];

void work()
{
    int i , j , k , l , x , a , b , c , d , w;
    scanf("%d%d%d",&n,&m,&q);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , g[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (g[i][j] == '1');
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            for (k = 1 ; k <= n ; ++ k)
                for (l = 1 ; l <= m ; ++ l)
                {
                    x = p[k][l] - p[i - 1][l] - p[k][j - 1] + p[i - 1][j - 1];
                    if (k < i || l < j) x = 1;
                    f[i][j][k][l] = f[i - 1][j][k][l] + f[i][j - 1][k][l] + f[i][j][k - 1][l] + f[i][j][k][l - 1] -
                    f[i - 1][j - 1][k][l] - f[i - 1][j][k - 1][l] - f[i - 1][j][k][l - 1] - f[i][j - 1][k - 1][l] - f[i][j - 1][k][l - 1] - f[i][j][k - 1][l - 1] +
                    f[i][j - 1][k - 1][l - 1] + f[i - 1][j][k - 1][l - 1] + f[i - 1][j - 1][k][l - 1] + f[i - 1][j - 1][k - 1][l] - f[i - 1][j - 1][k - 1][l - 1] + (x == 0);
                }
    while (q --)
    {
        scanf("%d%d%d%d",&i,&j,&k,&l);
        x = 0;
        for (w = 0 ; w < 16 ; ++ w)
        {
            a = w & 8 ? k : i - 1;
            b = w & 4 ? l : j - 1;
            c = w & 2 ? k : i - 1;
            d = w & 1 ? l : j - 1;
            if (__builtin_popcount(w) & 1)
                x -= f[a][b][c][d];
            else x += f[a][b][c][d];
        }
        printf("%d\n" , x);
    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //while (~scanf("%d%d%d%d",&n,&m,&C,&D))
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}