#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 105
int n,m,X,A,B,C;
struct team
{
  char s[25];
  int v;
}a[N],b[N][N];

int cmp(team x,team y)
{
  return x.v > y.v;  
}

int ra()
{
  return X = (A * X + B) % C; 
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i , j ,k , x ,y;  
  scanf("%d%d%d%d%d\n",&n,&X,&A,&B,&C);
  for (i = 1 ; i <= n ;i ++)
    scanf("%s %d\n",a[i].s,&a[i].v);
  sort(a + 1 , a + n + 1,cmp);
  m = n >> 2;
  for (i = 1 ; i <= 4 ;i ++)
    for (j = 0 ;j < m ;j ++)
      b[i][j] = a[(i - 1) * m + j + 1];
  for (i = m,y = 0 ; i >= 1 ;i --,y ++)
  {
    printf("Group %c:\n",'A' + y);  
    for (j = 1 ;j <= 4 ;j ++)  
    {
      x = ra() % i;
      printf("%s\n",b[j][x].s);
      for (k = x ; k < m ; k ++)
        b[j][k] = b[j][k + 1];
    }
  }    
  return 0;  
}