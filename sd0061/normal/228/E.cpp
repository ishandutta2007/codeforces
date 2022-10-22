#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define LL long long
#define N 205
int n , m , f[N] , u[N];
int a , b , c;

int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
void work()
{
  int i , x , y , z;
  scanf("%d%d",&n,&m);
  for (i = 1 ; i <= n << 1 ; ++ i) f[i] = i;
  for (i = 1 ; i <= m ; ++ i)
  {
    scanf("%d%d%d",&a,&b,&c);
    if (c)
    {
      f[getf(a)] = getf(b);
      f[getf(a + n)] = getf(b + n);
    }
    else
    {
      f[getf(a)] = getf(b + n);
      f[getf(a + n)] = getf(b);
    }
  }
  for (i = 1 ; i <= n ; ++ i)
    if (getf(i) == getf(i + n))
      break;
  if (i <= n)
  {
    puts("Impossible");
    return;
  }
  for (i = 1 ; i <= n << 1 ; ++ i)
    if (!u[getf(i)])
    {
      u[getf(i)] = 1;
      u[getf(i + n)] = 2;
    }
  if ((getf(a) + getf(b) + c) & 1)
  {
    x = 0;
    for (i = 1 ; i <= n ; ++ i)
      x += (u[getf(i)] == 2);
    cout << x << endl;
    for (i = 1 ; i <= n ; ++ i)
      if (u[getf(i)] == 2)
        cout << i << ' ';
  }
  else
  {
    x = 0;
    for (i = 1 ; i <= n ; ++ i)
      x += (u[getf(i)] == 1);
    cout << x << endl;
    for (i = 1 ; i <= n ; ++ i)
      if (u[getf(i)] == 1)
        cout << i << ' ';
  }
}

int main()
{
 // freopen("input.txt", "r" , stdin);
  //freopen("output.txt", "w" , stdout);
 // int _; scanf("%d",&_) ; while (_ --)
    work();
  return 0;
}