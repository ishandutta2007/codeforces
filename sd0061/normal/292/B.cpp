#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
#define N 100005
int n , m;
vector<int> e[N];
int d[N];
int f[N] , sum ;
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}

void work()
{
  int i , x , y;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n ; ++ i)
    f[i] = i;
  sum = n;
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%d%d",&x,&y);
    ++ d[x] , ++ d[y];
    f[getf(x)] = getf(y);
  }
  for (i = 1 ; i <= n ; ++ i)
    if (getf(i) != getf(1))
      break;
  if (i <= n)
  {
    puts("unknown topology");
    return;
  }

  for (i = 1 ; i <= n ; ++ i)
    if (d[i] != 2)
      break;
  if (i > n)
  {
    puts("ring topology");
    return;
  }

  int s1 = 0 , s2 = 0;
  for (i = 1 ; i <= n ; ++ i)
    if (d[i] == 1)
      ++ s1;
    else if (d[i] == 2) ++ s2;
  if (s1 == 2 && s2 == n - 2)
  {
    puts("bus topology");
    return;
  }
  s1 = 0 , s2 = 0;
  for (i = 1 ; i <= n ; ++ i)
    if (d[i] == 1)
      ++ s1;
    else if (d[i] == n - 1) ++ s2;
  if (s1 == n - 1 && s2 == 1)
  {
    puts("star topology");
    return;
  }
  puts("unknown topology");
}

int main()
{
    work();
  return 0;
}