#include <bits/stdc++.h>
using namespace std;
const int N=1e6+2,M=1e5+20,K=5e5+2,O=2e3+2;
struct Q
{
	int l,r,dt,typ;
	Q(int a=0,int b=0,int c=0,int d=0):typ(a),l(b),r(c),dt(d){}
};
Q q[K];
int a[N],f[M],st[M],bel[N],l[O],r[O],ans[K],cnt[M],cf[K];
int ttp,k;
inline void read(register int &x)
{
	register int c=getchar();
	while (c<48||c>57) c=getchar();
	x=c^48;c=getchar();
	while (c>=48&&c<=57) x=x*10+(c^48),c=getchar();
}
inline int getf(register int x)
{
	register int tp=1;st[1]=x;
	while (f[x]!=x) x=st[++tp]=f[x];
	while (--tp) f[st[tp]]=x;
	return x;
}
int main()
{
	register int n,m,nm=0,mx=0,ksiz,lz=0,i,j,x,y,z;
	read(n);read(m);ksiz=sqrt(n);
	for (i=1;i<=n;i++) read(a[i]),r[bel[i]=(i-1)/ksiz+1]=i,mx=max(mx,a[i]);
	for (i=n;i;i--) l[bel[i]]=i;
	for (i=1;i<=m;i++) read(q[i].typ),read(q[i].l),read(q[i].r),read(q[i].dt),--q[i].typ;
	for (i=1;i<=mx;i++) f[i]=i;int mxx=mx;
	for (k=1;k<=bel[n];k++)
	{
		for (i=1;i<=lz;i++) f[i]=i;nm+=lz;
		mx=lz=0;
		for (i=l[k];i<=r[k];i++) mx=max(mx,a[i]);
		for (i=nm+1;i<=mx;i++) f[i]=i;
		for (i=l[k];i<=r[k];i++) ++cnt[a[i]];
		nm=mx;
		for (j=1;j<=m;j++) if (bel[q[j].l]==k||bel[q[j].r]==k)
		{
			z=max(q[j].l,l[k]);y=min(q[j].r,r[k]);
			if (q[j].typ)
			{
				q[j].dt+=lz;
				for (i=z;i<=y;i++) ans[j]+=getf(a[i])==q[j].dt;
				q[j].dt-=lz;
			}
			else
			{
				for (i=l[k];i<=r[k];i++) a[i]=getf(a[i])-lz,cnt[a[i]+lz]=0;
				for (i=1;i<=lz;i++) f[i]=i;nm+=lz;
				lz=mx=0;
				for (i=z;i<=y;i++) if (a[i]>q[j].dt) a[i]-=q[j].dt;
				for (i=l[k];i<=r[k];i++) mx=max(mx,a[i]);
				for (i=nm+1;i<=mx;i++) f[i]=i;
				for (i=l[k];i<=r[k];i++) ++cnt[a[i]];
				nm=mx;
			}
		} else if (bel[q[j].l]<k&&bel[q[j].r]>k)
		{
			if (q[j].typ) ans[j]+=q[j].dt<=nm&&f[q[j].dt+lz]==q[j].dt+lz?cnt[q[j].dt+lz]:0; else if (q[j].dt<<1<nm)
			{
				x=lz+q[j].dt;
				for (i=lz+1;i<=x;i++) f[i]=f[i+q[j].dt],cnt[f[i]]+=cnt[i],cnt[i]=0;
				lz+=q[j].dt;nm-=q[j].dt;
			}
			else if (q[j].dt<nm)
			{
				x=nm+lz;
				for (i=q[j].dt+lz+1;i<=x;i++) f[i]=f[i-q[j].dt],cnt[f[i]]+=cnt[i],cnt[i]=0;
				nm=q[j].dt;
			}
		}
		for (i=l[k];i<=r[k];i++) cnt[getf(a[i])]=0;
	}
	for (i=1;i<=m;i++) if (q[i].typ) printf("%d\n",ans[i]);
}