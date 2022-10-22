#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 5005

int n , a[N];
int sum , ans , cnt;
int del[N] , f[N][N] , g[N][N];

void work()
{
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]) , a[i] = n - a[i];

    for (i = 1 ; i <= n ; ++ i)
        for (j = i + 1 ; j <= n ; ++ j)
            sum += a[i] < a[j];
    for (i = 1 ; i <= n + 1 ; ++ i)
    {
        for (j = 1 ; j <= n ; ++ j)
            f[i][j] = f[i - 1][j] , f[i - 1][j] += f[i - 1][j - 1];
        ++ f[i][a[i]];
    }
    for (i = n ; i >= 0 ; -- i)
    {
        for (j = n ; j > 0 ; -- j)
            g[i][j] = g[i + 1][j] , g[i + 1][j] += g[i + 1][j + 1];
        ++ g[i][a[i]];
    }

    ans = 1 << 30;
    for (i = 1 ; i <= n ; ++ i)
        for (j = i + 1 ; j <= n ; ++ j)
        {
            x = a[i] , y = a[j];
            int tot = sum;
            if (x < y) ++ tot;
            tot -= f[i - 1][x - 1] + g[i + 1][x + 1];
            tot += f[i - 1][y - 1] + g[i + 1][y + 1];
            tot -= f[j - 1][y - 1] + g[j + 1][y + 1];
            tot += f[j - 1][x - 1] + g[j + 1][x + 1];
            if (tot < ans)
                ans = tot , cnt = 1;
            else if (tot == ans)
                ++ cnt;
        }
    cout << ans << ' ' << cnt << endl;
}

int main()
{
   // freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d",&n,&T))
        work();
    return 0;
}