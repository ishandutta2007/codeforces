#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=4e6+10,p=998244353;
	int n,m,limit=1,len;
	int a[N],b[N],c[N],pos[N];
	int ans[N],num;
	inline int fast(int x,int k)
	{
		int ret=1;
		while(k)
		{
			if(k&1) ret=ret*x%p;
			x=x*x%p;
			k>>=1;
		}
		return ret;
	}
	inline void ntt(int *a,int inv)
	{
		for(int i=0;i<limit;++i)
			if(i<pos[i]) swap(a[i],a[pos[i]]);
		for(int mid=1;mid<limit;mid<<=1)
		{
			int Wn=fast(3,(p-1)/(mid<<1));
			for(int r=mid<<1,j=0;j<limit;j+=r)
			{
				int w=1;
				for(int k=0;k<mid;++k,w=w*Wn%p)
				{
					int x=a[j+k],y=w*a[j+k+mid]%p;
					a[j+k]=(x+y)%p;
					a[j+k+mid]=(x-y+p)%p;
				}
			}
		}
		if(inv) return;
		inv=fast(limit,p-2);reverse(a+1,a+limit);
		for(int i=0;i<limit;++i) a[i]=a[i]*inv%p;
	}
	inline void main()
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[read()]=1;
		for(int i=1;i<=m;++i) c[i]=a[i];
		while(limit<=2*m) limit<<=1,++len;
		for(int i=0;i<=limit;++i) pos[i]=(pos[i>>1]>>1)|((i&1)<<(len-1));
		ntt(a,1);
		for(int i=0;i<limit;++i) a[i]=a[i]*a[i]%p;
		ntt(a,0);
		for(int i=1;i<=m;++i)
		{
			if(a[i]>=1&&!c[i])
			{
				puts("NO");
				return;
			}
			if(c[i]&&!a[i]) ans[++num]=i;
		}
		puts("YES");
		printf("%lld\n",num);
		for(int i=1;i<=num;++i) printf("%lld ",ans[i]);
	}
}
signed main()
{
	red::main();
	return 0;
}