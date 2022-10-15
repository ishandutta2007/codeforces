#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        printf("2\n1 1");
        return 0;
    }
    if(n%2==0)
    {
        printf("%d\n",n+n/2);
        for(int i=1;i<=n/2;i++)
            printf("%d %d ",i*2,i*2-1);
        for(int i=1;i<=n/2;i++)
            printf("%d ",i*2);
    }
    else
    {
        printf("%d\n",(n-1)+(n-1)/2+1);
        for(int i=1;i<=(n-1)/2;i++)
            printf("%d %d ",i*2,i*2-1);
        printf("%d ",n);
        for(int i=1;i<=n/2;i++)
            printf("%d ",i*2);
    }
    return 0;
}