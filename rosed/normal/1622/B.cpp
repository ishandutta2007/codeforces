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
	int T,n,s0,s1;
	int a[N],ans[N];
	char s[N];
	struct node
	{
		int pos,val;
		inline bool operator < (const node &t) const
		{
			return val<t.val;
		}
	}b[2][N];
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();s0=s1=0;
			for(int i=1;i<=n;++i) a[i]=read(); 
			cin>>(s+1);
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='1') b[1][++s1]=(node){i,a[i]};
				else b[0][++s0]=(node){i,a[i]};
			}
			sort(b[0]+1,b[0]+s0+1);
			sort(b[1]+1,b[1]+s1+1);
			for(int i=1;i<=s0;++i)
			{
				ans[b[0][i].pos]=i;
			}
			for(int i=s0+1;i<=n;++i)
			{
				ans[b[1][i-s0].pos]=i;
			}
			for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
			puts(""); 
		}
	}
}
signed main()
{
	red::main();
	return 0;
}