#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+2,p=998244353;
int a[N],fac[N],ifac[N];
int n,m,c,fh,i,t,ans;
inline void read(int &x)
{
	c=getchar();fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
inline int ksm(int x,int y)
{
	int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;
		y>>=1;
	}
	return r;
}
int main()
{
	read(n);m=n<<1;fac[0]=1;
	for (i=1;i<=m;i++) fac[i]=(ll)fac[i-1]*i%p;
	ifac[m]=ksm(fac[m],p-2);
	for (i=m-1;~i;i--) ifac[i]=(ll)ifac[i+1]*(i+1)%p;
	for (i=1;i<=m;i++) read(a[i]);
	sort(a+1,a+m+1);
	for (i=1;i<=n;i++) ans=(ans+a[i+n]-a[i])%p;
	printf("%d",int((long long)ans*fac[m]%p*ifac[n]%p*ifac[n]%p));
}