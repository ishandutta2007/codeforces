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
	const int N=4e5+10;
	int haku;
	int n,m,idx,rt;
	vector<int> eg[N],id[N];
	int ans[N],rd[N];
	inline void dfs(int now,int fa)
	{
		int sum=eg[now].size();
		for(int i=0;i<sum;++i)
		{
			int t=eg[now][i];
			if(t==fa) continue;
			ans[id[now][i]]=idx++;
			dfs(t,now);
		}
	}
	inline void main()
	{
		n=read();
		for(int x,y,i=1;i<n;++i)
		{
			x=read(),y=read();
			eg[x].push_back(y);id[x].push_back(i);
			eg[y].push_back(x);id[y].push_back(i);
			++rd[x],++rd[y];
		}
		for(int i=1;i<=n;++i)
		{
			if(rd[i]>=3)
			{
				rt=i;
				break;
			}
		}
		if(!rt)
		{
			for(int i=0;i<n-1;++i) printf("%lld\n",i);
			return;
		}
		for(int i=0;i<3;++i)
		{
			ans[id[rt][i]]=++idx;
		}
		for(int i=1;i<n;++i)
		{
			if(ans[i]) printf("%lld\n",ans[i]-1);
			else printf("%lld\n",idx++);
		}
	}
}
signed main()
{
	red::main();
	return 0;
}