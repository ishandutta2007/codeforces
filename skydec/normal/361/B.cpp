#include<stdio.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==k)
    {
            printf("-1");
            return 0;
            }
    for(int i=1;i<=n-k-1;i++)printf("%d ",i+1);
    printf("1 ");
    for(int i=n-k+1;i<=n;i++)printf("%d ",i);
    return 0;
}