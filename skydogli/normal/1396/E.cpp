#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
#define itset set<int>::iterator
#define piiset set<pii >::iterator
int fa[MN],siz[MN],w[MN],dep[MN],rt;
vector<int>edge[MN],fk[MN];
set<pii >S[MN];
set<int> Edg[MN];
int n,k,Minans,Maxans;
void dfs1(int x,int fa){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(v==fa)continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[w[x]])w[x]=v;
	}
	if(max(siz[w[x]],n-siz[x])<=n/2)rt=x;
}
void dfs2(int x,int F){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(v==F)continue;
		fa[v]=x;
		Edg[x].insert(edge[x][i]);
		dep[v]=dep[x]+1;
		dfs2(v,x);
		siz[x]+=siz[v];
		Maxans+=siz[v];Minans+=(siz[v]&1);
	}
}
void dfs3(int x,int t){
	if(Edg[x].size()) S[t].insert(mp(dep[x],x));
	for(itset it=Edg[x].begin();it!=Edg[x].end();++it){
		dfs3(*it,t);
	}
}
int vis[MN];
void dfs4(int x,int t){
	if(!vis[x])fk[t].push_back(x);
	for(int i=0;i<edge[x].size();++i)
		if(fa[x]!=edge[x][i])dfs4(edge[x][i],t);
}
void maintain(int x,int t){
	if(!Edg[x].size()) S[t].erase(mp(dep[x],x));
}
priority_queue<pii >Q;
signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%lld%lld",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1,0);dep[rt]=0;dfs2(rt,0);
	if(!(Minans<=k&&k<=Maxans&&k%2==Maxans%2)){puts("NO");return 0;}
	puts("YES");
	int rst=(Maxans-k)/2;
	for(int i=0;i<edge[rt].size();++i){
		dfs3(edge[rt][i],edge[rt][i]);
		if(siz[edge[rt][i]])
			Q.push(mp(siz[edge[rt][i]],edge[rt][i]));
	}
//	cerr<<"rt: "<<rt<<endl;
	while(rst){
//		cerr<<"fk "<<rst<<" "<<endl;
		int x=Q.top().y;Q.pop();siz[x]-=2;
		int a=(*--S[x].end()).y;
		while(dep[a]>rst){
			S[x].erase(--S[x].end());
			a=(*--S[x].end()).y;
		}
//		cerr<<"get: "<<a<<" "<<dep[a]<<endl;
		if(Edg[a].size()>1){
			int X=(*Edg[a].begin());
			Edg[a].erase(Edg[a].begin());
			int Y=(*Edg[a].begin());
			Edg[a].erase(Edg[a].begin());
			printf("%lld %lld\n",X,Y);
			vis[X]=vis[Y]=1;
			maintain(a,x);
		}
		else{
			int X=(*Edg[a].begin());
			Edg[a].erase(Edg[a].begin());
			vis[a]=vis[X]=1;
			printf("%lld %lld\n",a,X);
			S[x].erase(mp(dep[a],a));
			int p=fa[a];
			Edg[p].erase(a);
			maintain(p,x);
		}
		rst-=dep[a];if(siz[x])Q.push(mp(siz[x],x));
	}
	for(int i=0;i<edge[rt].size();++i)dfs4(edge[rt][i],edge[rt][i]);
	while(1){
		int x=Q.top().y;Q.pop();siz[x]--;
		if(Q.empty()){printf("%lld %lld\n",rt,fk[x].back());return 0;}
		int y=Q.top().y;Q.pop();siz[y]--;
		printf("%lld %lld\n",fk[x].back(),fk[y].back());
		fk[x].pop_back();fk[y].pop_back();
		if(siz[x])Q.push(mp(siz[x],x));
		if(siz[y])Q.push(mp(siz[y],y));
	}
	return 0;
}
//qwq