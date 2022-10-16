#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
int n;
long long s[N];
long long p[N];
int q;
long long l,r,v;
const int C=1e8;
struct bi
{
	long long h,m,l;
	bi(){}
	bi(long long v)
	{
		h=0;
		l=v%C;
		m=v/C;
	}
	bi(long long h,long long m,long long l)
	{
		this->h=h;
		this->m=m;
		this->l=l;
	}
};
bi operator + (bi a,bi b)
{
	long long h,m,l;
	l=a.l+b.l;
	m=a.m+b.m;
	h=a.h+b.h;
	m+=l/C;
	l%=C;
	h+=m/C;
	m%=C;
	return bi(h,m,l);
}
bi operator - (bi a,bi b)
{
	long long h,m,l;
	h=a.h-b.h;
	m=a.m-b.m;
	l=a.l-b.l;
	if (l<0)
	{
		m--;
		l+=C;
	}
	if (m<0)
	{
		h--;
		m+=C;
	}
	return bi(h,m,l);
}
bi operator * (bi a,bi b)
{
	long long h,m,l;
	l=a.l*b.l;
	m=a.m*b.l+b.m*a.l;
	h=a.h*b.l+b.h*a.l+a.m*b.m;
	m+=l/C;
	l%=C;
	h+=m/C;
	m%=C;
	return bi(h,m,l);
}
bi ps[N];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&s[i]);
	sort(s+1,s+n+1);
	for (int i=1;i<=n;i++)
		p[i]=s[i+1]-s[i];
	sort(p+1,p+n);
	for (int i=1;i<=n;i++)
		ps[i]=ps[i-1]+bi(p[i]);
	scanf("%d",&q);
	while (q--)
	{
		scanf("%lld%lld",&l,&r);
		v=r-l+1;
		int pos=lower_bound(p+1,p+n,v)-p;
		bi bv=bi(v)*bi(n-pos+1)+ps[pos-1];
		printf("%lld ",bv.h*C*C+bv.m*C+bv.l);
	}
	printf("\n");
	return 0;
}