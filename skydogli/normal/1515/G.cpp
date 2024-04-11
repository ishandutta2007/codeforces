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
int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}
int n,m,q,val[MN];
vector<pii >e[MN],cir[MN];
int fa[MN],dep[MN],vis[MN],belong[MN];
namespace Graph{
	int dfn[MN],low[MN],ins[MN],N,st[MN],Ti,rp;
	void tarjan(int x){
		dfn[x]=low[x]=++Ti;
		st[++N]=x;ins[x]=1;
		for(int i=0;i<e[x].size();++i){
			int v=e[x][i].x;
			if(!dfn[v]){
				tarjan(v);
				low[x]=min(low[x],low[v]);
			}
			else if(ins[v])low[x]=min(low[x],dfn[v]);
		}
		if(dfn[x]==low[x]){
			rp++;
			while(st[N+1]!=x){
				belong[st[N]]=rp;
				ins[st[N]]=0;
				N--;
			}
		}
	}
}
int fk=0;
int d[MN];
int LCA(int x,int y){
	while(x!=y){
		if(d[x]<d[y])swap(x,y);
		x=fa[x];
	}
	return x;
}
void dfs(int x){
//	cerr<<"dfs: "<<x<<" "<<belong[x]<<" "<<" "<<fa[x]<<" "<<dep[x]<<endl;
	vis[x]=1;
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i].x,w=e[x][i].y;
		if(fa[v]==x||belong[x]!=belong[v])continue;
		if(!vis[v]){
			fa[v]=x;dep[v]=dep[x]+w;
			d[v]=d[x]+1;
			dfs(v);
		}
		else {
			val[belong[x]]=gcd(val[belong[x]],abs(dep[x]-dep[v]+w));
		}
	}
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		int a=read(),b=read(),c=read();
		e[a].pb(mp(b,c));
	}
	vector<int>rt;
	for(int i=1;i<=n;++i)
		if(!belong[i]){
			fk++;
			rt.pb(i);
			Graph::tarjan(i);
		}
	for(int i=1;i<=n;++i)
		if(!vis[i])dfs(i);
	q=read();
	for(int i=1;i<=q;++i){
		int x=read(),s=read(),t=read();
//		cerr<<"val: "<<val[belong[x]]<<endl;
		if(!s)puts("YES");
		else puts((val[belong[x]]&&(t-s)%gcd(t,val[belong[x]])==0)?"YES":"NO");
	}
	return 0;
}