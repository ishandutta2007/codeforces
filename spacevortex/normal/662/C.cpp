#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=25,V=(1ll<<20)+20,M=1e5+20,inf=1e17;
ll n,m,sx,ans;
ll a[V],b[V];
char s[N][M];
void FWT(ll n,ll opt,ll *w)
{
	ll len,mid,i,j,a,b;
	for(len=2;len<=n;len<<=1)
	{
		mid=len>>1;
		for(i=0;i<n;i+=len)
		{
			for(j=0;j<mid;j++)
			{
				a=w[i+j]+w[i+mid+j];b=w[i+j]-w[i+mid+j];
				if(opt==-1) a>>=1,b>>=1;
				w[i+j]=a;w[i+mid+j]=b;
			}
		}
	}
}
int main()
{
	ll i,j,now,ns;
	scanf("%I64d%I64d",&n,&m);
	sx=1<<n;
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(i=1;i<=m;i++)
	{
		now=0;
		for(j=1;j<=n;j++)
		{
			now=(now<<1)|(s[j][i]=='1');
		}
		a[now]++;
	}
	for(ns=0;ns<sx;ns++)
	{
		now=0;
		for(i=0;i<n;i++)
		{
			if(ns&(1ll<<i)) now++;
		}
		b[ns]=min(now,n-now);
	}
	FWT(sx,1,a);FWT(sx,1,b);
	for(i=0;i<sx;i++) a[i]*=b[i];
	FWT(sx,-1,a);
	ans=inf;
	for(i=0;i<sx;i++) ans=min(ans,a[i]);
	printf("%I64d",ans);
	return 0;
}