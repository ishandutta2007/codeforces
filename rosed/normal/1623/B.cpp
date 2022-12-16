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
	int T,n; 
	int maxn,pos;
	struct node
	{
		int l,r,id,ans;
	}a[N];
	typedef pair<int,int> p;
	map<p,bool> q;
	inline bool check(int l,int r)
	{
		if(l>r) return 1;
		return q[p(l,r)];
	}
	inline void dfs(int l,int r)
	{
		if(l==r){printf("%lld %lld %lld\n",l,r,l);return;}
		for(int i=l;i<=r;++i)
		{
			if(check(l,i-1)&&check(i+1,r))
			{
				printf("%lld %lld %lld\n",l,r,i);
				dfs(l,i-1);dfs(i+1,r);
				return;
			}
		}
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			q.clear();
			n=read();pos=maxn=0;
			for(int i=1;i<=n;++i)
			{
				a[i].l=read(),a[i].r=read(),a[i].id=i;
				q[p(a[i].l,a[i].r)]=1;
				if(a[i].r-a[i].l+1>maxn)
				{
					maxn=a[i].r-a[i].l+1;
					pos=i;
				}
			}
			dfs(a[pos].l,a[pos].r);
			puts("");
		}
	}
}
signed main()
{
	red::main();
	return 0;
}