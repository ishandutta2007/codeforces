#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define p 1000000007
using namespace std;

int n,i,j,k;
long long pow2[100005],pow4[100005],pow7[100005],pow10[100005];
long long sum[100005],f[100005];
long long ans,ansl,ansr,tmp;
char s[100005];

long long calc()
{
	n=strlen(s+1);
	ans=tmp=0;
	for(i=1;i<n;++i)ans+=f[i]+pow7[i]*pow4[i+1]%p;
	for(i=n;i>=1;--i)
	if(s[n-i+1]=='7')
	{
		ans+=f[i-1]%p;
		tmp=(tmp+4*pow10[i-1])%p;
		ans+=2*tmp*sum[i-1]%p+p-tmp*(pow4[i-1]+pow7[i-1])%p;
		ans+=tmp*tmp%p*(pow2[i-1]+p-1)%p;
		ans+=(tmp+pow7[i-1])%p*(tmp+3*pow10[i-1]%p+pow4[i-1])%p;
		tmp=(tmp+3*pow10[i-1])%p;
	}else tmp=(tmp+4*pow10[i-1])%p;
	return ans%p;
}

int main()
{
	pow2[0]=pow10[0]=1;
	for(i=1;i<=100000;++i)pow2[i]=pow2[i-1]*2%p;
	for(i=1;i<=100000;++i)pow4[i]=(pow4[i-1]*10+4)%p;
	for(i=1;i<=100000;++i)pow7[i]=(pow7[i-1]*10+7)%p;
	for(i=1;i<=100000;++i)pow10[i]=pow10[i-1]*10%p;
	for(i=1;i<=100000;++i)sum[i]=(2*sum[i-1]+11*pow2[i-1]%p*pow10[i-1]%p)%p;
	for(i=1;i<=100000;++i)
	{
		f[i]=2*f[i-1]%p;
		f[i]+=(22*sum[i-1]%p+p-11*(pow4[i-1]+pow7[i-1])%p)*pow10[i-1]%p;
		f[i]+=(16+49)*pow10[i-1]%p*pow10[i-1]%p*(pow2[i-1]+p-1)%p;
		f[i]+=((4*pow10[i-1]+pow7[i-1])%p)*((7*pow10[i-1]+pow4[i-1])%p)%p;
		f[i]%=p;
	}
	scanf("%s",s+1);ansl=calc();
	scanf("%s",s+1);ansr=calc();
	printf("%I64d\n",(ansr+p-ansl)%p);
}