#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=1e6+10,inf=1e9+7,base=131,mod=1e9+7;
	int n,m,t,ret;
	char a[N],b[N],s[N];
	int nxt[N],f[N],g[N];
	int pw[N],ha[N],hs[N];
	inline void prepare(char *a,int *f)
	{
		int len=max(n,m);
		for(int i=pw[0]=1;i<=len;++i) pw[i]=pw[i-1]*base%mod;
		for(int i=1;i<=n;++i) ha[i]=(ha[i-1]*base+a[i])%mod;
		for(int i=1;i<=m;++i) hs[i]=(hs[i-1]*base+s[i])%mod;
		for(int i=1;i<=n;++i)
		{
			int l=i,r=n;
			while(l<=r)
			{
				int t1=(ha[mid]-ha[i-1]*pw[mid-i+1]%mod+mod)%mod;
				int t2=hs[mid-i+1];
				if(t1==t2) f[i]=mid-i+1,l=mid+1;
				else r=mid-1;
			}
			f[i]=min(f[i],m-1);
		}
	}
	struct BIT
	{
		int tr[N];
		BIT(){memset(tr,0,sizeof(tr));}
		inline void update(int p,int k)
		{
			for(p++;p<N;p+=p&(-p)) tr[p]+=k;
		}
		inline int query(int p)
		{
			int ret=0;
			for(p++;p;p-=p&(-p)) ret+=tr[p];
			return ret;
		}
	}bit[2];
	inline void main()
	{
		n=read(),m=read();
		scanf("%s%s%s",a+1,b+1,s+1);
		prepare(a,f);
		reverse(s+1,s+m+1);reverse(b+1,b+n+1);
		prepare(b,g);
		reverse(g+1,g+n+1);
		for(int i=n;i;--i)
		{
			bit[0].update(g[i],1);
			bit[1].update(g[i],g[i]);
			if(i+m-1<=n)
			{
				bit[0].update(g[i+m-1],-1);
				bit[1].update(g[i+m-1],-g[i+m-1]);
			}
			//if(!f[i]) continue;
			int v=m-f[i];
			ret+=bit[1].query(m)-bit[1].query(v-1);
			ret-=(bit[0].query(m)-bit[0].query(v-1))*(v-1);
		}
		printf("%lld\n",ret);
	}
}
signed main()
{
	red::main();
	return 0;
}