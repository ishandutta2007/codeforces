#include <stdio.h>
#define N 1005
int n , d , l ,s1 , s2 ,w , t;
int a[N];
bool f;
int cal(int m , int sum)
{
  int i , j , x ,y;
  for (i = 2 ; i <= l  ;i ++)
    if ((sum - m) % (i - 1) == 0)
    {
      y = (sum - m) / (i - 1);
      x = m - y;
      if (x >= 0 && y >= 0)
      {  
        w = i;    
        return y;
      }         
    }
  return -1;  
}

int main()
{
  int x,y,i,j;
  scanf("%d %d %d",&n,&d,&l);
  x = ((n + 1) >> 1) * l;
  y = (n >> 1);
  if (x - y < d)
  {
    printf("-1");
    return 0;    
  }  
  
  for (x = ((n + 1) >> 1) ; x <= ((n + 1) >> 1) * l ; x ++)
    if (x - d >= (n >> 1) && x - d <= (n >> 1) * l)
    {
      y = x - d;
      if (x == (n + 1) >> 1)
        s1 = 0;
      else s1 = cal((n + 1) >> 1, x);
      if (s1 == -1)
        continue;
      t = w;  
      if (y == n >> 1)
        s2 = 0;
      else s2 = cal(n >> 1, y);
      if (s2 == -1)
        continue;
      f = 1;  
      break;  
    }
  if (!f)
  {
    printf("-1");
    return 0;     
  }  
  for (i = 1 ;i <= n ;i += 2)
    if (s1 > 0)
      a[i] = t , s1 --;
    else a[i] = 1;  

  for (i = 2 ;i <= n ;i += 2)
    if (s2 > 0)
      a[i] = w , s2 --;
    else a[i] = 1;
    
  for (i = 1 ;i <= n ;i ++)
    printf("%d ",a[i]);
  return 0;   
}