#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int n,h[o],cnt,s[o],hs[o],d[o],dfn[o],nfd[o],fa[o],tp[o];long long b1[o],b2[o],ans,sr[o],sdO[o];
struct Egde{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
void Dfs(int nw){
	d[nw]=d[fa[nw]]+1;s[nw]=1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa[nw])
		fa[e[i].v]=nw,Dfs(e[i].v),s[nw]+=s[e[i].v],hs[nw]=(s[hs[nw]]>s[e[i].v]?hs[nw]:e[i].v);
}
void dfs(int nw,int ld){
	tp[nw]=ld;nfd[dfn[nw]=++cnt]=nw;
	if(hs[nw]) dfs(hs[nw],ld);
	for(int i=h[nw];i;i=e[i].p) if(e[i].v-fa[nw]&&e[i].v-hs[nw]) dfs(e[i].v,e[i].v);
}
inline int lca(int x,int y){
	for(;tp[x]^tp[y];y=fa[tp[y]]) if(d[tp[x]]>d[tp[y]]) swap(x,y);
	return d[x]<d[y]?x:y;
}
inline int dis(int x,int y){return d[x]+d[y]-2*d[lca(x,y)];}
inline int jmp(int x,int y,int stp){
	int Lca=lca(x,y);
	if(d[x]-d[Lca]<stp) stp=d[x]+d[y]-2*d[Lca]-stp,x=y;
	for(;d[x]-d[fa[tp[x]]]<=stp;x=fa[tp[x]]) stp-=d[x]-d[fa[tp[x]]];
	return nfd[dfn[x]-stp];
}
struct circ{int v,r;circ(int v_=0,int r_=0):v(v_),r(r_){}}c[o];
inline bool in(circ A,circ B){return A.r+dis(A.v,B.v)<=B.r;}
inline circ merge(circ A,circ B){
	if(!A.v) return B;
	if(A.r>B.r) swap(A,B);
	int ds=dis(A.v,B.v);
	if(A.r+ds<=B.r) return B;
	return circ(jmp(A.v,B.v,(B.r-A.r+ds)/2),(A.r+B.r+ds)/2);
}
inline int lowbit(int x){return x&-x;}
inline void chg(int pos,int val){for(int i=pos;i<=cnt;i+=lowbit(i)) b1[i]+=val,b2[i]+=pos*1ll*val;}
inline long long ask(int pos){long long res=0;for(int i=pos;i;i-=lowbit(i)) res+=(pos+1ll)*b1[i]-b2[i];return res;}
inline void modify(int u,int val){for(;u;u=fa[tp[u]]) chg(dfn[tp[u]],val),chg(dfn[u]+1,-val);}
inline long long query(int u){long long res=0;for(;u;u=fa[tp[u]]) res+=ask(dfn[u])-ask(dfn[tp[u]]-1);return res;}
void slv(int l,int r){
	if(l==r) return;
	int md=l+r>>1,t1=md,t2=md+1;circ L(0,0);
	slv(l,md);slv(md+1,r);
	sr[md]=sdO[md]=0;c[md]=circ(0,0);
	for(int i=md+1;i<=r;++i) sr[i]=sr[i-1]+(c[i]=merge(c[i-1],circ(i,0))).r,sdO[i]=sdO[i-1]+d[c[i].v];
	for(int i=md;i>=l;--i){
		L=merge(L,circ(i,0));
		for(L=merge(L,circ(i,0));t2<=r&&!in(L,c[t2]);modify(c[t2++].v,2));
		for(;t1+1<t2&&in(c[t1+1],L);modify(c[++t1].v,-2));
		ans+=L.r*2ll*(t1-md)+(sr[r]-sr[t2-1])*2+sr[t2-1]-sr[t1]+(L.r+d[L.v])*(t2-t1-1ll)+sdO[t2-1]-sdO[t1]-query(L.v);
	}
	for(int i=t1+1;i<t2;++i) modify(c[i].v,-2);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(i+n,u),ad(u,i+n),ad(i+n,v),ad(v,i+n);
	Dfs(1);cnt=0;dfs(1,1);
	slv(1,n);
	printf("%lld",ans/2);
	return 0;
}