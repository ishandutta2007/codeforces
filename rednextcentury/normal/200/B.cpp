#include<stdio.h>
int main()
{
  int n;
  int p,i;
  float sum=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
        {scanf("%d",&p);
    sum+=p;
            }
sum=sum/n;
printf("%f",sum);
}