#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 105
int n , a[N] , sx , sy , ex , ey , ans;
int f[N];
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i , j, x , y;
  cin >> n;
  for (i = 1 ; i <= n ;i ++)
    scanf("%d",&a[i]) , a[i] ++;
  scanf("%d%d%d%d",&sx,&sy,&ex,&ey);

  f[sx] = sy;
  for (i = sx + 1; i <= n ;i ++)
    f[i] = min(f[i - 1], a[i]); 
  for (i = sx - 1; i > 0 ;i --)
    f[i] = min(f[i + 1], a[i]); 
    
  ans = 1 << 30;
  for (i = 1 ; i <= n ;i ++)
  {
    y = abs(i - ex) + abs(i - sx);
    x = f[i];
    for (j = min(i , ex) ; j <= max(i , ex) ;j ++)
      if (a[j] < x)
        x = a[j];
    ans = min(ans , y + abs(ey - x));
  }   
  
  cout << ans << endl;      
  return 0;    
}