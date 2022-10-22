#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define N 100005
int n , k , a[N] , f[N] , sum;
int main()
{
  scanf("%d %d",&n,&k);
  for (int i = 1 ;i <= n ;i ++)
  {
    scanf("%d",&a[i]);
    if (!f[a[i]])
      sum ++ ;
    f[a[i]] ++;    
  }
  if (sum < k)
  {
    printf("-1 -1");
    return 0;      
  }
  int r = n;
  while (sum != k)
  {
    f[a[r]] --;
    if (!f[a[r]])
      sum --;
    r --;     
  }
  while (f[a[r]] > 1)
    f[a[r]] -- , r --;
  int l = 1;
  while (f[a[l]] > 1)
    f[a[l]] -- , l ++;
  printf("%d %d",l,r);  
  return 0;    
}