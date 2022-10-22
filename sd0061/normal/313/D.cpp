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
#define N 305
int n , m , k;
LL c[N][N];
LL f[N][N];

void work()
{
  int i , j , x , y , z;
  cin >> n >> m >> k;
  for (i = 1 ; i <= n ; ++ i)
    for (j = i ; j <= n ; ++ j)
      c[i][j] = 1LL << 60;
  while (m --)
  {
    cin >> x >> y >> z;
    for (i = x ; i <= y ; ++ i)
      c[i][y] = min(c[i][y] , (LL)z);
  }
  for (i = 0 ; i <= n ; ++ i)
    for (j = 0 ; j <= k ; ++ j)
      f[i][j] = 1LL << 60;
  f[0][0] = 0;
  for (i = 1 ; i <= n ; ++ i)
    for (j = 0 ; j <= k && j <= i ; ++ j)
    {
      f[i][j] = f[i - 1][j];
      for (z = 0 ; z < i ; ++ z) if (j - i + z >= 0)
        f[i][j] = min(f[i][j] , f[z][j - i + z] + c[z + 1][i]);
    }
  if (f[n][k] == 1LL << 60)
    cout << -1 << endl;
  else cout << f[n][k] << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  //while (~scanf("%d",&n))
    work();
  return 0;
}