#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define N 200005
using namespace std;
typedef long long LL;

#define sqr(x) ((x)*(x))
int n , m , a[N] , r[N];
int ans[N] , tot;

struct node
{
  int a , r , n;
  bool operator < (const node& r) const{
    return a < r.a;}
}b[N];

void work()
{
  int i , j , x , y;
  scanf("%d",&n);
  for (i = 0 ; i < n ; ++ i)
    scanf("%d %d",&b[i].a , &b[i].r) , b[i].a -= b[i].r , b[i].n = i;
  sort(b , b + n);
  for (i = 0 ; i < n ; ++ i)
    a[i] = b[i].a , r[i] = b[i].r;
  scanf("%d",&m);
  memset(ans , -1 , sizeof(ans));
  for (j = 1 ; j <= m ; ++ j)
  {
    scanf("%d%d",&x , &y);
    if (x < a[0]) continue;
    if (x > a[n - 1] + r[n - 1] + r[n - 1]) continue;
    i = upper_bound(a , a + n , x) - a - 1;
    if (sqr(x - a[i] - r[i]) + sqr(y) <= sqr(r[i]))
      ans[b[i].n] = ~ans[b[i].n] ? ans[b[i].n] : j;
    if (y == 0 && i != 0)
    {
      if (a[i - 1] + r[i - 1] + r[i - 1] == x)
        ans[b[i - 1].n] = ~ans[b[i - 1].n] ? ans[b[i - 1].n] : j;
    }
  }
  for (i = 0 ; i < n ; ++ i) tot += (ans[i] != -1);
  printf("%d\n", tot);
  for (i = 0 ; i < n ; ++ i) printf("%d " , ans[i]);

}

int main()
{
  //int _;scanf("%d\n" , &_); while (_--)
  //while (cin >> k >> b >> n >> t)
    work();
  return 0;
}