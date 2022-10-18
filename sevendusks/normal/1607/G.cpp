/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,n,m,a[N],b[N],l[N],r[N],x[N];
bool bl;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void print(int ans)
{
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++)
	{
		if (bl) printf("%lld %lld\n",m-x[i],x[i]);
		else printf("%lld %lld\n",x[i],m-x[i]);
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		for (int i=1;i<=n;i++) a[i]=read(),b[i]=read();
		int sa=0,sb=0;bl=0;
		sa=accumulate(a+1,a+1+n,sa);
		sb=accumulate(b+1,b+1+n,sb);
		if (sa<sb)
		{
			bl=1;
			swap(sa,sb);
			for (int i=1;i<=n;i++) swap(a[i],b[i]);
		}
		sa=0,sb=0;int sum=0;
		for (int i=1;i<=n;i++)
		{
			l[i]=max(0ll,m-b[i]);
			r[i]=min(m,a[i]);
			x[i]=r[i];
			sa+=a[i]-r[i];
			sb+=b[i]-(m-r[i]);
			sum+=r[i]-l[i];
		}
		if (sa>=sb)
		{
			print(sa-sb);
			continue;
		}
		int d=min((sb-sa)/2,sum),ans=abs(sa-sb+2*d);
		for (int i=1;i<=n;i++)
		{
			int now=min(r[i]-l[i],d);
			x[i]-=now;d-=now;
		}
		print(ans);
	}
}