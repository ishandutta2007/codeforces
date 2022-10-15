#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
int a1,a2,a3,b1,b2,b3,a,b,n;
int main()
{
  scanf("%d %d %d",&a1,&a2,&a3);
  scanf("%d %d %d",&b1,&b2,&b3);
  a=a1+a2+a3;
  b=b1+b2+b3;
  scanf("%d",&n);
  if((a+4)/5+(b+9)/10>n) printf("NO"); else printf("YES");
  return 0;
}