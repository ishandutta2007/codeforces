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
#include <map>
#define pb push_back
#define mp make_pair
#define N 100002
using namespace std;
typedef long long LL;
//const LL Q = 1000000007LL;
int n , m ;LL a[N] , t[N];


void work()
{
  int i , j, x ;
  LL ans;
  for (i = 1 ; i <= n ;i ++)
    scanf("%I64d",&a[i]) , t[i] = a[i];
  x = -1; a[n + 1] = 1;
  for (i = 1 ; i <= n ;i ++)
    if (x == -1 || a[i] < a[x])
      x = i;
  j = a[x];
  x = m;
  while (1)
  {
    if (a[x] == j) break;
    if (x == 1) x = n;
    else  -- x;
  }
  for (i = 1 ; i <= n ;i ++)
    a[i] -= j;
  ans = (LL)(j) * n;
  j = x;
  while (1)
  {
    if (x == m) break;
    if (x == n) x = 1;
    else  ++ x;
    a[x] --;
    ++ ans;
  }
  a[j] = ans;
  for (i = 1 ; i <= n ;i ++)
    printf("%I64d ",a[i]);
}

int main()
{
  while(~scanf("%d%d",&n,&m)) work();
  return 0;
}