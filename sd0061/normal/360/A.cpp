#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
#define N 5005

int n , m , a[N] , lim[N];
bool f[N];
pair<int , int> A[N] , B[N];
void work()
{
    int i , j , k , x , y , w;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        lim[i] = 1000000000;
    for (i = 1 ; i <= m ; ++ i)
    {
        scanf("%d%d%d%d",&j,&x,&y,&w);
        A[i] = make_pair(j , x);
        B[i] = make_pair(y , w);
        if (j == 1)
        {
            for ( ; x <= y ; ++ x)
                a[x] += w;
        }
        else
        {
            for ( ; x <= y ; ++ x)
                lim[x] = min(lim[x] , w - a[x]);
        }
    }
    memset(a , 0 , sizeof(a));
    for (i = 1 ; i <= m ; ++ i)
    {
        j = A[i].first , x = A[i].second;
        y = B[i].first , w = B[i].second;
        if (j == 1)
        {
            for (k = x ; k <= y ; ++ k)
                a[k] += w;
        }
        else
        {
            for (k = x ; k <= y ; ++ k)
                if (lim[k] + a[k] > w)
                    break;
            if (k <= y) break;
            for (k = x ; k <= y ; ++ k)
                if (lim[k] + a[k] == w)
                    break;
            if (k > y) break;
        }
    }
    if (i <= m)
        puts("NO");
    else
    {
        puts("YES");
        for (i = 1 ; i <= n ; ++ i)
            printf("%d " , lim[i]);
    }
}

int main()
{
    work();
    return 0;
}