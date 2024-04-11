#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define N 1005
int n;
int a[N] , b[N] , p[N];
int cnt , ans[N];

void work()
{
  int i , w , e , r , t , f , g , h , j;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d%d%d",&p[i] , &a[i] , &b[i]);

  for (w = 0 ; w < 10 ; ++ w)
    for (e = 0 ; e < 10 ; ++ e) if (w != e)
      for (r = 0 ; r < 10 ; ++ r) if (r != w && r != e)
        for (t = 0 ; t < 10 ; ++ t) if (t != w && t != e && t != r)
        {
          if (w == 2 && e == 1 && r == 3 && t == 4)
                ++ w , -- w;
          for (i = 1 ; i <= n ; ++ i)
          {
            int o = 0 , u = 0;
            f = p[i] / 1000 , g = p[i] / 100 % 10 , h = p[i] / 10 % 10 , j = p[i] % 10;
            if (f == w)
              ++ o;
            else if (f == e || f == r || f == t)
              ++ u;
            if (g == e)
              ++ o;
            else if (g == w || g == r || g == t)
              ++ u;
            if (h == r)
              ++ o;
            else if (h == e || h == w || h == t)
              ++ u;
            if (j == t)
              ++ o;
            else if (j == e || j == r || j == w)
              ++ u;
            if (a[i] != o || b[i] != u) break;
          }
          if (i > n) ans[cnt ++] = w * 1000 + e * 100 + r * 10 + t;
        }
   if (cnt == 1)
     printf("%04d\n" , ans[0]);
   else if (cnt > 1)
     puts("Need more data");
   else puts("Incorrect data");
}

int main()
{
  work();
  return 0;
}