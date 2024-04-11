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
#define vc vector<int>
int T,n,L[MN],R[MN],f[MN][2];
vc e[MN];
int fa[MN];
void dfs(int x){
	f[x][0]=f[x][1]=0;
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;dfs(v);
		f[x][0]+=max(f[v][0]+abs(L[x]-L[v]),f[v][1]+abs(L[x]-R[v]));
		f[x][1]+=max(f[v][0]+abs(R[x]-L[v]),f[v][1]+abs(R[x]-R[v]));
	}
}
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)L[i]=read(),R[i]=read();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			e[u].pb(v);
			e[v].pb(u);
		}
		dfs(1);
		printf("%lld\n",max(f[1][0],f[1][1]));
		for(int i=1;i<=n;++i)e[i].clear();
	}
	return 0;
}