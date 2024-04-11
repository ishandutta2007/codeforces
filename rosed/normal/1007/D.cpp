#include<bits/stdc++.h>
using namespace std;
namespace red{
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=4e5+10,M=6e6+10,inf=1<<30;
	int n,m;
	vector<int> eg[N];
	int head[M],cnt;
	struct point
	{
		int nxt,to;
		point(){}
		point(const int &nxt,const int &to):nxt(nxt),to(to){}
	}a[M<<3];
	inline void link(int x,int y)
	{
		a[++cnt]=(point){head[x],y};head[x]=cnt;
		a[++cnt]=(point){head[y^1],x^1};head[y^1]=cnt;
	}
	int son[N],str[N],top[N],f[N],dep[N],id[N],tot;
	inline void dfs1(int now,int fa)
	{
		dep[now]=dep[fa]+1;f[now]=fa;
		str[now]=1;
		int maxson=-1;
		for(int i=eg[now].size()-1;~i;--i)
		{
			int t=eg[now][i];
			if(t==fa) continue;
			dfs1(t,now);
			str[now]+=str[t];
			if(str[t]>maxson) maxson=str[t],son[now]=t;
		}
	}
	inline void dfs2(int now,int topf)
	{
		id[now]=++tot;
		top[now]=topf;
		if(son[now]) dfs2(son[now],topf);
		for(int i=eg[now].size()-1;~i;--i)
		{
			int t=eg[now][i];
			if(t==f[now]||t==son[now]) continue;
			dfs2(t,t);
		}
	}
	vector<int> ans[N<<2];
	inline void update(int tl,int tr,int l,int r,int p,int k)
	{
		if(tl<=l&&r<=tr)
		{
			ans[p].push_back(k);
			return;
		}
		if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
		if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
	}
	int sum;
	int ql[N<<2],qr[N<<2];
	inline void build(int l,int r,int p)
	{
		ql[p]=++sum,qr[p]=(sum+=ans[p].size());
		if(p>1)
		{
			link(ql[p]<<1|1,qr[p>>1]<<1|1);
			if(ans[p].size()) link(qr[p>>1]<<1,ans[p][0]^1);
		}
		for(int i=0;i<ans[p].size();++i)
		{
			int x=ans[p][i];
			link(ql[p]+i<<1|1,x^1);
			link(ql[p]+i+1<<1|1,ql[p]+i<<1|1);
			if(i) link(ql[p]+i-1<<1,x^1);
		}
		if(l==r) return;
		build(l,mid,ls(p));
		build(mid+1,r,rs(p));
	}
	inline void tree_update(int x,int y,int k)
	{
		while(top[x]^top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			update(id[top[x]],id[x],1,n,1,k);
			x=f[top[x]];
		}
		if(dep[x]>dep[y]) swap(x,y);
		if(x!=y) update(id[x]+1,id[y],1,n,1,k);
	}
	int dfn[M],low[M],st[M],col[M];
	int idx,topf,num;
	inline void tarjan(int now)
	{
		dfn[now]=low[now]=++idx;
		st[++topf]=now;
		for(int i=head[now];i;i=a[i].nxt)
		{
			int t=a[i].to;
			if(!dfn[t])
			{
				tarjan(t);
				low[now]=min(low[now],low[t]);
			}
			else if(!col[t]) low[now]=min(low[now],dfn[t]);
		}
		if(dfn[now]==low[now])
		{
			col[now]=++num;
			while(st[topf]!=now) col[st[topf--]]=num;
			--topf;
		}
	}
	inline void main()
	{
		n=read();sum=n;
		for(int x,y,i=1;i<n;++i)
		{
			x=read(),y=read();
			eg[x].push_back(y);
			eg[y].push_back(x);
		}
		dfs1(1,0);
		dfs2(1,1);
		m=read();
		for(int a,b,c,d,i=1;i<=m;++i)
		{
			a=read(),b=read(),c=read(),d=read();
			tree_update(a,b,i<<1);tree_update(c,d,i<<1|1);
		}
		build(1,n,1);
		for(int i=1;i<=sum*2+1;++i)
			if(!dfn[i]) tarjan(i);
		for(int i=1;i<=m;++i)
			if(col[i<<1]==col[i<<1|1]) return(void)puts("NO");
		puts("YES");
		for(int i=1;i<=m;++i)
			puts(col[i<<1]<col[i<<1|1]?"1":"2");
	}
}
signed main()
{
	//freopen("haha.in","r",stdin);
	red::main();
	return 0;
}