#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
#define M 505
int n , m , K;
int c[N] , t[N] , f[N] , s[N];
int d[M][M];

int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}

void work()
{
    int i , j , k , x , y , w;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 1 ; i <= K ; ++ i)
        scanf("%d",&c[i]) , t[i] = t[i - 1] + c[i];
    for (i = 1 ; i <= n ; ++ i)
        f[i] = i , s[i] = 1;
    for (i = 1 ; i <= K ; ++ i)
        for (j = 1 ; j <= K ; ++ j) if (i != j)
            d[i][j] = 1e9;
    while (m --)
    {
        scanf("%d%d%d",&x,&y,&w);
        i = lower_bound(t + 1 , t + 1 + K , x) - t;
        j = lower_bound(t + 1 , t + 1 + K , y) - t;
        if (x != y)
            d[i][j] = d[j][i] = min(d[i][j] , w);
        if (w == 0)
        {
            x = getf(x) , y = getf(y);
            if (x != y)
                f[x] = y , s[y] += s[x];
        }
    }
    for (i = 1 ; i <= K ; ++ i)
    {
        x = getf(t[i - 1] + 1);
        for (j = t[i - 1] + 2 ; j <= t[i] ; ++ j)
            if (x != getf(j))
                break;
        if (j <= t[i]) break;
    }
    if (i <= K)
    {
        puts("No");
        return;
    }
    puts("Yes");
    for (k = 1 ; k <= K ; ++ k)
        for (i = 1 ; i <= K ; ++ i)
            for (j = 1 ; j <= K ; ++ j)
                d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
    for (i = 1 ; i <= K ; ++ i)
    {
        for (j = 1 ; j <= K ; ++ j)
            if (d[i][j] >= 1e9)
                printf("-1 ");
            else
                printf("%d " , d[i][j]);
        puts("");
    }
}

int main()
{
    work();
    return 0;
}