#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,p=1e9+7;
	int n,m,ret,l,r;
	int a[N],b[N],q[N],c[N];
	int num[N];
	vector<int> ans[N];
	inline bool check(int x)
	{
		int tag=0;
		memset(num,0,sizeof(num));
		for(int i=1;i<=m;++i) q[i]=b[i];
		int j=1;
		for(int i=m;i>=1;--i)
		{
			tag+=c[i]-c[i+1];
			if(c[i]!=c[i+1]) j=1;
			for(;j<=x&&q[i];++j)
			{
				int d=min(q[i],tag-num[j]);
				num[j]+=d;
				q[i]-=d;
				if(num[j]!=tag) --j;
			}
			if(q[i]) return 0;
		}
		return 1;
	}
	inline void main()
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[i]=read(),++b[a[i]];
		sort(a+1,a+n+1);
		for(int i=1;i<=m;++i) c[i]=read();
		l=1,r=n,ret=n;
		while(l<=r)
		{
			if(check(mid)) ret=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ret);
		int tag=0,j=1;
		memset(num,0,sizeof(num));
		for(int i=m;i>=1;--i)
		{
			tag+=c[i]-c[i+1];
			if(c[i]!=c[i+1]) j=1;
			for(;j<=ret&&b[i];++j)
			{
				int d=min(b[i],tag-num[j]);
				num[j]+=d;
				b[i]-=d;
				for(int k=1;k<=d;++k) ans[j].push_back(i);
				if(num[j]!=tag) --j;
			}
		}
		for(int i=1;i<=ret;++i)
		{
			int x=ans[i].size();
			printf("%lld ",x);
			for(auto x:ans[i]) printf("%lld ",x);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}