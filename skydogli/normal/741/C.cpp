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
int T,n,m,col[MN],vis[MN],X[MN],Y[MN];
vector<int>e[MN];
void dfs(int x,int c){
	vis[x]=1;
	col[x]=c;
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(vis[v]){
			assert(col[x]!=col[v]);
			continue;
		}
		dfs(v,c^1);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		X[i]=x,Y[i]=y;
		e[x].pb(y);e[y].pb(x);
	}
	for(int i=1;i<=n;++i){
		int x=i<<1,y=i*2-1;
		e[x].pb(y);e[y].pb(x);
	}
	for(int i=1;i<=n*2;++i)
		if(!vis[i])dfs(i,0);
	for(int i=1;i<=n;++i){
		assert(col[X[i]]!=col[Y[i]]);
		printf("%lld %lld\n",col[X[i]]+1,col[Y[i]]+1);
	}
	return 0;
}