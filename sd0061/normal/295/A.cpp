#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#define N 100005
typedef long long LL;
using namespace std;
int n , m , k ;
LL a[N];
int s[N] , c[N];
struct ope
{
  int l , r , w;
}b[N];

int work()
{
  int i , x , y;
  scanf("%d%d%d",&n,&m,&k);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d",&c[i]);
  for (i = 1 ; i <= n ; ++ i)
    a[i] = c[i] - c[i - 1];
  for (i = 1 ; i <= m ; ++ i)
    scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].w);
  for (i = 1 ; i <= k ; ++ i)
  {
    scanf("%d%d",&x,&y);
    ++ s[x] , -- s[y + 1];
  }
  LL p = 0;
  for (i = 1 ; i <= m ; ++ i)
  {
    p += s[i];
    a[b[i].l] += (LL) b[i].w * p;
    a[b[i].r + 1] -= (LL) b[i].w * p;
  }
  p = 0;
  for (i = 1 ; i <= n ; ++ i)
  {
    p += a[i];
    printf("%I64d " , p);
  }
}

int main()
{
  //int _;cin>>_;while(_--)
  //while (~scanf("%d%d%d",&n,&m,&Q))
    work();
  //printf("%d" ,kase );
  return 0;
}