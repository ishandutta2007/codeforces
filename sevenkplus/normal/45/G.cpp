#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int pr(int n)
{
    if(n<2)return 0;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return 0;
    return 1;
}
int ff2(int n)
{
    int r=n*(n+1)/2;
    for(int i=2;i<=r-2;i++)
        if(pr(i)&&pr(r-i))
        {
            for(int j=1;j<=n;j++)
                if(j==1||j==i-1)printf("1 ");else printf("2 ");
            return 0;
        }
    printf("-1");
}
int ff3(int n)
{
    int r=n*(n+1)/2;
    if(r>2&&pr(r-2))
    {
        for(int i=1;i<=n;i++)
            printf("%d ",i==2?2:1);
        return 0;
    }
    for(int i=3;i<200;i++)
        if(pr(i)&&i<n)
            for(int j=2;j<=r-i-2;j++)
                if(pr(j)&&pr(r-i-j))
                {
                    int a=0,b=0;
                    for(int k=1;k<j;k++)if(k!=i&&j-k!=i)
                    {
                        a=k;b=j-k;break;
                    }
                    if(a==0||b==0)continue;
                    for(int k=1;k<=n;k++)
                    {
                        if(k==i)printf("1 ");else
                            if(k==a||k==b)printf("2 ");else
                                printf("3 ");
                    }
                    return 0;
                }
    printf("-1");
}
int main()
{
    int n;
    scanf("%d",&n);
    int r=n*(n+1)/2;
    if(pr(r)){for(int i=1;i<=n;i++)printf("1 ");return 0;}
    if(r&1)ff3(n);else ff2(n);
}