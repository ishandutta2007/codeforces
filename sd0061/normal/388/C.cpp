#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define N 1005
int n , a[N] , sum1 , sum2 , b[N] , m;

void work()
{
    int i , j , x;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
    {
        scanf("%d",&x);
        for (j = 1 ; j <= x ; ++ j)
            scanf("%d",&a[j]);
        if (x & 1)
            b[++ m] = a[(x + 1) / 2];
        for (j = 1 ; j <= x / 2 ; ++ j)
            sum1 += a[j];
        for (j = (x + 3) / 2; j <= x ; ++ j)
            sum2 += a[j];
    }
    sort(b + 1 , b + m + 1  , greater<int>());
    for (i = 1 ; i <= m ; ++ i)
        if (i & 1)
            sum1 += b[i];
        else
            sum2 += b[i];
    printf("%d %d\n" , sum1 , sum2);
}

int main()
{
 //   freopen("~input.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}