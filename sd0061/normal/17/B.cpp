#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#define N 1005
typedef long long LL;
using namespace std;
int n , m;
int g[N];
void work()
{
  int i , j , x , y , z , ans = 0 , cnt = 0;
  cin >> n;
  for (i = 1 ; i <= n ; ++ i)
      g[i] = 1 << 30 , scanf("%d" , &x);
  cin >> m;
  while (m --)
  {
    scanf("%d%d%d",&x,&y,&z);
    g[y] = min(g[y] , z);
  }

  for (i = 1 ; i <= n ; ++ i)
    if (g[i] == 1 << 30)
       ++ cnt;
    else ans += g[i];

  printf("%d\n" , cnt > 1 ? -1 : ans);
}


int main()
{
//  while (scanf("%d",&n) , n)
  //int _; cin >> _; while (_--)
    work();
  return 0;
}