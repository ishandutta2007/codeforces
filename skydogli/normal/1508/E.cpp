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
#define pb push_back
#define vc vector
int T,n,m,cnt,tot,fa[MN],pos[MN],dep[MN];
int a[MN],dfn[MN],ex[MN];
vector<int>e[MN];
bool cmp(int x,int y){return a[x]<a[y];}
void dfs(int x){
	dfn[x]=++cnt;
	dep[x]=dep[fa[x]]+1;
	sort(e[x].begin(),e[x].end(),cmp);
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		fa[v]=x;dfs(v);
	}
	ex[x]=++tot;
}
bool chkdfn(int l,int r){
	for(int i=1;i<=n;++i)
		if(a[i]!=dfn[i]&&l<=a[i]&&a[i]<=r)return 0;
	return 1;
}
bool chkex(int l,int r){
	for(int i=1;i<=n;++i)if(a[i]!=ex[i]&&l<=a[i]&&a[i]<=r)return 0;
	return 1;
}
bool chkfa(int x,int y){
	while(x){
		if(x==y)return 1;
		x=fa[x];
	}
	return 0;
}
int ans=0;
void bk(int x){
	while(x!=1){
		swap(a[x],a[fa[x]]);
		ans++;
		x=fa[x];
	}
}
int tmp,fk[MN];
void dfs2(int x){
	if(a[x]<tmp)return;
	fk[x]=++tot;
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i];
		if(fa[x]==v)continue;
		assert(fa[v]==x);
		dfs2(v);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		pos[a[i]]=i;
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1);
	if(a[1]==1){
		if(chkdfn(1,n)){
			puts("YES\n0");
			for(int i=1;i<=n;++i)printf("%lld ",dfn[i]);
		}
		else puts("NO");
		return 0;
	}
	int now=a[1]-1;
	if(!chkex(1,now-1)){puts("NO");return 0;}
	int p=0;
	for(int i=1;i<=n;++i)if(ex[i]==now){p=i;break;}
	if(!chkfa(p,pos[now])){puts("NO");return 0;}
	bk(pos[now]);
	tot=now-1;tmp=now;dfs2(1);
	for(int i=1;i<=n;++i)if(fk[i]!=a[i]&&now<=fk[i]&&fk[i]<=n){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n;++i)
		if(a[i]<now){
			ans+=dep[i]-1;
		}
	puts("YES");
	cout<<ans<<endl;
	for(int i=1;i<=n;++i)printf("%lld ",dfn[i]);
	return 0;
}