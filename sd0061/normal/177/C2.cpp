#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#define N 100005
using namespace std;
typedef long long LL;

int n , m;
int f[N] , s[N] , ans;
bool u[N];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}

void work()
{
  int i , x , y;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i) f[i] = i , s[i] = 1;
  while (m --)
  {
    scanf("%d%d",&x,&y);
    x = getf(x) , y = getf(y);
    if (x != y)
      f[x] = y , s[y] += s[x];
  }
  scanf("%d",&m);
  while (m --)
  {
    scanf("%d%d",&x,&y);
    x = getf(x) , y = getf(y);
    if (x == y)
      u[x] = 1;
  }
  for (i = 1 ; i <= n ; ++ i) if (i == getf(i) && !u[i])
    ans = max(ans , s[i]);
  printf("%d",ans);

}

int main()
{
    work();
  return 0;
}