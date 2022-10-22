#include <stdio.h>
int main()
{
  int m,n,a;
  long long ans,ans2;
  scanf("%d%d%d",&m,&n,&a);
  
  ans = m / a;
  if (m % a != 0)
    ans ++;
  ans2 = n / a;
  if (n % a != 0)
    ans2 ++;
  printf("%I64d",ans*ans2);
  //getchar();getchar();
  return 0;  
}