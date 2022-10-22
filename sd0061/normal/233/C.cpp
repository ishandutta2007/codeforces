#include <stdio.h>
#include <string.h>
int n,m,l,k,s;
bool a[201][201];

int work(int q,int m)
{
  int i ,j, x;   
  s = 0;
  for (x = 3 ;x <= 100 ;x ++)
  {
    s += (x - 1) * (x - 2) / 2 ;
    if (s > q) 
    {
      s -= (x - 1) * (x - 2) / 2 ;
      break;    
    }
  }
  x --;
  l = q - s;
  for (i = m + 1 ;i <= m + x ;i ++)
    for (j = i + 1 ;j <= m + x ;j ++)
      a[i][j] = a[j][i] = 1;
  while (l)
  {
    for (i = 1 ; i <= x; i ++)
      if (i * (i - 1) / 2 <= l && i * (i + 1) / 2 > l)
      {
        l -= i * (i - 1) / 2;
        x ++;
        for (j = m + 1 ; j <= m + i ;j ++)
          a[j][n + x] = a[n + x][j] = 1;
        break;      
      }      
  }    
  n += x; 
 // while (l)
  //  work(l,n);

  return l;  
}

int main()
{
  int i , j;  
  scanf("%d",&k);
  work(k, 0);
  printf("%d\n",n);
  for (i = 1 ;i <= n ;i ++)
  {
    for (j = 1 ;j <= n ;j ++)
      printf("%d",a[i][j]);
    printf("\n");  
  }
  return 0;        
}