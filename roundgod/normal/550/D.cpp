#include<cstdio>
int main()
{
    int k,i,j;
    scanf("%d",&k);
    if(k%2==0) 
    {
      printf("NO");
      return 0;
    }
    printf("YES\n");
    if(k==1)
    {
        printf("2 1\n");
        printf("1 2");
        return 0;
    }
    printf("%d %d\n",2*k+4,k*(k+2));
    for(i=2;i<=k+1;i++)
    printf("1 %d\n",i);
    for(i=k+2;i<=2*k;i++)
    printf("2 %d\n",i);
    for(i=3;i<=k+1;i++)
      for(j=3;j<=k+1;j++)
        if((i<j)&&i+j!=k+4)  printf("%d %d\n",i,j);
    for(i=k+2;i<=2*k;i++)
      for(j=k+2;j<=2*k;j++)
        if((i<j)&&i+j!=3*k+2)  printf("%d %d\n",i,j);
    for(i=3;i<=k+1;i++)
      {
        printf("%d %d\n",i,2*k+1);
        printf("%d %d\n",i,2*k+2);
        
      }
      for(i=k+2;i<=2*k;i++)
      {
        printf("%d %d\n",i,2*k+3);
        printf("%d %d\n",i,2*k+4);
      }
        printf("%d %d\n",2*k+1,2*k+2);
        printf("%d %d\n",2*k+3,2*k+4);
    return 0;
}