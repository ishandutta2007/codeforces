#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 202
using namespace std;
int n , m , f[N] , a[N] , ans;
int getf(int x) {return f[x] == x ? x : f[x] = getf(f[x]);}
void work()
{
  int i , x , y;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n + m ; ++ i) f[i] = i;
  for (i = 1 ; i <= n ;i ++)
  {
    scanf("%d",&y);
    while (y --)
      scanf("%d",&x) , f[getf(i)] = getf(x + n);
  }
  int sum = 0;
  for (i = 1 ; i <= n ;i ++)
    if (getf(i) == i)
      ++ ans;
    else a[sum ++] = getf(i);
  if (sum)
    sort(a , a + sum) , ans += unique(a , a + sum) - a - 1;
  printf("%d",ans);
}

int main()
{
  work();
  return 0;
}