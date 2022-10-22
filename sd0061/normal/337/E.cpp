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
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 15

int n , sum[N] , t[N] , f[N];
LL a[N] , b[N] , ans = 1 << 30;

void dfs(int k , int tot)
{
  if (k > n)
  {
    if (!tot) return;
    LL cnt = n;
    if (tot > 1) ++ cnt;
    for (int i = 1 ; i <= n ; ++ i)
      cnt += t[i];
    ans = min(ans , cnt);
    return;
  }
  dfs(k + 1 , tot + 1);
  for (int i = k + 1 ; i <= n ; ++ i)
    if (b[i] % a[k] == 0)
    {
      b[i] /= a[k] , t[i] -= max(sum[k] , 1) , f[k] = i;
      dfs(k + 1 , tot);
      b[i] *= a[k] , t[i] += max(sum[k] , 1);
    }
}

void work()
{
  int i , j;
  cin >> n;
  for (i = 1 ; i <= n ; ++ i)
    cin >> a[i];
  sort(a + 1 , a + n + 1);
  for (i = 1 ; i <= n ; ++ i)
  {
    LL x = a[i]; int y = 0;
    for (j = 2 ; (LL)j * j <= x ; ++ j)
      while (x % j == 0)
        x /= j , ++ y;
    if (x > 1) ++ y;
    if (y == 1) y = 0;
    sum[i] = y;
  }
  memcpy(t , sum , sizeof(t));
  memcpy(b , a , sizeof(b));

  dfs(1 , 0);
  cout << ans << endl;
}

int main()
{
//  freopen("~input.txt","r",stdin);
  //while (~scanf("%d",&n))
    work();
  return 0;
}