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
int n,fa[MN],siz[MN],rt;
vector<int>e[MN],g[MN];
bool isrt[MN];
void dfs(int x){
	siz[x]=1;
	int mx=0;
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;dfs(v);
		siz[x]+=siz[v];mx=max(mx,siz[v]);
	}
	if(max(n-siz[x],mx)<=n/2)rt=x,isrt[x]=1;
}
int w[MN];
#define piii pair<pii,int>
vector<piii >ans;
bool vis[MN];
int up[MN];
void solve(int x){
	int lst=fa[x];
	up[x]=x;
//	cerr<<"DFS: "<<x<<endl;
	for(int i=0;i<e[x].size();++i)
		if(e[x][i]==fa[x]){
			swap(e[x][0],e[x][i]);
			break;
		}
	vector<pii >st;
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;
		solve(v);
		if(isrt[x]){
	//		cerr<<"      "<<x<<"  "<<up[v]<<" "<<1<<endl;
			g[x].pb(up[v]);
			g[up[v]].pb(x);
			continue;
		}
//		{
//			if(v!=up[v])ans.pb(mp(mp(x,v),up[v]));
//			g[x].pb(up[v]);
//			g[up[v]].pb(x);
//			cerr<<"        "<<x<<" "<<up[v]<<" 2"<<endl;
//		}
		st.pb(mp(v,up[v]));
		lst=up[v];//x's fa
		if(up[x]==x)up[x]=v;
	}
	st.pb(mp(x,x));
//	cerr<<"FK "<<x<<endl;
	for(int i=0;i+1<st.size();++i){
		if(i!=0) {
			ans.pb(mp(mp(st[i-1].y,x),st[i].x));
		//	cerr<<"fk: "<<up[st[i-1].x]<<" "<<x<<" "<<st[i].x<<endl;
		}
		else{
			ans.pb(mp(mp(fa[x],x),st[i].x));
		//	cerr<<"fk: "<<fa[x]<<" "<<x<<" "<<st[i].x<<endl;
		}
	//	cerr<<"FKFK: "<<ans.size()<<endl;
//		cerr<<"fk: "<<x<<" "<<st[i].x<<" "<<st[i].y<<endl;
		g[st[i].y].pb(st[i+1].x),g[st[i+1].x].pb(st[i].y);
//		cerr<<"        "<<st[i].y<<" "<<st[i+1].x<<endl;
	}
//	cerr<<"dfs "<<x<<": "<<up[x]<<endl;
//	if(x==9)exit(0);
}

void work(int x){
	if(vis[x])return;
	vis[x]=1;
	siz[x]=1;
	int son=0;
	for(int i=0;i<g[x].size();++i){
		int v=g[x][i];
		if(vis[v])continue;
//		cerr<<"  "<<x<<" "<<v<<endl;
//		cerr<<"FKFK"<<endl;
		fa[v]=x;work(v);
		siz[x]+=siz[v];
		if(siz[v]==(n+1)/2)continue;
		if(siz[son]<siz[v])son=v;
		if(w[v]!=v){
			ans.pb(mp(mp(x,v),w[v]));
//			cerr<<"     "<<x<<" "<<w[v]<<endl;
		}
//		else cerr<<"    "<<x<<" "<<v<<endl;
	}
	if(siz[son]<=siz[x]/2)w[x]=x;
	else w[x]=w[son];
}
set<int>E[MN];
int tot=0;
void DFS(int x){
	vis[x]=1;tot++;
	for(auto v:E[x]){
		if(!vis[v])DFS(v);
	}
}
signed main(){

	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1);
	fa[rt]=0;
//	cerr<<"FKFK"<<endl;
	solve(rt);
	fa[rt]=0;
	work(rt);
	printf("%lld\n",(int)ans.size());
	for(auto i:ans){
		printf("%lld %lld %lld\n",i.x.x,i.x.y,i.y);
	}
	return 0;
}