#include<stdio.h>
#include<cstring>
#define jsb 1000000007
using namespace std;
int n,k;int ans=0;
int Pow(int a,int b)
{
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%jsb)
    if(b&1)c=c*1ll*a%jsb;
    return c;
}
int main()
{
    scanf("%d%d",&n,&k);ans=1;
    ans=ans*1ll*Pow(n-k,n-k)%jsb;
    ans=ans*1ll*Pow(k,k-1)%jsb;
    printf("%d\n",ans);
    return 0;
}