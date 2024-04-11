#include <cstdio>
using namespace std;
long long n,m;
int i;
long long ans;
const long long hash_mod=1926081;
long long t[hash_mod],v[hash_mod];
long long val[hash_mod],ht;
long long h,j;
unsigned long long ret;
long long hash(long long q)
{
	h=q%hash_mod;
	j=0;
	while (t[h]!=0&&t[h]!=q)
	{
		j++;
		h+=j;
	}
	return v[h];
}
void ins(long long q,long long w)
{
	h=q%hash_mod;
	j=0;
	while (t[h]!=0&&t[h]!=q)
	{
		j++;
		h+=j;
	}
	if (t[h]==q)
		return;
	t[h]=q;
	v[h]=w;
}
long long fastmul(unsigned long long x,unsigned long long y,unsigned long long n)
{
	ret=0;
	while (x)
	{
		ret=(ret+(x&131071ll)*y)%n;
		y<<=17;
		y%=n;
		x>>=17;
	}
	return ret;
}
long long phi(long long n)
{
	ret=n;
	for (register int i=2;(long long)i*i<=n;i++)
		if (n%i==0)
		{
			while (n%i==0)
				n/=i;
			ret=ret/i*(i-1);
		}
	if (n>1)
		ret=ret/n*(n-1);
	return ret;
}
long long fastpow(long long m,long long p,long long n)
{
	long long ret=1ll;
	while (p)
	{
		if (p&1)
			ret=fastmul(ret,m,n);
		p>>=1;
		m=fastmul(m,m,n);
	}
	return ret;
}
long long cal(long long p,long long n)
{
	if (m%n==1)
		return p;
	register int i;
	for (i=1;i<=ht;i++)
		if (p%val[i]==0)
			if (hash(val[i])%n==1)
				return p/val[i];
	return 1ll;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	long long p=phi(n);
	for (i=1;(long long)i*i<=p;i++)
		if (p%i==0)
		{
			ins(p/i,fastpow(m,p/i,n));
			ins(i,fastpow(m,i,n));
			val[++ht]=i;
		}
	for (i--;i>=1;i--)
		if (p%i==0)
			val[++ht]=p/i;
	for (i=1;(long long)i*i<=n;i++)
		if (n%i==0)
			if ((long long)i*i==n)
				ans+=cal(phi(i),i);
			else
			{
				ans+=cal(phi(i),i);
				ans+=cal(phi(n/i),n/i);
			}
	printf("%lld\n",ans);
	return 0;
}