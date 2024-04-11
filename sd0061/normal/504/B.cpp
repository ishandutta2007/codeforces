#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200005;
int n;
int a[N] , b[N] , c[N];
int f[N] , g[N];
int main()
{
    int i , j , k , x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&b[i]);

    for (i = 0 ; i < n ; ++ i) {
        x = a[i] + 1 , y = 0;
        for (j = x ; j > 0 ; j -= j & -j)
            y += c[j];
        for (j = x ; j <= n ; j += j & -j)
            c[j] ++;
        f[n - i - 1] = x - y - 1;
    }
    memset(c , 0 , sizeof(c));
    for (i = 0 ; i < n ; ++ i) {
        x = b[i] + 1 , y = 0;
        for (j = x ; j > 0 ; j -= j & -j)
            y += c[j];
        for (j = x ; j <= n ; j += j & -j)
            c[j] ++;
        g[n - i - 1] = x - y - 1;
    }
    for (i = 0 ; i < n ; ++ i) {
        f[i] += g[i];
        if (f[i] > i) {
            f[i] -= i + 1;
            f[i + 1] ++;
        }
    }
    reverse(f , f + n);
    memset(c , 0 , sizeof(c));
    for (i = 0 ; i < n ; ++ i) {
        for (j = i + 1 ; j <= n ; j += j & -j)
            ++ c[j];
    }
    for (i = 0 ; i < n ; ++ i) {
        //printf("%d " , f[i]);
        k = f[i] + 1;
        x = 0;
        for (j = 17 ; j >= 0 ; -- j) {
            if (x + (1 << j) <= n && c[x + (1 << j)] < k) {
                x += 1 << j;
                k -= c[x];
            }
        }
        printf("%d " , x);
        for (j = x + 1 ; j <= n ; j += j & -j)
            -- c[j];
    }
    return 0;
}