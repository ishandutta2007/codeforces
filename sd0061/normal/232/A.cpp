#include <stdio.h>
#include <string.h>
int n,m,l,k,s;
bool a[201][201];

void work(int q,int m)
{
  int i ,j;   
  s = 0;
  for (n = 3 ;n <= 100 ;n ++)
  {
    s += (n - 1) * (n - 2) / 2 ;
    if (s > q) 
    {
      s -= (n - 1) * (n - 2) / 2 ;
      break;    
    }
  }
  n --;
  l = q - s;
  for (i = 1 ;i <= n ;i ++)
    for (j = i + 1 ;j <= n ;j ++)
      a[i][j] = a[j][i] = 1;
  while (l)
  {
    for (i = 1 ; i <= n; i ++)
      if (i * (i - 1) / 2 <= l && i * (i + 1) / 2 > l)
      {
        l -= i * (i - 1) / 2;
        n ++;
        for (j = 1 ; j <= i ;j ++)
          a[j][n] = a[n][j] = 1;
        break;      
      }      
  }    
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