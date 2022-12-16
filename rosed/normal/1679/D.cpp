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
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10;
	int n,m,k;
	int a[N];
	struct edge
	{
		int x,y;
	}e[N];
	int rd[N],dis[N];
	vector<int> eg[N];
	queue<int> q;
	int dfn[N],low[N],st[N],col[N];
	int idx,top,num;
	inline bool tarjan(int now)
	{
		dfn[now]=low[now]=++idx;
		st[++top]=now;
		for(int t:eg[now])
		{
			if(!dfn[t])
			{
				if(tarjan(t)) return 1;
				low[now]=min(low[now],low[t]);
			}
			else if(!col[t]) low[now]=min(low[now],dfn[t]);
		}
		if(dfn[now]==low[now])
		{
			int tot=1;
			col[now]=++num;
			while(st[top]!=now)
			{
				col[st[top--]]=num;
				++tot;
			}
			--top;
			if(tot>=2) return 1; 
		}
		return 0;
	}
	inline bool check(int lim)
	{
		while(!q.empty()) q.pop();

		idx=top=num=0;
		for(int i=1;i<=n;++i)
		{
			rd[i]=0;
			eg[i].clear();
			dis[i]=1;
			dfn[i]=low[i]=0;
			col[i]=0;
		}
		for(int i=1;i<=m;++i)
		{
			int x=e[i].x,y=e[i].y;
			if(a[x]>lim||a[y]>lim) continue;
			eg[x].emplace_back(y);
			++rd[y];
		}
		for(int i=1;i<=n;++i)
		{
			if(a[i]>lim) continue;
			if(!dfn[i])
			{
				if(tarjan(i))
				{
					return 1;
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(a[i]>lim) continue;
			if(!rd[i]) {q.push(i);}
		}
		int maxn=0;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			maxn=max(maxn,dis[now]);
			for(int t:eg[now])
			{
				dis[t]=max(dis[t],dis[now]+1);
				--rd[t];
				if(!rd[t]) q.push(t);
			}
		}
		return maxn>=k;
	}
	inline void main()
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<=m;++i)
		{
			cin>>e[i].x>>e[i].y;
		}
		int l=1,r=1e9+7;
		while(l<=r)
		{
			if(check(mid)) r=mid-1;
			else l=mid+1;
		}
		if(r==1e9+7) cout<<"-1\n";
		else cout<<r+1<<'\n';
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
6 7 4
4 10 3 2 1 5
1 2
1 3
3 4
4 5
5 6
6 2
2 5

*/