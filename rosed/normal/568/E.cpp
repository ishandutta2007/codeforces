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
	const int N=2e5+10,inf=1e18+7;
	int n,m;
	int a[N],b[N],l[N],p[N],f[N],g[N],v[N],ans[N];
	inline void get(int i,int k,int &x)
	{
		int t=lower_bound(b+1,b+m+1,k)-b-1;
		v[t]=1,x=ans[i]=b[t];
	}
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i) a[i]=read(),f[i]=inf;
		++n;
		a[n]=f[n]=inf;
		m=read();
		for(int i=1;i<=m;++i) b[i]=read();
		sort(b+1,b+m+1);
		for(int i=1;i<=n;++i)
		{
			if(~a[i])
			{
				int j=lower_bound(f+1,f+n+1,a[i])-f-1;
				l[i]=j+1,p[i]=g[j],f[j+1]=a[i],g[j+1]=i;
			}
			else
			{
				for(int j=n,t=m;t;--t)
				{
					while(f[j]>=b[t]) --j;
					f[j+1]=b[t],g[j+1]=i;
				}
			}
		}
		int i=l[n],j=n,x=a[n];
		while(i--)
		{
			if(~a[j])
			{
				if(!~a[p[j]]) get(p[j],a[j],x);
				else x=a[p[j]];
				j=p[j];
			}
			else
			{
				bool ok=0;
				for(int s=j-1;s;--s)
				{
					if(~a[s]&&l[s]==i&&a[s]<x)
					{
						x=a[j=s],ok=1;
						break;
					}
				}
				if(ok) continue;
				for(int s=j-1;s;--s)
				{
					if(!~a[s])
					{
						get(s,x,x),j=s;
						break;
					}
				}
			}
		}
		for(int i=1,j=1;i<=n;++i)
		{
			if(!~a[i])
			{
				if(ans[i]) continue;
				while(v[j]) ++j;
				v[j]=1,ans[i]=b[j];
			}
			else ans[i]=a[i];
		}
		for(int i=1;i<n;++i) printf("%lld ",ans[i]);
	}
}
signed main()
{
	red::main();
	return 0;
}