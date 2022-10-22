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
#define N 100004
int n , m , X , Y , Z , p;
int x[N] , y[N];
void work()
{
    int i , j;
    scanf("%d%d%d%d%d%d",&n,&m,&X,&Y,&Z,&p);
    for (i = 0 ; i < p ; ++ i)
        scanf("%d%d",&x[i] ,&y[i]);
    X %= 4 , Y %= 2 , Z %= 4;
    while (X --)
    {
        for (i = 0 ; i < p ; ++ i)
        {
            swap(x[i] , y[i]) , y[i] = n - y[i] + 1;
        }
            swap(n , m);

    }
    while (Y --)
        for (i = 0 ; i < p ; ++ i)
        {
            y[i] = m - y[i] + 1;
        }
    Z = 4 - Z;
    while (Z --)
    {
        for (i = 0 ; i < p ; ++ i)
        {
            swap(x[i] , y[i]) , y[i] = n - y[i] + 1;
        }
        swap(n , m);
    }
    for (i = 0 ; i < p ; ++ i)
        printf("%d %d\n" , x[i] , y[i]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}