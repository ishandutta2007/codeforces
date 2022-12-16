#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define fail return (void)puts("-1")
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=3e5+10,p=998244353;
	typedef pair<int,int> pr;
	priority_queue<pr> q;
	int haku,n,m;
	int a[N],ret,sum=1,ans=1;
	bool vis[N];
	inline void main()
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[i]=read(),q.push(pr(a[i],i));
		for(int i=1;i<=m;++i)
		{
			ret+=q.top().first;
			vis[q.top().second]=1;
			q.pop();
		}
		printf("%lld ",ret);
		int i=1,s=0;
		while(!vis[i]) ++i;
		for(;i<=n&&s<m;++i)
		{
			if(vis[i])
			{
				sum=sum*ans%p;
				ans=1;
				++s;
				continue;
			}
			++ans;
		}
		printf("%lld\n",sum%p);
	}
}
signed main()
{
	red::main();
	return 0;
}