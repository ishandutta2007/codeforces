#include<cstdio>
#include<iostream>
#include<utility>
#include<set>
using namespace std;
const int o=2e5+10;
int n,q,h[o],cnt,d[o],dfn[o],ed[o],anc[o][20],b[o];multiset<pair<int,int> > s;pair<int,int> di[o*4];
struct Edge{int v,p;}e[o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<=n;pos+=lowbit(pos)) b[pos]+=val;}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=b[pos];return res;}
void dfs(int nw){
	dfn[nw]=++cnt;d[nw]=d[anc[nw][0]]+1;
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^anc[nw][0]) anc[e[i].v][0]=nw,dfs(e[i].v);
	ed[nw]=cnt;
}
inline int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	for(int i=19;i+1;--i) if(d[anc[x][i]]>=d[y]) x=anc[x][i];
	if(x==y) return x;
	for(int i=19;i+1;--i) if(anc[x][i]^anc[y][i]) x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
inline int dis(int x,int y){if(!x||!y) return 0;return d[x]+d[y]-2*d[lca(x,y)];}
pair<int,int> merge(pair<int,int> A,pair<int,int> B){
	int u=0,v=0,D=0,z[4]={A.first,A.second,B.first,B.second};
	for(int i=0;i<3;++i) for(int j=i+1,k;j<4;++j) if((k=dis(z[i],z[j]))>D) D=k,u=z[i],v=z[j];
	if(!D) for(int i=0;i<4;++i) if(z[i]) u=z[i];
	return make_pair(u,v);
}
void chg(int id,int pos,int val,int l=1,int r=n){
	if(l==r){di[id]=make_pair(val,0);return;}
	int md=l+r>>1;
	if(pos<=md) chg(id<<1,pos,val,l,md);
	else chg((id<<1)|1,pos,val,md+1,r);
	di[id]=merge(di[id<<1],di[(id<<1)|1]);
}
pair<int,int> ask(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return di[id];
	int md=l+r>>1;
	if(qr<=md) return ask(id<<1,ql,qr,l,md);
	if(md<ql) return ask((id<<1)|1,ql,qr,md+1,r);
	return merge(ask(id<<1,ql,qr,l,md),ask((id<<1)|1,ql,qr,md+1,r));
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,u,v;i<n;++i) scanf("%d%d",&u,&v),ad(u,v),ad(v,u);
	cnt=0;dfs(1);cnt=0;
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j) anc[j][i]=anc[anc[j][i-1]][i-1];
	for(int opt,u,v;q--;){
		scanf("%d%d",&opt,&u);
		if(opt==1){
			scanf("%d",&v);++cnt;modify(dfn[u],1);modify(dfn[v],1);modify(dfn[u=lca(u,v)],-1);
			if(s.find(make_pair(d[u],u))==s.end()) chg(1,dfn[u],u);
			s.insert(make_pair(d[u],u));
		}
		else if(opt==2){
			scanf("%d",&v);--cnt;modify(dfn[u],-1);modify(dfn[v],-1);modify(dfn[u=lca(u,v)],1);
			s.erase(s.find(make_pair(d[u],u)));
			if(s.find(make_pair(d[u],u))==s.end()) chg(1,dfn[u],0);
		}
		else{
			v=(*s.rbegin()).second;
			for(int i=19;i+1;--i) if(((2*u)>>i)&1) v=anc[v][i];
			if(!v) v=1;
			if(query(ed[v])-query(dfn[v]-1)-cnt){printf("No\n");continue;}
			di[0]=ask(1,dfn[v],ed[v]);
			v=(*s.rbegin()).second;
			for(int i=19;i+1;--i) if((u>>i)&1) v=anc[v][i];
			if(!v) v=1;
			printf((dis(v,di[0].first)<=u&&dis(v,di[0].second)<=u)?"Yes\n":"No\n");
		}
	}
	return 0;
}