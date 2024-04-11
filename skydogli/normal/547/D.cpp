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
#define MN 600005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,n;
const int N=200000;
vector<pii >e[MN];
int vis[MN],vise[MN],ans[MN],lst[MN];
int U[MN],V[MN];
void dfs(int x){
	vis[x]=1;
	for(int i=lst[x]+1;i<e[x].size();i=max(i+1,lst[x]+1)){
		int v=e[x][i].x,id=e[x][i].y;
		lst[x]=i;
		if(vise[id])continue;
		vise[id]=1;
//		cerr<<"id "<<id<<" "<<x<<endl;
		ans[id]=(x<=N);
		dfs(v);	
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		int u=read(),v=read();
		U[i]=u,V[i]=v;
		e[u].pb(mp(v+N,i));
		e[v+N].pb(mp(u,i));
	}
	int m=n;
	for(int i=1;i<=(N<<1);++i)
		if(e[i].size()&1) {
			e[i].pb(mp(N<<1|1,++m));
			e[N<<1|1].pb(mp(i,m));
			U[m]=i;V[m]=N<<1|1;
		}
	for(int i=1;i<=(N<<1|1);++i)lst[i]=-1;
	for(int i=1;i<=(N<<1);++i)
		if(!vis[i])dfs(i);
	for(int i=1;i<=n;++i)putchar(ans[i]?'b':'r'); 
	return 0;
}