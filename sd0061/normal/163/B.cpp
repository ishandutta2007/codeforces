#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define N 100005
int n , k , h;
struct node
{
  int m , v , o;
  bool operator < (const node& r) const
  {
    if (m == r.m) return v < r.v;
    return m < r.m;
  }
}a[N];
int ans[N], p[N];
bool check(double val)
{
  int x = 0;
  for (int i = 1 ; i <= n ; ++ i)
    if (a[i].v * val >= (double)(x + 1) * h)
      ans[++ x] = a[i].o;
  return x >= k;
}

int main()
{
   int i , j , x , y;
   scanf("%d%d%d",&n,&k,&h);
   for (i = 1 ; i <= n ; ++ i)
      scanf("%d",&a[i].m) , a[i].o = i;
   for (i = 1 ; i <= n ; ++ i)
      scanf("%d",&a[i].v);
   sort(a + 1 , a + 1 + n);
   double l = 0 , r = (double) h * k , mid;
   y = 100;
   while (y --)
   {
     if (check((l + r) * 0.5))
        r = (l + r) * 0.5 , memcpy(p , ans , sizeof(p));
     else l = (l + r) * 0.5;
   }
   for (i = 1 ; i <= k ; ++ i)
      printf("%d " , p[i]);
   return 0;
}