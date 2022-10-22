#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;
int n , f[N] , l[N] , r[N], sum = 0;
bool g[N][N];

bool dfs(int x , int t)
{
  if (x == t) return 1;
  f[x] = 1 ;
  for (int y = 1 ; y <= sum ; ++ y) if (g[x][y] && !f[y])
    if (dfs(y , t))
      return 1;
  return 0;
}

int main()
{
  int i , j ;
  cin >> n;
  while (n --)
  {
    scanf("%d",&i);
    if (i == 1)
    {
      ++ sum , f[sum] = sum;
      cin >> l[sum] >> r[sum];
      for (i = 1 ; i < sum ; ++ i)
        if (l[sum] > l[i] && l[sum] < r[i] || r[sum] > l[i] && r[sum] < r[i])
          g[sum][i] = 1;
      for (i = 1 ; i < sum ; ++ i)
        if (l[i] > l[sum] && l[i] < r[sum] || r[i] > l[sum] && r[i] < r[sum])
          g[i][sum] = 1;
    }
    else
      cin >> i >> j , memset(f,  0 , sizeof(f)) , puts(dfs(i , j) ? "YES" : "NO");
  }
}