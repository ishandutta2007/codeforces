#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define N 25
#define sqr(x) ((long long)(x)*(x))

int f[1 << 24] , p[1 << 24] , cnt , a[N];
int n , x[N] , y[N] , xx , yy;

void print(int i)
{
  if (i == 0) return;
  if (p[i] > 99999)
  {
    p[i] -= 100000;
    int x = p[i] / 100 , y = p[i] % 100;
    print(i & ~(1 << x) & ~(1 << y));
    printf("0 %d %d ", x + 1 , y + 1);
  }
  else
  {
    print(i & ~(1 << p[i]));
    printf("0 %d ", p[i] + 1);
  }
}

int main()
{
   int i , j , k , v;
   scanf("%d%d%d",&xx,&yy,&n);
   for (i = 0 ; i < n ; ++ i)
     scanf("%d%d",&x[i],&y[i]);
   f[0] = 0;
   for (i = 1 ; i < 1 << n ; ++ i)
   {
     cnt = 0;
     for (j = 0 ; j < n ; ++ j) if (i & (1 << j)) a[cnt ++] = j;
     j = -- cnt;
     f[i] = f[i & ~(1 << a[j])] + sqr(xx - x[a[j]]) + sqr(yy - y[a[j]]) + sqr(xx - x[a[j]]) + sqr(yy - y[a[j]]);
     p[i] = a[j];
     if (cnt)
     {
       for (k = 0 ; k < cnt ; ++ k)
       {
         v = f[i & ~(1 << a[j]) & ~(1 << a[k])] + sqr(xx - x[a[j]]) + sqr(yy - y[a[j]]) + sqr(xx - x[a[k]]) + sqr(yy - y[a[k]]) +
                                            sqr(x[a[k]] - x[a[j]]) + sqr(y[a[k]] - y[a[j]]);
         if (v < f[i]) f[i] = v , p[i] = 100000 + a[j] * 100 + a[k];
       }
     }
   }
   cout << f[(1 << n) - 1] << endl;
   print((1 << n) - 1);
   printf("0\n");
   return 0;
}