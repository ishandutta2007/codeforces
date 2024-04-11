#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

#define N 20
int n , L , R;
int X[N] , Y[N] , A[N];
double f[1 << 20] , ans , pi = acos(-1.0);
map<int , int> l;

void work()
{
    int i , j , k;
    double dx , dy , x , y , q;
    scanf("%d%d%d",&n,&L,&R) , R -= L;
    for (i = 0 ; i < n ; ++ i)
    {
        scanf("%d%d%d",&X[i],&Y[i],&A[i]);
        X[i] -= L;
        l[1 << i] = i;
    }
    for (i = 0 ; i < 1 << n ; ++ i)
    {
        ans = max(ans , f[i]);
        for (j = ~i & ((1 << n) - 1); j ; j &= j - 1)
        {
            k = l[j & -j];
            x = f[i] - X[k] , y = -Y[k] , q = A[k] * pi / 180.0;
            dx = cos(q)*x - sin(q)*y;
            dy = sin(q)*x + cos(q)*y;
            if (fabs(dy) < 1e-6)
                f[i | 1 << k] = 1e30;
            else
            {
                y = Y[k] / dy;
                x = X[k] - y * dx;
                if (x < f[i] - 1e-6)
                    f[i | 1 << k] = 1e30;
                else
                    f[i | 1 << k] = max(f[i | 1 << k] , x);
            }
        }
    }
    ans = min(ans , 1. * R);
    printf("%.10f\n" , ans);
}

int main()
{
        work();
    return 0;
}