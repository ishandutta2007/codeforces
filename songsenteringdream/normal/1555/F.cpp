#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
const int o=3e5+10;
int n,q,anc[o][20],fa[o],h[o],cnt,uu[o*2],vv[o*2],ww[o*2],dfn[o],ed[o],dis[o],ft[o];bool ans[o*2];
struct Edge{int v,p,w;}e[o*2];
inline void ad(int U,int V,int W){e[++cnt].v=V;e[cnt].p=h[U];e[h[U]=cnt].w=W;}
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
inline bool merge(int x,int y){
	x=fr(x);y=fr(y);
	if(x==y) return false;
	fa[x]=y;return true;
}
void dfs(int nw){
	dfn[nw]=++cnt;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^anc[nw][0]) dis[e[i].v]=dis[anc[e[i].v][0]=nw]^e[i].w,dfs(e[i].v);
	ed[nw]=cnt;
}
inline bool ancoff(int x,int y){return dfn[x]<=dfn[y]&&ed[y]<=ed[x];}
inline int lca(int x,int y){
	if(ancoff(x,y)) return x;
	for(int i=19;i+1;--i) if(!ancoff(anc[x][i],y)) x=anc[x][i];
	return anc[x][0];
}
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<=n+1;pos+=lowbit(pos)) ft[pos]+=val;}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=ft[pos];return res;}
inline void change(int x,int y){for(;x^y;x=anc[x][0]) modify(dfn[x],1),modify(ed[x]+1,-1);}
int main(){
	read(n);read(q);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=q;++i){
		read(uu[i]);read(vv[i]);read(ww[i]);
		if(merge(uu[i],vv[i])) ad(uu[i],vv[i],ww[i]),ad(vv[i],uu[i],ww[i]),ans[i]=1;
	}
	cnt=0;for(int i=1;i<=n;++i) if(!dfn[i]) dfs(i);ed[0]=cnt;
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j) anc[j][i]=anc[anc[j][i-1]][i-1];
	for(int i=1,j;i<=q;++i) if(!ans[i]&&query(dfn[uu[i]])+query(dfn[vv[i]])==2*query(dfn[j=lca(uu[i],vv[i])]))
		if(ww[i]^dis[uu[i]]^dis[vv[i]]==1) ans[i]=1,change(uu[i],j),change(vv[i],j);
	for(int i=1;i<=q;++i) if(ans[i]) printf("YES\n");else printf("NO\n");
	return 0;
}