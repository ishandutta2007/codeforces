#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define N 1005
#define sqr(x) ((long long)(x)*(x))
struct obj
{
  int x , y , t;
  double p;
  bool operator < (const obj& r) const{
    return t < r.t;}
}a[N];
int n;
double f[N] , ans;
int main()
{
   int i , j;
   scanf("%d",&n);
   for (i = 1 ; i <= n ; ++ i)
     scanf("%d%d%d%lf",&a[i].x,&a[i].y,&a[i].t,&a[i].p);
   sort(a + 1 , a + n + 1);
   for (i = 1 ; i <= n ; ++ i)
   {
     for (j = 1 ; j < i ; ++ j)
        if (sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y) <= sqr(a[i].t - a[j].t))
          f[i] = max(f[i] , f[j]);
     ans = max(ans , f[i] += a[i].p);
   }
   printf("%.15lf" , ans);
   return 0;
}