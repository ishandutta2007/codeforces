#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
ll ans,a[N];
int n,c,fh,i,t,x;
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
int main()
{
	read(t);
	while (t--)
	{
		read(n);ans=0;
		for (i=1;i<=n;i++) {read(x);a[i]=x;}
		for (i=1;i<n;i++) if (a[i]<0) ans+=-a[i]; else a[i+1]+=a[i];
		printf("%lld\n",ans);
	}
}