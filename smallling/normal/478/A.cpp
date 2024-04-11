#include<cstdio>

int a1,a2,a3,a4,a5,sum;

int main()
{
    scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
    sum=a1+a2+a3+a4+a5;
    if(sum==0)return printf("-1"),0;
    printf("%d",sum%5?-1:sum/5);
}