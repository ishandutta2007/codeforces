#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,sum;
	int posl,posr,pos;
	struct node
	{
		int l,r,c;
	}a[N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();posl=posr=pos=1;
			for(int i=1;i<=n;++i)
			{
				a[i].l=read(),a[i].r=read(),a[i].c=read();
			}
			printf("%lld\n",a[1].c);
			a[0].c=1e18;
			for(int s,i=2;i<=n;++i)
			{
				if(a[i].l<a[posl].l||(a[i].l==a[posl].l&&a[i].c<a[posl].c)) posl=i;
				if(a[i].r>a[posr].r||(a[i].r==a[posr].r&&a[i].c<a[posr].c)) posr=i;
				if(a[pos].l!=a[posl].l||a[pos].r!=a[posr].r) pos=0;
				if(a[i].l==a[posl].l&&a[i].r==a[posr].r&&a[i].c<a[pos].c) pos=i;
				s=a[posl].c;
				if(posl!=posr) s+=a[posr].c;
				s=min(s,a[pos].c);
				printf("%lld\n",s);
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}