#include <stdio.h>
#define N 1005
int n,s,x[N],y[N],ans;
bool f[N];

int main()
{ 
  int i ,j ,w;
  scanf("%d %d",&s,&n);
  for (i = 1 ;i <= n; i ++ )
    scanf("%d %d",&x[i],&y[i]);
  for (i = 1 ;i <= n ;i ++)
    for (j = 1 ;j <= n ;j ++)
      if (!f[j] && s > x[j])
        f[j] = 1 , s += y[j] , ans ++;  
  if (ans != n)
    printf("NO");
  else printf("YES");
  return 0;  
}