#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define p 1051131
using namespace std;

int n,m,s,i,j,k,inv2,ans,pt;
long long t;
int pp[1200005],prime[1200005],tot;
int a[35000000],c[1200005],b[35000000];

void FWT(int *a)
{
	int i,j,k,t,l,x,y;
	for(i=1;i<n;i<<=1)
	for(j=0,t=n/(i<<1);j<n;j+=i<<1)
	for(k=l=0;k<i;++k,l+=t)
	{
		x=a[j+k];y=a[j+k+i];
		a[j+k]=(x+y)%p;
		a[j+k+i]=(x-y+p)%p;
	}
}

void ex_gcd(int a,int b,int &x,int &y)
{
    if(!b)x=1,y=0;
    else ex_gcd(b,a%b,y,x),y-=a/b*x;
}
int Div(int a) 
{
    int x, y;
    ex_gcd(a,p,x,y);
    if(x<0)x+=p;
    return x;
}

int Power(int a,long long b)
{
	int ans=1;
	for(;b;b>>=1,a=(long long)a*a%p)if(b&1)ans=(long long)ans*a%p;
	return ans;
}
int Power2(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=(long long)a*a%p)if(b&1)ans=(long long)ans*a%p;
	return ans;
}

int phi(int n)
{
	int i,sq,ans=n;
	sq=(int)sqrt(n);
	for(i=2;i<=n&&i<=sq;++i)
	if(n%i==0)
	{
		ans=ans/i*(i-1);
		while(n%i==0)n/=i;
	}
	if(n>1)ans=ans/n*(n-1);
	return ans;
}

int main()
{
	scanf("%d%I64d%d",&m,&t,&s);n=1<<m;pt=t%phi(p);
	for(i=0;i<s;++i)scanf("%d",&a[i]);
	for(i=s;i<n;++i)a[i]=(101*a[i-s]+10007)%p;
	FWT(a);
	b[0]=1;
	for(i=1;i<n;++i)b[i]=(i&-i)%p;
	FWT(b);
	c[1]=1;
	for(i=2;i<p;++i)
	{
		if(!pp[i])
		{
			prime[++tot]=pp[i]=i;
			if(p%i==0)c[i]=Power(i,t);else c[i]=Power2(i,pt);
		}else c[i]=(long long)c[i/pp[i]]*c[pp[i]]%p;
		for(j=1;j<=tot&&prime[j]<=pp[i]&&prime[j]<=p/i;++j)pp[i*prime[j]]=prime[j];
	}
	for(i=0;i<n;++i)b[i]=c[b[i]];
	for(i=0;i<n;++i)a[i]=(long long)a[i]*b[i]%p;
	FWT(a);
	inv2=Div(n);
	for(i=0;i<n;++i)a[i]=(long long)a[i]*inv2%p;
	ans=0;
	for(i=0;i<n;++i)ans^=a[i];
	printf("%d\n",ans);
}