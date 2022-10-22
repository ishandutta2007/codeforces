#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,m,q,U[MN],V[MN],W[MN],id[MN],ans[MN],cnt;
const int inf=1e18;
bool in[MN],ein[MN];
struct graph{
	vector<pii >e[MN];
	vector<int>eid[MN];
	int f[MN],vis[MN],fa[MN],len[MN],pid[MN],app[MN];
	priority_queue<pii,vector<pii >,greater<pii > >Q;
	void dij(int S){
		for(int i=1;i<=n;++i)f[i]=inf;
		f[S]=0;Q.push(mp(0,S));
		while(!Q.empty()){
			pii w=Q.top();Q.pop();
			if(vis[w.y])continue;
			vis[w.y]=1;
			int x=w.y;
			for(int i=0;i<e[x].size();++i){
				int v=e[x][i].x,w=e[x][i].y;
				if(f[v]>f[x]+w){
					f[v]=f[x]+w;
					Q.push(mp(f[v],v));
					fa[v]=x;
					pid[v]=eid[x][i];
				}
			}
		}
	}
	void dfs(int x){
		if(in[x]&&in[fa[x]])len[x]++;
		for(int i=0;i<e[x].size();++i){
			int v=e[x][i].x;
			if(fa[v]!=x||app[v])continue;
			app[v]=1;
			len[v]=len[x];
			dfs(v);
		}
	}
}A,B;
int tag[MN<<2];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
void change(int x,int l,int r,int b,int e,int v){
	if(b<=l&&r<=e){tag[x]=min(tag[x],v);return;}
	if(l>e||r<b)return;
	if(b<=mid)change(Ls,l,mid,b,e,v);
	if(e>mid)change(Rs,mid+1,r,b,e,v);
}
void build(int x,int l,int r){
	if(l==r){ans[l]=tag[x];return;}
	tag[Ls]=min(tag[Ls],tag[x]);
	tag[Rs]=min(tag[Rs],tag[x]);
	build(Ls,l,mid);
	build(Rs,mid+1,r);
}
void chk(int x,int y,int z){
	change(1,1,cnt-1,A.len[x],cnt-B.len[y],z+A.f[x]+B.f[y]);
}
signed main(){
	memset(tag,0x3f,sizeof(tag));
	n=read();m=read();q=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		U[i]=u,V[i]=v,W[i]=w;
		A.e[u].pb(mp(v,w));
		A.eid[u].pb(i);
		B.e[v].pb(mp(u,w));
		B.eid[v].pb(i);
		A.e[v].pb(mp(u,w));
		A.eid[v].pb(i);
		B.e[u].pb(mp(v,w));
		B.eid[u].pb(i);
	}
	A.dij(1);
	B.dij(n);
	int x=1;
	while(x){
		in[x]=1;id[x]=++cnt;
		ein[B.pid[x]]=1;
		x=B.fa[x];
	}
	in[0]=1;
	A.dfs(1);B.dfs(n);
	for(int i=1;i<=m;++i){
		if(!ein[i])chk(U[i],V[i],W[i]),chk(V[i],U[i],W[i]);
	}
	build(1,1,cnt-1);
	while(q--){
		int t=read(),x=read();
		int u=U[t],v=V[t],w=W[t];
		if(id[u]>id[v])swap(u,v);			
		if(!ein[t])printf("%lld\n",min(A.f[n],min(A.f[u]+x+B.f[v],A.f[v]+x+B.f[u])));
		else if(w>=x){
			printf("%lld\n",A.f[n]-w+x);
		}
		else{
			printf("%lld\n",min(ans[id[u]],A.f[n]-w+x));
		}
	}
	return 0;
}