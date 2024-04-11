#include <iostream>
#include <cstdio>
using namespace std;
#define N 1000010
int n , m , L[N] , ans;
int f[20][N];
int LCA(int x , int y)
{
    if (L[x] > L[y]) swap(x , y);
    for (int i = 19 ; i >= 0 ; -- i)
        if (L[y] - L[x] >= 1 << i)
            y = f[i][y];
    if (x == y) return y;
    for (int i = 19 ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y])
            x = f[i][x] , y = f[i][y];
    return f[0][x];
}
int main()
{
    int i , x , y , q , w;
    scanf("%d",&m);
    n = 4 , ans = 2;
    f[0][2] = f[0][3] = f[0][4] = 1;
    L[2] = L[3] = L[4] = 1;
    q = 2 , w = 4;
    while (m --)
    {
        scanf("%d",&x);
        L[++ n] = L[x] + 1 , f[0][n] = x;
        for (i = 1 ; i < 20 ; ++ i)
            f[i][n] = f[i - 1][f[i - 1][n]];
        L[++ n] = L[x] + 1 , f[0][n] = x;
        for (i = 1 ; i < 20 ; ++ i)
            f[i][n] = f[i - 1][f[i - 1][n]];
        y = LCA(q , n);
        if (L[q] + L[n] - L[y] - L[y] > ans)
            ans = L[q] + L[n] - L[y] - L[y] , w = n;
        y = LCA(w , n);
        if (L[w] + L[n] - L[y] - L[y] > ans)
            ans = L[w] + L[n] - L[y] - L[y] , q = n;
        printf("%d\n" , ans);
    }
    return 0;
}