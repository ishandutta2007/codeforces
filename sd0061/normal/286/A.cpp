#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
#define N 100005
#define M 100005
#define LL long long
int n , a[N];

void work()
{
  int i , x , y , l , r;
  scanf("%d",&n);
  x = n / 2 ;
  if (n & 1) a[x + 1] = x + 1;
  for (i = 1 ; i <= x ; ++ i)
    if (!a[i])
    {
      y = i == x ? 1 : i + 1;
      a[i] = y , a[n - i + 1] = n - y + 1;
      a[y] = n - i + 1 , a[n - y + 1] = i;
    }
  for (i = 1 ; i <= n ;i ++)
    if (a[a[i]] != n - i + 1)
      break;
  if (i <= n) puts("-1");
  else
  for (i = 1 ; i <= n ;i ++)
    printf("%d ", a[i]);
}


int main()
{
    work();
  return 0;
}