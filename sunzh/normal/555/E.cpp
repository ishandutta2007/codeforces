#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n,m,q;
int cnt;
namespace tarjan{
	int tot=1;
	int head[200010],nxt[400010],to[400010],belong[200010];
	void add(int x,int y){
		nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
	}
	int dfn[200010],low[200010];
	int tp,fn;
	int stk[200010];
	bool used[400010],vis[400010];
	void tarjan(int x){
		stk[++tp]=x;
		dfn[x]=low[x]=++fn;vis[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			if(used[i]||used[i^1]) continue ;
			used[i]=1;
			int v=to[i];
			if(!dfn[v]){
				tarjan(v);
				low[x]=min(low[x],low[v]);
			}
			else if(vis[v]) low[x]=min(low[x],dfn[v]);
		}
		if(low[x]==dfn[x]){
			++cnt;
			while(stk[tp]!=x){
				vis[stk[tp]]=0;
				belong[stk[tp]]=cnt;
				--tp;
			}
			vis[x]=0,belong[x]=cnt;
			--tp;
		}
	}
}
namespace LCA{
	int tot=0;
	int head[200010],nxt[400010],to[400010],belong[200010];
	int dep[200010],fa[200010],siz[200010],top[200010],son[200010];
	int tag1[200010],tag2[200010];
	void add(int x,int y){
		nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
	}
	void dfs1(int x,int f,int t){
		fa[x]=f,belong[x]=t,dep[x]=dep[f]+1,siz[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int v=to[i];
			if(v==f) continue ;
			dfs1(v,x,t);
			siz[x]=siz[v];
			if(siz[v]>siz[son[x]]) son[x]=v; 
		}
	}
	void dfs2(int x,int topf){
		top[x]=topf;
		if(!son[x]) return ;
		dfs2(son[x],topf);
		for(int i=head[x];i;i=nxt[i]){
			int v=to[i];
			if(v==fa[x]||v==son[x]) continue ;
			dfs2(v,v);
		}
	}
	int LCA(int x,int y){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
		if(dep[x]<dep[y]) return x;
		else return y;
	}
	bool check(int x,int f){
		for(int i=head[x];i;i=nxt[i]){
			int v=to[i];
			if(v==f) continue ;
			if(check(v,x)==0) return 0;
			tag1[x]+=tag1[v],tag2[x]+=tag2[v]; 
		}
		if(tag1[x]&&tag2[x]) return 0;
		return 1;
	}
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		tarjan::add(u,v);tarjan::add(v,u);
	}
	for(int i=1;i<=n;++i) if(!tarjan::dfn[i]) tarjan::tarjan(i);
	for(int i=1;i<=n;++i){
		for(int j=tarjan::head[i];j;j=tarjan::nxt[j]){
			int v=tarjan::to[j];
			if(tarjan::belong[i]==tarjan::belong[v]) continue ;
			LCA::add(tarjan::belong[i],tarjan::belong[v]);
		}
	}
	for(int i=1;i<=cnt;++i){
		if(!LCA::belong[i]) LCA::dfs1(i,0,i),LCA::dfs2(i,i);
	}
	for(int i=1;i<=q;++i){
		int s=read(),t=read();
		s=tarjan::belong[s];t=tarjan::belong[t];
		if(LCA::belong[s]!=LCA::belong[t]){
			printf("No\n");exit(0);
		}
		LCA::tag1[s]+=1,LCA::tag2[t]+=1;
		int lca=LCA::LCA(s,t);
		LCA::tag1[lca]-=1,LCA::tag2[lca]-=1;
	}
	for(int i=1;i<=cnt;++i) if(LCA::belong[i]==i){
		if(LCA::check(i,0)==0){
			printf("No\n");exit(0);
		}
	}
	printf("Yes\n");return 0;
}