#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define LL long long
#define N 100005
int a[102][2] , n , m;
int f[3002][102][2] , Q = 1e9 + 7 , d[202];
vector< int > e[102];

void work()
{
  int i , j , k , x , y;
  scanf("%d%d",&n,&m);
  for (i = 0 ; i < n ; ++ i)
    scanf("%d%d",&a[i][0] , &a[i][1]);
  for (i = 0 ; i < n ; ++ i)
    f[ a[i][0] ][i][0] = 1 ,  f[ a[i][1] ][i][1] = 1;

  for (k = 0 ; k <= m ; ++ k)
    for (i = 0 ; i < n ; ++ i)
      for (j = 0 ; j < n ; ++ j)
        if (i != j)
        {
          if (a[i][0] == a[j][1] && k - a[i][0] >= 0)
            f[k][i][0] += f[k - a[i][0]][j][0] , f[k][i][0] %= Q;
          if (a[j][0] != a[j][1] && a[i][0] == a[j][0] && k - a[i][0] >= 0)
            f[k][i][0] += f[k - a[i][0]][j][1] , f[k][i][0] %= Q;
            
          if (a[i][1] == a[j][1] && k - a[i][1] >= 0)
            f[k][i][1] += f[k - a[i][1]][j][0] , f[k][i][1] %= Q;
          if (a[j][0] != a[j][1] && a[i][1] == a[j][0] && k - a[i][1] >= 0)
            f[k][i][1] += f[k - a[i][1]][j][1] , f[k][i][1] %= Q;
        }
  int ans = 0;
  for (i = 0 ; i < n ; ++ i)
  {
    ans += f[m][i][0] , ans %= Q ;
    if (a[i][0] != a[i][1])
      ans += f[m][i][1] , ans %= Q;
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}