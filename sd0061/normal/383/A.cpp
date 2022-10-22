#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

#define N 200005
int n , m , a[N] , d[N];

void work()
{
    int i , j;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= n ; ++ i)
        if (a[i])
        {
            ++ d[i + 1];
        }
        else
        {
            ++ d[1];
            -- d[i];
        }
    for (i = 1 ; i <= n ; ++ i)
        d[i] += d[i - 1] ;// , cout << d[i] << endl;
    long long ans1 = 0 , ans2 = 0;

    for (i = 1 , j = 0 ; i <= n ; ++ i)
        if (a[i] == 1)
        {
            ans1 += d[i] - j;
            ++ j;
        }
    for (i = n , j = 0 ; i > 0 ; -- i)
        if (a[i] == 0)
        {
            ans2 += d[i] - j;
            ++ j;
        }
    cout << min(ans1 , ans2) << endl;
}

int main()
{
    work();
    return 0;
}