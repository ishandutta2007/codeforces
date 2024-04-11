#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
#define N 3005
int n , a[N] , b[N] , c[N];
LL f[N] , sb[N];
int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //freopen("~output.txt" , "w" , stdout);

    int i , j;
    LL x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &b[i]) , sb[i] = sb[i - 1] + b[i];
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &c[i]) , c[i] -= b[i];
    for (i = 1 ; i <= n ; ++ i)
        f[i] = -1LL << 60;
    f[1] = a[1];
    for (i = 2 ; i <= n ; ++ i)
        f[i] = a[i] + sb[i - 1];
    for (i = 2 ; i <= n ; ++ i)
    {
        if (i == n)
        {
            for (j = 1 ; j < i ; ++ j)
                f[i] = max(f[i] , f[j] + sb[n] - sb[j]);
        }
        x = -1LL << 60;
        for (j = 1 ; i - j > 1 ; ++ j)
        {
            x = max(x , (LL)c[i - j]);
            f[i] = max(f[i] , f[i - j - 1] + sb[i - 1] - sb[i - j - 1] + x + a[i]);
        }
    }
    cout << f[n] << endl;
    return 0;
}