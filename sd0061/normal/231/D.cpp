#include <stdio.h>
#include <string.h>
int a[7],x,y,z;
int i,j,k,ans;

int main()
{
  //freopen("~input.txt","r",stdin);
 // freopen("~output.txt","w",stdout);
  scanf("%d%d%d",&i,&j,&k);
  scanf("%d%d%d",&x,&y,&z);
  scanf("%d%d%d",&a[1],&a[2],&a[3]);
  scanf("%d%d%d",&a[4],&a[5],&a[6]);
  if (j < 0)
    ans += a[1];
  if (j > y)
    ans += a[2];
  if (k < 0)
    ans += a[3];
  if (k > z)
    ans += a[4];
  if (i < 0)
    ans += a[5];
  if (i > x)
    ans += a[6];
  printf("%d",ans);
  return 0;  
}