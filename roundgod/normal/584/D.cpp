#include<cstdio>
#include<cmath>
int main()
{
int n,i,f;
scanf("%d",&n);
if(n==3||n==5||n==7)
{
printf("1\n");
printf("%d",n);
return 0;
}
printf("3\n");
printf("3");
n=n-3;
int prime(int x);
for(i=3;i<=n/2;i=i+2)
  if(prime(i)&&prime(n-i))
  {
   printf(" %d %d",i,n-i);
   return 0;
  }
return 0;
}
int prime(int x)
{
  int j;
  for(j=3;j*j<=x;j++)
    if(x%j==0) return 0;
  return 1;
}