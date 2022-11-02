#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

map <long long,int>Hash;
long long num[1000005],sum[1000005];
int tot,S;

long long gcd(long long a,long long b)
{
	long long tmp;
	while(b!=0)tmp=b,b=a%b,a=tmp;
	return a;
}

long long mult(long long x,long long y,long long mod)
{
	long long ans=0;
	while(y)
	{
		if(y%2)ans=(ans+x)%mod;
		x=(x+x)%mod;
		y/=2;
	}
	return ans;
}

long long Power_mult(long long x,long long y,long long mod)
{
	long long ans=1;
	while(y)
	{
		if(y%2)ans=mult(ans,x,mod);
		x=mult(x,x,mod);
		y/=2;
	}
	return ans;
}

int prime[]={0,2,3,5,7,11,13,17,19,23,29};

bool prime_test(long long n)
{
	if(n<=1)return false;
	if(n==2)return true;
	if(n%2==0)return false;
	long long i,j,k=0,m=n-1,a;
	while(m%2==0)m/=2,++k;
	for(i=1;i<=10;++i)
	{
		if(prime[i]==n)return true;
		if(prime[i]>n)return false;
		a=Power_mult(prime[i],m,n);
		if(a==1)continue;
		for(j=1;j<=k;++j)
		{
			if(a==n-1)break;
			a=mult(a,a,n);
		}
		if(j>k)return false;
	}
	return true;
}

long long rho(long long n)
{
	long long i=1,x,y,k=2,c,d;
	c=rand()%(n-1)+1;
	x=y=rand()%n;
	do
	{
		++i;
		d=gcd(n+y-x,n);
		if(d>1&&d<n)return d;
		if(i==k)y=x,k*=2;
		x=(mult(x,x,n)+c)%n;
	}while(x!=y);
	return -1;
}

void rho_main(long long now)
{
	if(prime_test(now))
	{
		num[++tot]=now;
		return;
	}
	long long half=rho(now);
	while(half==-1)half=rho(now);
	rho_main(half);
	rho_main(now/half);
}

long long cp[1001],cn[1001],cm[1001],ca[1001],c;
long long fac[10000001];

long long Power(long long a,long long b,long long p)
{
	long long ans=1;
	while(b)
	{
		if(b%2)ans=(ans*a)%p;
		a=(a*a)%p;
        b/=2;
	}
	return ans;
}

int n,i,j,k;
long long a,p,ans;

int main()
{
	scanf("%d",&n);
	p=1000000007;
	for(i=1;i<=n;++i)
	{
		scanf("%I64d",&a);
		if(a!=1)rho_main(a);
	}
	S=0;
	for(i=1;i<=tot;++i)++Hash[num[i]];
	for(i=1;i<=tot;++i)
	if(Hash[num[i]])
	{
		sum[++S]=Hash[num[i]];
		Hash[num[i]]=0;
	}
	tot=0;
	rho_main(p);
	for(i=1;i<=tot;++i)++Hash[num[i]];
	for(i=1;i<=tot;++i)
	if(Hash[num[i]])
	{
		++c;
		cn[c]=1;cp[c]=num[i];
		for(j=Hash[num[i]];j;--j)cn[c]*=num[i];
		cm[c]=p/cn[c];
		Hash[num[i]]=0;
	}
	ans=1;
	fac[0]=1;
	for(i=1;i<=1000000;++i)fac[i]=fac[i-1]*i%p;
	for(i=1;i<=S;++i)ans=ans*fac[sum[i]+n-1]%p*Power(fac[sum[i]],p-2,p)%p*Power(fac[n-1],p-2,p)%p;
	printf("%I64d\n",ans);
}