#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,M=205;
int a[M][M],yss[128],s[N][N],ys[N][N],f[N*N],fs[N*N];
int n,m,i,j,p,c,x,y,cnt,ctt,ans;
int ksm(int x,int y)
{
	int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		y>>=1;x=(ll)x*x%p;
	}
	return r;
}
int getf(int x){if (f[x]==x) return x;return f[x]=getf(f[x]);}
int cal(int a[][M],register int n)
{
	register int i,j,k,r=1,fh=0,l;
	for (i=1;i<=n;i++)
	{
		for (j=i;j<=n;j++) if (a[j][i]) break;
		if (j>n) return 0;
		if (i!=j) {swap(a[j],a[i]);fh^=1;}
		r=(ll)r*a[i][i]%p;
		k=ksm(a[i][i],p-2);
		for (j=i;j<=n;j++) a[i][j]=(ll)a[i][j]*k%p;
		for (j=i+1;j<=n;j++)
		{
			a[j][i]=p-a[j][i];
			for (k=i+1;k<=n;k++) a[j][k]=(a[j][k]+(ll)a[j][i]*a[i][k])%p;
			a[j][i]=0;
		}
	}
	if (fh) return (p-r)%p;
	return r;
}
int main()
{
	yss['/']=1;yss['\\']=2;yss['*']=3;
	scanf("%d%d%d",&n,&m,&p);
	for (i=1;i<=n;i++)
	{
		c=getchar();
		while (!yss[c]) c=getchar();
		s[i][1]=yss[c];
		for (j=2;j<=m;j++) s[i][j]=yss[getchar()];
	}
	for (i=1;i<=n+1;i++) for (j=1;j<=m+1;j++) if (i+j&1) ys[i][j]=++cnt;
	for (i=1;i<=cnt;i++) f[i]=i;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (s[i][j]<3)
	{
		if (s[i][j]==1) x=ys[i][j+1],y=ys[i+1][j]; else x=ys[i][j],y=ys[i+1][j+1];
		if (x) assert(y),f[getf(x)]=getf(y);
	}
	for (i=1;i<=cnt;i++) if (getf(i)==i) fs[i]=++ctt;
	if (ctt<=201)
	{
		for (i=1;i<=ctt;i++) for (j=1;j<=ctt;j++) if (i!=j) a[i][j]=p; else a[i][j]=0;
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (s[i][j]==3)
		{
			if (i+j+1&1) x=fs[f[ys[i][j+1]]],y=fs[f[ys[i+1][j]]]; else x=fs[f[ys[i][j]]],y=fs[f[ys[i+1][j+1]]];
			++a[x][x];++a[y][y];--a[x][y];--a[y][x];
		}
		ans=cal(a,ctt-1);
	}
	memset(ys,0,sizeof(ys));cnt=ctt=0;
	for (i=1;i<=n+1;i++) for (j=1;j<=m+1;j++) if (i+j+1&1) ys[i][j]=++cnt;
	for (i=1;i<=cnt;i++) f[i]=i;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (s[i][j]<3)
	{
		if (s[i][j]==1) x=ys[i][j+1],y=ys[i+1][j]; else x=ys[i][j],y=ys[i+1][j+1];
		if (x) assert(y),f[getf(x)]=getf(y);
	}
	for (i=1;i<=cnt;i++) if (getf(i)==i) fs[i]=++ctt;
	if (ctt<=201)
	{
		for (i=1;i<=ctt;i++) for (j=1;j<=ctt;j++) if (i!=j) a[i][j]=p; else a[i][j]=0;
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (s[i][j]==3)
		{
			if (i+j&1) x=fs[f[ys[i][j+1]]],y=fs[f[ys[i+1][j]]]; else x=fs[f[ys[i][j]]],y=fs[f[ys[i+1][j+1]]];
			++a[x][x];++a[y][y];--a[x][y];--a[y][x];
		}
		ans=(ans+cal(a,ctt-1))%p;
	}
	cout<<ans<<endl;
}