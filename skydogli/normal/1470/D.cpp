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
#define MN 300005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m;
int a[MN],vis[MN],col[MN],dep[MN];
vector<int>edge[MN];
		vector<int>ans;
char ch[MN];
int F[MN],app[MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
int q[MN];
void dfs(int x){
	if(vis[x])return;
	vis[x]=1;
	if(col[x])for(auto i:edge[x])app[i]=1;
	for(auto v:edge[x]){
		if(!app[v])app[v]=col[v]=1,ans.push_back(v);
		dfs(v);
	}
}
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		ans.clear();
		for(int i=1;i<=n;++i)F[i]=i,app[i]=vis[i]=col[i]=0,edge[i].clear();
		for(int i=1;i<=m;++i){
			int u=read(),v=read();
			edge[u].push_back(v);
			edge[v].push_back(u);
			F[Find(u)]=Find(v);
		}
		bool ok=1;
		dfs(1);
		for(int i=1;i<=n;++i)if(!app[i])ok=0;
		if(!ok){
			puts("NO");
			continue;
		}
		puts("YES");
		printf("%lld\n",(int)ans.size());
		for(auto i:ans)printf("%lld ",i);
		puts("");
	}
	return 0;
}