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
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
#define N 105
using namespace std;
int n , m ;
char g[N][N];
vector< pair<int , int> > ans , ans2;
bool f[N][N];

void work()
{
  int i , j;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%s" , g[i] + 1);
  for (i = 1 ; i <= n ; ++ i)
  {
    for (j = 1 ; j <= n ; ++ j)
      if (g[i][j] == '.')
      {
        ans.push_back(mp(i , j));
        break;
      }
    if (j > n){ m = 1 ; break;}
  }
  for (i = 1 ; i <= n ; ++ i)
  {
    for (j = 1 ; j <= n ; ++ j)
      if (g[j][i] == '.')
      {
        ans2.push_back(mp(j , i));
        break;
      }
    if (j > n){break;}
  }
  if (m == 1 && i <= n)
  {
    puts("-1");
  }
  else if (!m)
  {
    for (i = 0 ;i < n ; ++ i)
      printf("%d %d\n" , ans[i].first , ans[i].second);
  }
  else
  {
    for (i = 0 ;i < n ; ++ i)
      printf("%d %d\n" , ans2[i].first , ans2[i].second);
  }

}

int main()
{
  //while (scanf("%d%d%d%d%d",&p , &n , &m , &a , &b) , p)
    work();
  return 0;
}