#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2;
ll ans,a[N];
int n,c,fh,i,q,x,y,z;
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
inline void read(ll &x)
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
inline ll ab(register ll x)
{
	if (x<=0) return 0;return x;
}
int main()
{
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	for (i=n;i;i--) a[i]-=a[i-1];ans=a[1];
	for (i=2;i<=n;i++) if (a[i]>0) ans+=a[i];
	read(q);
	while (q--)
	{
		printf("%lld\n",ans+1>>1);
		read(z);read(y);read(x);++y;
		if (z>1)
		{
			ans-=ab(a[z]);
			a[z]+=x;
			ans+=ab(a[z]);
		} else ans+=x;
		if (y<=n)
		{
			ans-=ab(a[y]);
			a[y]-=x;
			ans+=ab(a[y]);
		}
	}
	printf("%lld\n",ans+1>>1);
}