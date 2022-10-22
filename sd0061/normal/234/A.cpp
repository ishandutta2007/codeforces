#include <stdio.h>
#include <string.h>
#define N 105
int n ,re[N],ans;
char c;
bool g[N][N], f[N], a[N], d[N];

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
    
  int i,j;  
  scanf("%d\n",&n);
  for (i = 0 ;i < n; i ++)
  {
    c = getchar();
    a[i] = c == 'L' ? 1 : 0;  
  }  
  
  for (i = 0 ;i < n / 2;i ++)
    if (a[i] == 0 && a[i + n / 2] == 1)
      printf("%d %d\n",i + 1 + n / 2,i + 1);
    else  printf("%d %d\n",i + 1,i + n / 2 + 1);  
  return 0;    
}