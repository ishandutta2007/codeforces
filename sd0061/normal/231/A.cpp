#include <stdio.h>
#define N 1005
int ans,n;
int main()
{
  //freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout); 
  int i , j , x , y;    
  scanf("%d",&n);
  for (i = 1 ; i <= n ;i ++)
  {
    x = 0;
    for (j = 1 ;j <= 3 ;j ++)
    {
      scanf("%d",&y);
      if (y)
        x ++;
    }  
    if (x > 1)
      ans ++;
  }  
  printf("%d",ans);
  return 0;
}