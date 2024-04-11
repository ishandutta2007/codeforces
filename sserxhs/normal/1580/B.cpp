#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=102;
unsigned int f[N][N][N],c[N][N],fac[N],*g,*h;
unsigned int n,nn,m,q,p,i,j,k,ii,jj,lim;
int main()
{
	cin>>nn>>m>>q>>p;
	n=100;
	for (i=0;i<=n;i++) c[i][0]=1;
	for (i=1;i<=n;i++) for (j=1;j<=i;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
	fac[0]=1;
	for (i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%p;n=nn;
	if (n<m+q-1)
	{
		cout<<"0\n";
		return 0;
	}
	for (i=0;i<=m;i++) f[0][i][0]=1;
	for (i=1;i<=n;i++) f[i][0][0]=f[i][1][1]=fac[i];
	for (i=1;i<=n;i++) for (j=i+1;j<=n;j++) f[i][j][0]=fac[i];
	unsigned int ls=0;
	for (i=2;i<=n;i++) {int lm=min(i,m);for (j=2;j<=lm;j++) {int lmm=min(i-j+1,q);for (k=0;k<=lmm;k++)
	{
		lim=min(k,ii);
		for (ii=1;ii<=i;ii++)
		{
			g=f[ii-1][j-1];h=f[i-ii][j-1];
			ls=0;
			for (jj=0;jj<=lim;jj++) ls=(ls+(ll)g[jj]*h[k-jj])%p;
			f[i][j][k]=(f[i][j][k]+(ll)ls*c[i-1][ii-1])%p;
		}
	}}}
	cout<<f[n][m][q]<<endl;
}