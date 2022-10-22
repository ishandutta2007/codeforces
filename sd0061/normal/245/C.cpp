#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n ,a[N], ans;
int main()
{
  int i , j, x;
  cin >> n;
  for (i = 1 ;i <= n ;i ++)
    cin >> a[i];
  if (n <= 2 || n % 2 == 0)
  {
    printf("-1");
    return 0;    
  }
  for (i = n ;i >= 3 ;i --)
  if (a[i])
  {
    if (i & 1)
    {
      x = (i - 1) >> 1;
      ans += a[i];
      a[i - 1] -= a[i] , a[x] -= a[i];
      if (a[i - 1] < 0) a[i - 1] = 0;
      if (a[x] < 0) a[x] = 0;    
      a[i] = 0;       
    }  
    else
    {
      x = i >> 1;
      ans += a[i];
      a[x] -= a[i];
      if (a[x] < 0) a[x] = 0;  
      a[i] = 0;         
    }
  }  
  for (i = 1 ; 2 * i + 1 <= n ;i ++)
    if (a[i])
    {
      ans += a[i];
      a[2 * i] -= a[i] , a[2 * i + 1] -= a[i];
      if (a[2 * i] < 0) a[2 * i] = 0;
      if (a[2 * i + 1] < 0) a[2 * i + 1] = 0; 
      a[i] = 0;       
    }
  for (i = 1 ; i <= n ;i ++)
    if (a[i])
    {
      printf("-1");
      return 0;    
    }        
  printf("%d",ans);  
  return 0;    
}