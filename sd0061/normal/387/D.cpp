#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define N 505
#define M 200005

int n , m , pre[N] , mcnt;
bool a[N][N];
struct edge
{
    int x , next;
}e[N * N];
int re[N];
bool f[N];

bool find(int x)
{
    for (int i = pre[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].x;
        if (!f[y])
        {
            f[y] = 1;
            if (!re[y] || find(re[y]))
            {
                re[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

void work()
{
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d%d",&x,&y) , a[x][y] = 1;
    int ans = 1 << 30;

    for (x = 1 ; x <= n ; ++ x)
    {
        int sum = !a[x][x] , ed = m - a[x][x] , res = 0;
        for (i = 1 ; i <= n ; ++ i)
            if (i != x)
                sum += !a[i][x] + !a[x][i] , ed -= a[i][x] + a[x][i];
        memset(pre , -1 , sizeof(pre)) , mcnt = 0;
        for (i = 1 ; i <= n ; ++ i) if (i != x)
            for (j = 1 ; j <= n ; ++ j) if (j != x && a[i][j])
                e[mcnt] = (edge) {j , pre[i]} , pre[i] = mcnt ++;
        memset(re , 0 , sizeof(re));
        for (i = 1 ; i <= n ; ++ i)
            if (i != x)
            {
                memset(f , 0 , sizeof(f));
                res += find(i);
            }
        if (res >= n - 1)
            sum += ed - n + 1;
        else
            sum += ed - res + n - 1 - res;
        ans = min(ans , sum);
    }
    printf("%d\n" , ans);
}

int main()
{
    work();
    return 0;
}