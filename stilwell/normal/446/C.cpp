#include <stdio.h>
#include <stdlib.h>
#define p 1000000009
using namespace std;

int n,m,i,j,k,l,ll,rr,opt;
long long sum[2000005],addA[2000005],addB[2000005];
long long powA[2000005],powB[2000005],sumA[2000005],sumB[2000005];
long long sq,A,B,invsq,ans;

long long Power(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b%2)ans=ans*a%p;
		a=a*a%p;
		b/=2;
	}
	return ans;
}

void C(int x,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		addA[x]=(addA[x]+powA[l-ll])%p;
		addB[x]=(addB[x]+powB[l-ll])%p;
		sum[x]=(sum[x]+powA[l-ll]*sumA[r-l+1]%p-powB[l-ll]*sumB[r-l+1]%p)%p;
		return;
	}
	int mid=l+r>>1;
	addA[x<<1]=(addA[x<<1]+addA[x])%p;
	addB[x<<1]=(addB[x<<1]+addB[x])%p;
	sum[x<<1]=(sum[x<<1]+addA[x]*sumA[mid-l+1]%p-addB[x]*sumB[mid-l+1]%p)%p;
	addA[x<<1|1]=(addA[x<<1|1]+addA[x]*powA[mid-l+1]%p)%p;
	addB[x<<1|1]=(addB[x<<1|1]+addB[x]*powB[mid-l+1]%p)%p;
	sum[x<<1|1]=(sum[x<<1|1]+addA[x]*powA[mid-l+1]%p*sumA[mid-l+1]%p-addB[x]*powB[mid-l+1]%p*sumB[mid-l+1]%p)%p;
	addA[x]=addB[x]=0;
	if(rr<=mid)C(x<<1,l,mid);
	else if(ll>mid)C(x<<1|1,mid+1,r);
		else C(x<<1,l,mid),C(x<<1|1,mid+1,r);
	sum[x]=(sum[x<<1]+sum[x<<1|1])%p;
}

void Q(int x,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		ans=(ans+sum[x])%p;
		return;
	}
	int mid=l+r>>1;
	addA[x<<1]=(addA[x<<1]+addA[x])%p;
	addB[x<<1]=(addB[x<<1]+addB[x])%p;
	sum[x<<1]=(sum[x<<1]+addA[x]*sumA[mid-l+1]%p-addB[x]*sumB[mid-l+1]%p)%p;
	addA[x<<1|1]=(addA[x<<1|1]+addA[x]*powA[mid-l+1]%p)%p;
	addB[x<<1|1]=(addB[x<<1|1]+addB[x]*powB[mid-l+1]%p)%p;
	sum[x<<1|1]=(sum[x<<1|1]+addA[x]*powA[mid-l+1]%p*sumA[mid-l+1]%p-addB[x]*powB[mid-l+1]%p*sumB[mid-l+1]%p)%p;
	addA[x]=addB[x]=0;
	if(rr<=mid)Q(x<<1,l,mid);
	else if(ll>mid)Q(x<<1|1,mid+1,r);
		else Q(x<<1,l,mid),Q(x<<1|1,mid+1,r);
	sum[x]=(sum[x<<1]+sum[x<<1|1])%p;
}

int main()
{
	sq=383008016;
	invsq=Power(sq,p-2);
	A=(1+sq)*Power(2,p-2)%p;
	B=(1+p-sq)*Power(2,p-2)%p;
	scanf("%d%d",&n,&m);
	powA[0]=powB[0]=1;sumA[0]=sumB[0]=0;
	for(i=1;i<=n;++i)
	{
		powA[i]=powA[i-1]*A%p;
		powB[i]=powB[i-1]*B%p;
		sumA[i]=(sumA[i-1]+powA[i])%p;
		sumB[i]=(sumB[i-1]+powB[i])%p;
	}
	for(l=1;l<n;l*=2);
	for(i=1;i<=n;++i)scanf("%I64d",&sum[l+i-1]),sum[l+i-1]=sum[l+i-1]*sq%p;
	for(i=l-1;i;--i)sum[i]=sum[i<<1]+sum[i<<1|1];
	for(;m;--m)
	{
		scanf("%d%d%d",&opt,&ll,&rr);
		if(opt==1)C(1,1,l);
		else
		{
			ans=0;
			Q(1,1,l);
			ans=(ans+p)%p;
			ans=ans*invsq%p;
			printf("%I64d\n",ans);
		}
	}
}