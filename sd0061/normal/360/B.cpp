#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
#define N 2005

int n , m , a[N] , f[N];

bool check(int val)
{
    int i , j;
    for (i = 1 ; i <= n + 1 ; ++ i)
    {
        f[i] = i - 1;
        for (j = 1 ; j < i ; ++ j)
            if (i == n + 1 || abs(a[i] - a[j]) <= (LL)val * (i - j))
                f[i] = min(f[i] , f[j] + i - j - 1);
    }
    return f[n + 1] <= m;
}

void work()
{
    int i , x ;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    int top = 0 , bot = 2e9 , mid;
    while (top < bot)
    {
        mid = top + (bot - mid) / 2;
        if (check(mid))
            bot = mid;
        else
            top = mid + 1;
    }
    printf("%d\n" , top);
}

int main()
{
    work();
    return 0;
}