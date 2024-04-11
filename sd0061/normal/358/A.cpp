#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
#define N 10005
int n , a[N];

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int i , j , x , y , s , t , f = 0;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i < n ; ++ i)
        for (j = 1 ; j < n ; ++ j)
        {
            x = min(a[i] , a[i + 1]);
            y = max(a[i] , a[i + 1]);
            s = min(a[j] , a[j + 1]);
            t = max(a[j] , a[j + 1]);
            if (t > y && s < y && s > x)
                f = 1;
        }
    puts(f ? "yes" : "no");
    return 0;
}