#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,K,l,val,ll,rr;
int change[400005],C[15][15];
long long sum[400005][6],S[400005][6],ans;
char opt;

void Change(int p,int v,int l,int r)
{
	int i;
	for(i=0;i<=5;++i)
	sum[p][i]=v*(S[r][i]-S[l-1][i]+1000000007)%1000000007;
	change[p]=v;
}

void M(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		Change(p,val,l,r);
		return;
	}
	int mid=l+r>>1;
	if(change[p]!=-1)
	{
		Change(p<<1,change[p],l,mid);
		Change(p<<1|1,change[p],mid+1,r);
		change[p]=-1;
	}
	if(rr<=mid)M(p<<1,l,mid);
	else if(ll>mid)M(p<<1|1,mid+1,r);
		else M(p<<1,l,mid),M(p<<1|1,mid+1,r);
	for(int i=0;i<=5;++i)sum[p][i]=(sum[p<<1][i]+sum[p<<1|1][i])%1000000007;
}

void Q(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		int i;
		long long tmp=1;
		for(i=0;i<=K;++i)
		{
			ans=(ans+tmp*sum[p][K-i]%1000000007*C[K][i])%1000000007;
			tmp=tmp*(1000000007-ll+1)%1000000007;
		}
		return;
	}
	int mid=l+r>>1;
	if(change[p]!=-1)
	{
		Change(p<<1,change[p],l,mid);
		Change(p<<1|1,change[p],mid+1,r);
		change[p]=-1;
	}
	if(rr<=mid)Q(p<<1,l,mid);
	else if(ll>mid)Q(p<<1|1,mid+1,r);
		else Q(p<<1,l,mid),Q(p<<1|1,mid+1,r);
}

int main()
{
	C[0][0]=1;
	for(i=0;i<=10;++i)
	for(j=0;j<=10;++j)
	C[i+1][j]+=C[i][j],C[i+1][j+1]+=C[i][j];
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		S[i][0]=1;
		for(j=1;j<=5;++j)S[i][j]=S[i][j-1]*i%1000000007;
		for(j=0;j<=5;++j)S[i][j]=(S[i][j]+S[i-1][j])%1000000007;
	}
	for(l=1;l<n;l*=2);
	for(i=l+l;i;--i)change[i]=-1;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&val);
		ll=rr=i;
		M(1,1,l);
	}
	for(;m;--m)
	{
		opt=getchar();
		while(opt!='='&&opt!='?')opt=getchar();
		if(opt=='=')
		{
			scanf("%d%d%d",&ll,&rr,&val);
			M(1,1,l);
		}
		else
		{
			ans=0;
			scanf("%d%d%d",&ll,&rr,&K);
			Q(1,1,l);
			printf("%I64d\n",ans);
		}
	}
}