#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef unsigned long long ll;
const int N=105;
const ui p=1e9+7;
ui a[N][N],b[N][N];
int c[N];
ui ksm(ll x,int y)
{
	ll r=1;
	while (y)
	{
		if (y&1) r=r*x%p;
		x=x*x%p;y>>=1;
	}
	return r;
}
ui det(ui a[N][N],int n)
{
	ui r=1;
	int i,j,k;
	for (i=1;i<=n;i++)
	{
		for (j=i;j<=n;j++) if (a[j][i]) break;
		if (j>n) return 0;
		if (i!=j) swap(a[j],a[i]),r=p-r;
		r=(ll)r*a[i][i]%p;
		ui x=ksm(a[i][i],p-2);
		for (j=i;j<=n;j++) a[i][j]=(ll)a[i][j]*x%p;
		for (j=i+1;j<=n;j++)
		{
			ui x=p-a[j][i];
			for (k=i;k<=n;k++) a[j][k]=((ll)x*a[i][k]+a[j][k])%p;
		}
	}
	if (n&1) r=p-r;
	return r%p;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i,j,k;
	cin>>n;
	for (i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		a[u][v]=a[v][u]=1;
	}
	for (k=0;k<n;k++)
	{
		for (i=1;i<n;i++) for (j=1;j<=n;j++) b[i][j]=a[i][j]*k+1;
		for (i=1;i<n;i++) b[i][i]=p;
		for (i=1;i<n;i++) for (j=1;j<=n;j++) if (i!=j) b[i][i]-=b[i][j];
		c[k+1]=det(b,n-1);
	}
	int m=n+1;
	for (i=1;i<=n;i++) a[i][m]=c[i];
	for (i=1;i<=n;i++) for (k=j=1;j<=n;j++,k=(ll)k*i%p) a[i][j]=k;
	for (i=1;i<=n;i++)
	{
		for (j=i;j<=m;j++) if (a[j][i]) break;
		if (j!=i) swap(a[i],a[j]);
		ui x=ksm(a[i][i],p-2);
		for (j=i;j<=m;j++) a[i][j]=(ll)a[i][j]*x%p;
		for (j=1;j<=n;j++) if (i!=j&&a[j][i])
		{
			ui x=p-a[j][i];
			for (k=i;k<=m;k++) a[j][k]=((ll)x*a[i][k]+a[j][k])%p;
		}
	}
	for (i=1;i<=n;i++) cout<<a[i][m]<<" \n"[i==n];
}