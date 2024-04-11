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
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define N 100005
int n , m , p;
int d[N] , q[N] , a[N];
LL s[N] , f[101][N];
LL B(LL i , LL k)
{
  return f[i - 1][k] + s[k];
}
long double K(LL i , LL j , LL k)
{
  LL y = B(i , k) - B(i , j) , x = k - j;
  return (long double)y / (long double)x;
}
LL F(int i , int j , int x)
{
  return (LL)-a[j] * x + f[i - 1][x] + s[x];
}

void work()
{
  int i , j , k , x , y;
  cin >> n >> m >> p;
  for (i = 2 ; i <= n ; ++ i)
    cin >> d[i] , d[i] += d[i - 1];
  for (i = 1 ; i <= m ; ++ i)
  {
    cin >> x >> y;
    a[i] = y - d[x];
  }
  sort(a + 1 , a + m + 1);
  for (i = 1 ; i <= m ; ++ i)
    s[i] = a[i] + s[i - 1];

  for (i = 1 ; i <= m ; ++ i) f[1][i] = (LL)a[i] * i - s[i];
  for (i = 2 ; i <= p ; ++ i)
  {
    int top = 0 , bot = 0; q[0] = 0;
    for (j = 1 ; j <= m ; ++ j)
    {
      while (top < bot && F(i , j , q[top + 1]) <= F(i , j , q[top]))
        ++ top;
      f[i][j] = F(i , j , q[top]) + (LL)j * a[j] - s[j];
      while (top < bot && K(i , q[bot - 1] , q[bot]) >= K(i , q[bot] , j))
        -- bot;
      q[++ bot] = j;
    }
  }
  cout << f[p][m] << endl;
}

int main()
{
  std::ios::sync_with_stdio(false);
  //while (~scanf("%d",&n))
    work();
  return 0;
}