#include <stdio.h>
#include <string.h>
#define N 1005
int n;
int ans[15][N];
void work(int d,int l,int r)
{
  if (l == r)
    return;
  int m = (l + r) >> 1;
  for (int i = l ; i <= m ;i ++)
    ans[d][++ ans[d][0]] = i;
  work(d + 1 , l , m);
  work(d + 1 , m + 1 , r);       
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int x;
  scanf("%d",&n);
  work(1,1,n);  
  for (x = 1 ; ans[x][0];x ++); x --;
  printf("%d",x);
  for (int i = 1 ;i <= x ; i ++)
    if (ans[i][0])
    {
      printf("\n%d ",ans[i][0]);
      while (ans[i][0])
        printf("%d ",ans[i][ans[i][0] --]);            
    } 
  return 0;  
}