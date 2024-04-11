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
#define MN 500005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,n,m;
int deg[MN],vis[MN];
set<int>S,e[MN];
vector<int>p,G[MN];
pii ans[MN];
int siz[MN],col[MN],fa[MN];
int cnt;
vector<int>P;
void solve(int x,int lst=0){
	vis[x]=1;
	int p=0;
	for(auto v:S){
		if(e[x].find(v)==e[x].end()){
			G[x].pb(v);
			G[v].pb(x);
//			solve(v);
		}	
	}
	for(auto v:G[x])
		if(S.find(v)!=S.end())S.erase(v);
	for(auto v:G[x])
		if(v!=lst) solve(v,x);
}
void dfs(int x,int f){	
	P.pb(x);
	if(f){
		if(col[f]==1){siz[f]++;col[x]=0;fa[x]=f;}
		else if(siz[fa[f]]>2){
			siz[fa[f]]--;
			col[f]=1;siz[f]=2;fa[x]=f;fa[f]=0;
			col[x]=0;
		}
		else {
			int y=fa[f];
			col[f]=1;siz[f]=3;col[y]=col[x]=0;fa[y]=fa[x]=f;fa[f]=0;
		}
	}
//	cerr<<"dfs "<<x<<" "<<col[x]<<" "<<fa[x]<<endl;
	for(auto v:G[x])
		if(v!=f) dfs(v,x);
}
void work(int x){
	col[x]=siz[x]=1;
	P.clear();
	dfs(x,0);
	for(auto x:P){
		if(col[x]==1){
			ans[x]=mp(p[cnt],p[cnt+siz[x]-1]);
			for(auto v:G[x])
				if(fa[v]==x){
				ans[v]=mp(p[cnt+1],p[cnt]);	
				cnt++;
			}
			cnt++;
		}
	}
}
signed main(){
	T=read();
	int cas=0;
	while(T--){
		cas++;
		n=read();m=read();
	//	if(cas==25)cout<<n<<" "<<m<<endl;
		S.clear();p.clear();
		cnt=0;
		for(int i=1;i<=n;++i){
			e[i].clear();
			G[i].clear();
			siz[i]=col[i]=deg[i]=vis[i]=fa[i]=0;
			e[i].insert(0);
		}
		for(int i=1;i<=m;++i){
			int x=read(),y=read();
	//		if(cas==25)cout<<x<<" "<<y<<endl;
			deg[x]++;deg[y]++;
			e[x].insert(y);
			e[y].insert(x);
		}
		int TOT=0;
		for(int i=1;i<=n;++i)
			if(deg[i]!=n-1)S.insert(i),p.push_back(++TOT);
		for(int i=1;i<=n;++i)
			if(deg[i]==n-1){TOT++;ans[i]=mp(TOT,TOT);}
		for(int i=1;i<=n;++i)
			if(!vis[i]&&S.find(i)!=S.end()){
				S.erase(i);
				solve(i);
				work(i);
			}
		assert(cnt==p.size());
	//	if(T<=5){
			for(int i=1;i<=n;++i)printf("%lld ",ans[i].x);
			puts("");
			for(int i=1;i<=n;++i)printf("%lld ",ans[i].y);
			puts("");
	//	}
	}
	return 0;
}