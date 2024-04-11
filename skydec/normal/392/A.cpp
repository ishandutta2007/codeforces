#include<stdio.h>
#include<cmath>
using namespace std;
int n;
int ans=0;
int check(int x)
{
    return (int)sqrt(n*1ll*n-x*1ll*x);
}
int main()
{
    scanf("%d",&n);
    ans=2*n;
    for(int i=1;i<=n;i++)if(check(check(i))==i)ans--;
    if(n)
    printf("%d\n",ans*4);else printf("1");
    return 0;
}