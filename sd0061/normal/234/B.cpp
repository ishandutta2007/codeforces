#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,k,num,ans[1005];
struct poo
{
  int w ,x;     
}a[1005];
int cmp(poo x, poo y)
{
  return x.w > y.w;  
}
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i ,j , x;  
  scanf("%d%d",&n,&k);
  for (i = 1 ;i <= n ;i ++)
    scanf("%d",&a[i].w) , a[i].x = i;
  sort(a + 1, a + n + 1,cmp);
  printf("%d\n",a[k].w);
  for (i = 1 ;i <= k ;i ++)
    ans[++ num] = a[i].x;
  sort(ans + 1, ans + num + 1);
  for (i = 1 ;i <= num;i ++)
    printf("%d ",ans[i]);
  return 0;        
}