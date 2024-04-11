#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+2;
int x[N],nxt[N],pre[N],f[N][2],z[N],y[N];
int t,n,m,i,j,c;
inline void read(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
int main()
{
	//freopen("a.in","r",stdin);
	read(t);
	while (t--)
	{
		read(n);read(m);
		for (i=1;i<=n;i++) read(x[i]);
		sort(x+1,x+n+1);
		for (i=1;i<=n;i++) read(j);
		pre[1]=1;
		for (i=j=1;i<=n;i++)
		{
			f[i][0]=f[i][1]=0;
			while ((j<n)&&(x[j+1]<=x[i]+m)) pre[++j]=i;
			nxt[i]=j;
		}y[n+1]=0;
		for (i=1;i<=n;i++) z[i]=max(z[i-1],i-pre[i]+1);
		for (i=n;i;i--) y[i]=max(y[i+1],nxt[i]-i+1);c=0;
		for (i=1;i<=n;i++) c=max(c,z[i]+y[i+1]);printf("%d\n",c);
	}
}