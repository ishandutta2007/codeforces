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
#include <map>
#include <set>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 1005
int n , m;
LL A[N][N] , B[N][N] , C[N][N] , D[N][N];

void Update(int x , int y , LL w)
{
  if (x * y % 2)
  {
    for (int i = x ; i <= n ; i += i & -i)
      for (int j = y ; j <= n ; j += j & -j)
        A[i][j] ^= w;
  }
  if (y % 2)
  {
    for (int i = x ; i <= n ; i += i & -i)
      for (int j = y - 1 ; j > 0 ; j -= j & -j)
        B[i][j] ^= w;
  }
  if (x % 2)
  {
    for (int i = x - 1 ; i > 0 ; i -= i & -i)
      for (int j = y ; j <= n ; j += j & -j)
        C[i][j] ^= w;
  }
  for (int i = x - 1 ; i > 0 ; i -= i & -i)
    for (int j = y - 1 ; j > 0 ; j -= j & -j)
      D[i][j] ^= w;
}
LL Query(int x , int y)
{
  LL res = 0;
  for (int i = x ; i > 0 ; i -= i & -i)
    for (int j = y ; j > 0 ; j -= j & -j)
      res ^= A[i][j];
  if (x % 2)
  {
    for (int i = x ; i > 0 ; i -= i & -i)
      for (int j = y ; j <= n ; j += j & -j)
        res ^= B[i][j];
  }
  if (y % 2)
  {
    for (int i = x ; i <= n ; i += i & -i)
      for (int j = y ; j > 0 ; j -= j & -j)
        res ^= C[i][j];
  }
  if (x * y % 2)
  {
    for (int i = x ; i <= n ; i += i & -i)
      for (int j = y ; j <= n ; j += j & -j)
        res ^= D[i][j];
  }
  return res;
}


void work()
{
  int x1 , x2 , y1 , y2 , i;
  LL w;
  scanf("%d%d",&n,&m);
  ++ n;
  while (m --)
  {
    scanf("%d%d%d%d%d" , &i ,&x1 ,&y1 ,&x2 ,&y2);
    ++ x2 , ++ y2;
    if (i == 1)
    {
      w =  Query(x1 , y1);
      w ^= Query(x1 , y2);
      w ^= Query(x2 , y1);
      w ^= Query(x2 , y2);
      printf("%I64d\n" , w);
    }
    else
    {
      scanf("%I64d" , &w);
      Update(x1 , y1 , w);
      Update(x1 , y2 , w);
      Update(x2 , y1 , w);
      Update(x2 , y2 , w);
    }
  }
}

int main()
{
  work();
  return 0;
}