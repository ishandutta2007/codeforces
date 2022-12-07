#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
typedef long long LL;
const LL N=1e5+20,M=1e5+20,inf=1e16;
LL n,m,p,l,r;
LL d[N],dis[N],A[M],sum[M],f[M],g[M],q[M];
inline void mread(LL &rx)
{
	LL fx=1;char c=getchar();
	rx=0;
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	rx*=fx;
}
int main()
{
//	freopen("test.in","r",stdin);
	LL i,j,hh,tt;
	mread(n);mread(m);mread(p);
	for(i=2;i<=n;++i)
	{
		mread(d[i]);
		dis[i]=dis[i-1]+d[i];
	}
	for(i=1;i<=m;++i)
	{
		mread(hh);mread(tt);
		A[i]=tt-dis[hh];
	}
	sort(A+1,A+m+1);
	for(i=1;i<=m;++i)
	{
		sum[i]=sum[i-1]+A[i];
	}
	for(i=1;i<=m;++i) f[i]=inf;
	while(p--)
	{
		l=1;r=1;
		for(i=1;i<=m;++i)
		{
			while(l<r&&q[l+1]<i&&(LD)f[q[l+1]]+sum[q[l+1]]-f[q[l]]-sum[q[l]]<=(LD)A[i]*(q[l+1]-q[l])) l++;
			g[i]=f[q[l]]-A[i]*q[l]+A[i]*i-sum[i]+sum[q[l]];
			while(l<r&&(LD)(f[q[r]]+sum[q[r]]-f[q[r-1]]-sum[q[r-1]])*(i-q[r-1])>=(LD)(q[r]-q[r-1])*(f[i]+sum[i]-f[q[r-1]]-sum[q[r-1]])) r--;
		    q[++r]=i;
		}
		for(i=1;i<=m;++i)
		{
			f[i]=min(f[i],g[i]);
		}
		memset(q,0,sizeof(q));
	}
	printf("%I64d",f[m]);
	return 0;
}