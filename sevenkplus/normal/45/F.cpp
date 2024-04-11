#include<cstdio>
#include<cstdlib>
#include<cstring>
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  if(m==1)
  {
    printf("-1\n");return 0;
  }else
  if(m==2)
  {
    if(n==1)printf("1\n");else
    if(n==2)printf("5\n");else
    if(n==3)printf("11\n");else printf("-1\n");
    return 0;
  }else
  if(m==3)
  {
    if(n==1)printf("1\n");else
    if(n==2)printf("3\n");else
    if(n==3)printf("5\n");else
    if(n==4)printf("9\n");else
    if(n==5)printf("11\n");else printf("-1\n");
    return 0;
  };
  if(n==1)
  {
    printf("1\n");return 0;
  }
  if(m&1)
  {
    if(n<=(m/2-1)+1)printf("1\n");else
    if(n<=(m/2-1)*2+2)printf("3\n");else
    if(n<=(m/2-1)*3+2)printf("5\n");else
    if(n<=(m/2-1)*4+3)printf("7\n");else printf("%d\n",(n-4)/(m/2-1)*2+1);
  }else printf("%d\n",(n-2)/(m/2-1)*2+1);
}