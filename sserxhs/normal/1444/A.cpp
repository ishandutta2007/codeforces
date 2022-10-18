#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,fh,i,t,m,x,cnt,ct;
ll n,y,ans;
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
ll ksm(ll x,int y)
{
	ll r=1;
	while (y)
	{
		if (y&1) r*=x;x*=x;y>>=1;
	}
	return r;
}
int main()
{
	read(t);
	while (t--)
	{
		read(n);read(m);ans=9e18;
		if (n%m) printf("%lld\n",n); else
		{
			x=sqrt(m);y=n/m;
			for (i=2;i<=x;i++) if (m%i==0)
			{
				cnt=1;m/=i;ct=0;
				while (m%i==0) {++cnt;m/=i;}
				while (y%i==0) {++ct;y/=i;}
				ans=min(ans,ksm(i,ct+1));
			}
			if (m!=1)
			{
				i=m;
				cnt=1;m/=i;ct=0;
				while (m%i==0) {++cnt;m/=i;}
				while (y%i==0) {++ct;y/=i;}
				ans=min(ans,ksm(i,ct+1));
			}
			printf("%lld\n",n/ans);
		}
	}
}
//x|p,q\ne|x