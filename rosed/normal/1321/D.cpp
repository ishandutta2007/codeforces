#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define double long double
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
	const int N=2e5+10;
	int haku;
	int n,m,k;
	int ansmax,ansmin;
	vector<int> eg[N];
	int dis[N],sum[N];
	bool vis[N];
	int a[N];
	queue<int> q;
	set<int> v[N];
	inline void spfa(int st)
	{
		q.push(st);
		vis[st]=1;sum[st]=1;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			int s=eg[now].size();
			for(int i=0;i<s;++i)
			{
				int t=eg[now][i];
				if(!vis[t])
				{
					dis[t]=dis[now]+1;
					sum[t]=1;
					vis[t]=1;
					q.push(t);
				}
				else if(dis[t]==dis[now]+1) ++sum[t];
			}
		}
	}
	inline void main()
	{
		n=read(),m=read();
		for(int x,y,i=1;i<=m;++i)
		{
			x=read(),y=read();
			
			if(v[y].count(x)) continue;
			v[y].insert(x);
			
			eg[y].push_back(x);
		}
		k=read();
		for(int i=1;i<=k;++i) a[i]=read();
		spfa(a[k]);
		for(int i=1;i<k;++i)
		{
			if(sum[a[i]]>=2||dis[a[i]]!=dis[a[i+1]]+1)	++ansmax;
			if(dis[a[i]]!=dis[a[i+1]]+1) ++ansmin;
		}
		cout<<ansmin<<' '<<ansmax<<endl;
	}
}
signed main()
{
	red::main();
	return 0;
}