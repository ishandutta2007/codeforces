#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define N 1005
int m , a[15] , cnt[15];
LL dp[15][2][15] , Q = 1e9 + 7 , ans;

void dfs(int pos, int sum, LL x)
{
  if (pos == 7)
  {
    if (sum > 0)
      ans += x , ans %= Q;
    return;
  }
  for (int i = 0 ; i < 10 ; ++ i)
    if (cnt[i])
    {
      LL y = x * cnt[i] % Q;
      -- cnt[i];
      if (pos == 0)
        dfs(pos + 1 , sum + i , y);
      else dfs(pos + 1 , sum - i , y);
      ++ cnt[i];
    }
}

void work()
{
  int i , j , k , l;
  scanf("%d",&m);
  ++ m;
  for (i = 0 ; i < 10 ; ++ i)
    a[i] = m % 10 , m /= 10;
  reverse(a , a + 10);

  dp[0][0][0] = 1;
  for (i = 0 ; i < 10 ; ++ i)
    for (j = 0 ; j < 2 ; ++ j)
      for (k = 0 ; k < 10 ; ++ k) if (dp[i][j][k])
      {
        if (j == 1)
        {
          dp[i + 1][j][k + 1] += dp[i][j][k] * 2 , dp[i + 1][j][k + 1] %= Q;
          dp[i + 1][j][k] += dp[i][j][k] * 8 , dp[i + 1][j][k] %= Q;
        }
        else
        {
          for (l = 0 ; l < a[i] ; ++ l)
          {
            dp[i + 1][1][k + (l == 4 || l == 7)] += dp[i][j][k];
            dp[i + 1][1][k + (l == 4 || l == 7)] %= Q;
          }
          dp[i + 1][0][k + (l == 4 || l == 7)] += dp[i][j][k];
          dp[i + 1][0][k + (l == 4 || l == 7)] %= Q;
        }
      }
  for (i = 0 ; i < 10 ; ++ i)
    cnt[i] = dp[10][1][i];
  cnt[0] = (cnt[0] - 1 + Q) % Q;
  dfs(0 , 0 , 1);
  cout << ans << endl;
}

int main()
{
  //freopen("1.txt" , "r" , stdin);
  work();
  return 0;
}