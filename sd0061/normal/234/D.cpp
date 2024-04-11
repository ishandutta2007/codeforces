#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 105
int n , m , k , ans[N], win[N], lose[N];
int low[N], up[N];
bool f[N];char s[N];

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i ,j ,y , x ,s1 , s2, s3;
  scanf("%d %d\n",&m,&k);
  for (i = 1 ;i <= k ;i ++)
    scanf("%d",&x) , f[x] = 1;
  scanf("%d\n",&n);
  for (i = 1 ;i <= n ;i ++)
  {
    scanf("%s\n%d",s,&y);
    s1 = s2 = s3 = 0;
    while (y --)
    {
      scanf("%d",&x);
      if (f[x] && x != 0)
        low[i] ++ , up[i] ++, s1 ++;
      else if (x == 0)
        s3 ++;
      else s2 ++;        
    }  
    if (s2 == m - k)
      low[i] += s3, up[i] += s3;     
    else
    {
      if (m - k - s2 < s3)
        low[i] += s3 - m + k + s2;
      up[i] += min(k - s1, s3);      
    }
  //  printf("%d %d\n",low[i],up[i]);
  }  
  x = 0,y = 0;
  for (i = 1 ;i <= n ;i ++)
    x = max(x, up[i]),y = max(y, low[i]);
    
  for (i = 1 ;i <= n ;i ++)
  {
    for (j = 1 ; j <= n ;j ++)
      if (i != j)
        if (low[i] < up[j])
          break;
    if (j > n)
    {
      ans[i] = 0;  
      continue; 
    }
    for (j = 1 ; j <= n ;j ++)
      if (i != j)
        if (up[i] < low[j])
          break;
    if (j > n)
    {
      ans[i] = 2;  
      continue; 
    }
    ans[i] = 1;               
  } 
 
  for (i = 1 ;i <= n;i ++)
    printf("%d\n",ans[i]);        
  return 0;
}