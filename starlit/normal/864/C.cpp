#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10005
#define ll long long
using namespace std;
ll a,b,f,k;
int pre[2];
int m,ans=0x3f3f3f3f,dp[N];
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&f,&k);
	if(a*k<=b)
    {puts("0");return 0;}
	for(int i=1;i<=k;i++)
	{
        if(2*(f*(i&1)+a*(i>>1))>b)break;
        pre[1]=i;
	}
	for(int i=1;i<=k;i++)
	{
        if(2*(a*((i+1)>>1)-f*(i&1))>b)break;
        pre[0]=i;
	}
	memset(dp,0x3f,sizeof dp);dp[0]=0;
	for(int i=1;i<=k;i++)
    if((i-1)*a+((i&1)?f:(a-f))<=b)
    dp[i]=1;
    else dp[i]=dp[max(1,i-pre[i&1])]+1;
    if(k&1)
    {
        for(int i=0;i<k;i++)
        {
            if(a*(i/2*2+1)+((i&1)?1:-1)*f>b)break;
            ans=dp[k-i];
        }
    }
    else
    {
        for(int i=0;i<k;i++)
        {
            if(a*((i+1)/2*2)+((i&1)?-1:1)*f>b)break;
            ans=dp[k-i];
        }
    }
    printf("%d",ans>=0x3f3f3f3f?-1:ans);
}