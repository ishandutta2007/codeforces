#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 100005
int n , m;
int len[N] , ansx , ansy ;  
double d[N], y[N] , yy[N] , a , b , ans = 1e10;
double dis(double q , double w ,double e ,double r)
{
  return sqrt((q - e) * (q - e) + (w - r) * (w - r));   
}

int main()
{
  int i , j ; double x, q , w;
  scanf("%d%d%lf%lf",&n,&m,&a,&b);
  for (i = 1 ;i <= n ; i ++)
    scanf("%lf",&yy[i]) , d[i] = dis(0,0,a,yy[i]);
  for (i = 1 ;i <= m ; i ++)
    scanf("%lf",&y[i]);
  for (i = 1 ;i <= m ; i ++)
    scanf("%d",&len[i]);
  
  for (i = 1 ; i <= m ;i ++)
  {
    x = dis(0,0,b,y[i]);
    int l = 1 , r = n , x1 , x2;
    while (l + 1 < r)
    {
      x1 = (2 * l + r) / 3 , x2 = (l + 2 * r) / 3;
      q = d[x1] + dis(a,yy[x1],b,y[i]);
      w = d[x2] + dis(a,yy[x2],b,y[i]);
      if (q <= w)
        r = x2;
      else l = x1 + 1;  
    }  
    q = d[l] + dis(a,yy[l],b,y[i]) + double(len[i]);
    if (q < ans)
      ans = q , ansx = l , ansy = i;
    w = d[r] + dis(a,yy[r],b,y[i]) + double(len[i]);
    if (w < ans)
      ans = w , ansx = r , ansy = i;
  }    
  cout << ansx << ' ' << ansy;
  return 0;    
}