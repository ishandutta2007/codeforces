#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define lowbit(i) (i&(-i))
	inline int read()
	{
		int x=0;char f=1,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=4e5+10;
	int n,ans;
	int a[N],b[N],c[N],pos[N];
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=a[i+n]=read(),pos[a[i]]=i;
		for(int i=1;i<=n;++i) b[i]=read();
		for(int i=1;i<=n;++i)
		{
			int t=pos[b[i]]-i+1;
			if(t>0)++c[t];
			t=pos[b[i]]-i+n+1;
			++c[t];
		}
		for(int i=1;i<=n;++i) ans=max(ans,c[i]);
		printf("%lld\n",ans);
	}
}
signed main()
{
	red::main();
	return 0;
}