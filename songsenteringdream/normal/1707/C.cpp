#include<cstdio>
#include<iostream>
using namespace std;
const int o=4e5+10;
int n,m,h[o],cnt,fa[o],U[o],V[o],tot,dfn[o],ed[o],a[o],anc[o][20],d[o];
struct Edge{int v,p;}e[o];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
void dfs(int nw,int fa){
	dfn[nw]=++cnt;d[nw]=d[anc[nw][0]=fa]+1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa) dfs(e[i].v,nw);
	ed[nw]=cnt;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(fr(u)^fr(v)) fa[fr(u)]=fr(v),ad(u,v),ad(v,u);
		else U[++tot]=u,V[tot]=v;
	}
	dfs(1,cnt=0);
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j) anc[j][i]=anc[anc[j][i-1]][i-1];
	for(int i=1;i<=tot;++i){
		if(dfn[U[i]]>dfn[V[i]]) swap(U[i],V[i]);
		if(ed[U[i]]>=ed[V[i]]){
			++a[dfn[V[i]]];--a[ed[V[i]]+1];
			for(int j=19;j+1;--j) if(d[anc[V[i]][j]]>d[U[i]]) V[i]=anc[V[i]][j];
			++a[1];--a[dfn[V[i]]];++a[ed[V[i]]+1];--a[n+1];
		}
		else ++a[dfn[U[i]]],--a[ed[U[i]]+1],++a[dfn[V[i]]],--a[ed[V[i]]+1];
	}
	for(int i=1;i<=n;++i) a[i]+=a[i-1];
	for(int i=1;i<=n;++i) putchar(48+(a[dfn[i]]==tot));
	return 0;
}