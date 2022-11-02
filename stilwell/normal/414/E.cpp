#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

struct Link_Cut_Tree
{
	int size[400005],l[400005],r[400005],fa[400005];
	inline void splay_updata(int x){size[x]=size[l[x]]+size[r[x]]+1;}
	inline bool top(int p){return (!fa[p])||(l[fa[p]]!=p&&r[fa[p]]!=p);}
	inline void zig(int x)
	{
		int y=fa[x],z=fa[y];
		if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
		fa[x]=z,fa[y]=x,fa[r[x]]=y;
		l[y]=r[x],r[x]=y;
		splay_updata(y);
	}
	inline void zag(int x)
	{
		int y=fa[x],z=fa[y];
		if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
		fa[x]=z,fa[y]=x,fa[l[x]]=y;
		r[y]=l[x];l[x]=y;
		splay_updata(y);
	}
	inline void splay(int x)
	{
		int y,z;
		while(!top(x))
		{
			y=fa[x],z=fa[y];
			if(!top(y))
			{
				if(l[z]==y){if(l[y]==x)zig(y),zig(x);else zag(x),zig(x);}
				else{if(l[y]==x)zig(x),zag(x);else zag(y),zag(x);}
			}
			else{if(l[y]==x)zig(x);else zag(x);}
		}
		splay_updata(x);
	}
	inline int access(int x)
	{
		int y=0;
		for(;x;y=x,x=fa[x])
		{
			splay(x);
			r[x]=y;
			splay_updata(x);
		}
		return y;
	}
	int BST_K(int x,int K)
	{
		while(x)
		{
			if(size[r[x]]+1==K)return x;
			if(size[r[x]]+1>K)
			x=r[x];
			else 
			{
				K=K-1-size[r[x]];
				x=l[x];
			}
		}
	}
	void change_fa(int u,int v,int pre)
	{
		access(pre);access(v);
		splay(u);fa[u]=v;
	}
}lct;

struct Euler_Tour_Tree
{
	int BST[400005],add[400005],Max[400005],Min[400005];
	int size[400005],fa[400005],l[400005],r[400005];
	int id[400005],st[400005],root;
	void splay_updata(int x)
	{
		Max[x]=Min[x]=BST[x];
		if(l[x])
		{
			if(Max[l[x]]>Max[x])Max[x]=Max[l[x]];
			if(Min[l[x]]<Min[x])Min[x]=Min[l[x]];
		}
		if(r[x])
		{
			if(Max[r[x]]>Max[x])Max[x]=Max[r[x]];
			if(Min[r[x]]<Min[x])Min[x]=Min[r[x]];
		}
		size[x]=size[l[x]]+size[r[x]]+1;
	}
	void zig(int x)
	{
		int y=fa[x],z=fa[y];
		if(l[z]==y)l[z]=x;else r[z]=x;
		fa[x]=z,fa[y]=x,fa[r[x]]=y;
		l[y]=r[x],r[x]=y;
		splay_updata(y);
	}
	void zag(int x)
	{
		int y=fa[x],z=fa[y];
		if(l[z]==y)l[z]=x;else r[z]=x;
		fa[x]=z,fa[y]=x,fa[l[x]]=y;
		r[y]=l[x];l[x]=y;
		splay_updata(y);
	}
	void Add(int x,int val)
	{
		BST[x]+=val;
		Min[x]+=val;
		Max[x]+=val;
		add[x]+=val;
	}
	void splay_down(int x)
	{
		if(add[x])
		{
			if(l[x])Add(l[x],add[x]);
			if(r[x])Add(r[x],add[x]);
			add[x]=0;
		}
	}
	void splay(int x)
	{
		int y,z;
		y=x;z=1;st[1]=x;
		while(fa[y]){++z;y=fa[y];st[z]=y;}
		for(y=z;y>=1;--y)splay_down(st[y]);
		while(fa[x])
		{
			y=fa[x],z=fa[y];
			if((z)&&(y!=root))
			{
				if(l[z]==y){if(l[y]==x)zig(y),zig(x);else zag(x),zig(x);}
				else{if(l[y]==x)zig(x),zag(x);else zag(y),zag(x);}
			}
			else{if(l[y]==x)zig(x);else zag(x);}
		}
		root=x;
		splay_updata(root);
	}
	void splay_(int x)
	{
		int y,z;
		y=x;z=1;st[1]=x;
		while(fa[y]){++z;y=fa[y];st[z]=y;}
		for(y=z;y>=1;--y)splay_down(st[y]);
		while(fa[x]!=root)
		{
			y=fa[x],z=fa[y];
			if((z!=root)&&(fa[y]!=root))
			{
				if(l[z]==y){if(l[y]==x)zig(y),zig(x);else zag(x),zig(x);}
				else{if(l[y]==x)zig(x),zag(x);else zag(y),zag(x);}
			}
			else{if(l[y]==x)zig(x);else zag(x);}
		}
		splay_updata(x);
	}
	int splay_build(int p,int q,int f)
	{
	    int mid;
	    mid=(p+q)>>1;
	    fa[id[mid]]=f;
	    if(mid!=p)l[id[mid]]=splay_build(p,mid-1,id[mid]);
	    if(mid!=q)r[id[mid]]=splay_build(mid+1,q,id[mid]);
	    splay_updata(id[mid]);
	    return id[mid];
	}
	int find(int d)
	{
		if(d>Max[root])return 0;
		int x=root;
		for(;;)
		{
			splay_down(x);
			if(r[x]&&Min[r[x]]<=d&&Max[r[x]]>=d)x=r[x];
			else
			{
				if(BST[x]==d){splay(x);return x;}
				x=l[x];
			}
		}
	}
	void change_fa(int u,int v,int L,int R,int h)
	{
		splay(L);splay_(R);
		fa[l[r[root]]]=0;
		u=l[r[root]];
		l[r[root]]=0;
		splay_updata(r[root]);
		splay_updata(root);
		Add(u,-h);
		while(l[u])u=l[u];
		splay(u);
		splay(v);
		l[u]=l[root];fa[l[u]]=u;
		l[root]=u;fa[u]=root;
		splay_updata(u);
		splay_updata(root);
	}
}ett;

int n,m,i,j,k,opt,h,u,v,lca,ans,tot,L,R;
int fa[400005],son[400005],pre[400005],next[400005],tail[400005];

void dfs(int x,int d)
{
	ett.BST[x]=ett.BST[x+n]=d;
	ett.id[++tot]=x;
	lct.size[x]=1;
	for(int i=son[x];i;i=next[i])
	{
		lct.fa[i]=x;
		dfs(i,d+1);
	}
	ett.id[++tot]=x+n;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		for(j=0;k;--k)
		{
			scanf("%d",&u);
			if(!son[i])son[i]=j=u;
			else next[j]=u,pre[u]=j,j=u;
			fa[u]=i;
		}
		tail[i]=j;
	}
	tot=0;dfs(1,0);
	ett.root=ett.splay_build(1,tot,0);
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&u,&v);
			lct.access(u);
			lct.splay(u);
			ans=lct.size[u];
			lca=lct.access(v);
			lct.splay(v);
			ans+=lct.size[v];
			lct.splay(lca);
			ans-=2*(lct.size[lct.l[lca]]+1);
			printf("%d\n",ans);
		}
		if(opt==2)
		{
			scanf("%d%d",&u,&h);
			lct.access(u);
			lct.splay(u);
			k=lct.BST_K(u,2);
			v=lct.BST_K(u,h+1);
			lct.change_fa(u,v,k);
			if(pre[u])L=pre[u]+n;else L=fa[u];
			if(next[u])R=next[u];else R=fa[u]+n;
			if(!pre[u])
			{
				if(!next[u])son[fa[u]]=tail[fa[u]]=0;
				else son[fa[u]]=next[u],pre[next[u]]=0;
			}
			else
			{
				if(!next[u])tail[fa[u]]=pre[u],next[pre[u]]=0;
				else next[pre[u]]=next[u],pre[next[u]]=pre[u];
			}
			pre[u]=tail[v];next[u]=0;
			next[tail[v]]=u;tail[v]=u;
			fa[u]=v;
			ett.change_fa(u,v+n,L,R,h-1);
		}
		if(opt==3)
		{
			scanf("%d",&v);
			ans=ett.find(v);
			if(ans>n)ans-=n;
			printf("%d\n",ans);
		}
	}
}