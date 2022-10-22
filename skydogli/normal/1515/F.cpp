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
int n,m,c,a[MN],fa[MN];
vector<pii >e[MN];
vector<int>ans,t;
bool vis[MN];
void dfs(int x){
	vis[x]=1;
//	cerr<<"dfs: "<<x<<" "<<fa[x]<<endl;
	for(int i=0;i<e[x].size();++i){
		int v=e[x][i].x,id=e[x][i].y;
		if(vis[v])continue;
		fa[v]=x;
		dfs(v);
		if(a[v]>c){
			a[x]+=a[v]-c;
			ans.pb(id);
		}
		else t.pb(id);
	}
}
signed main(){
	n=read();m=read();c=read();
	int s=0;
	for(int i=1;i<=n;++i){
		a[i]=read();s+=a[i];
	}
	if(s<c*(n-1)){puts("NO");return 0;}
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		e[x].pb(mp(y,i));
		e[y].pb(mp(x,i));
	}
	dfs(1);
	puts("YES");
	reverse(t.begin(),t.end());
	for(int i=0;i<ans.size();++i)printf("%lld\n",ans[i]);
	for(int i=0;i<t.size();++i)printf("%lld\n",t[i]);
	return 0;
}