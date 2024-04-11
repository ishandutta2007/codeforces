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
int T,n,m;
int a[MN];
char ch[MN];
vc e[MN];
int f[MN][2],fa[MN],sum[MN];
const int inf=1e9;
void dfs(int x){
	f[x][1]=1;f[x][0]=0;
	bool ok=0;
	sum[x]=0;
	int mi=inf;
	for(auto v:e[x]){
		if(fa[x]==v)continue;
		fa[v]=x;
		dfs(v);
		f[x][1]+=f[v][0];
		f[x][0]+=min(f[v][1],f[v][0]);
		if(f[v][1]<=f[v][0])ok=1;
		mi=min(mi,f[v][1]-f[v][0]);
		sum[x]+=min(f[v][0],f[v][1]);
	}
	mi=max(mi,0ll);
	f[x][0]+=mi;
	f[x][0]--;

//	cerr<<"f "<<x<<": "<<f[x][0]<<" "<<f[x][1]<<endl;
}
int ans,res;
void getans(int x){
	res+=sum[x];
//	cerr<<"dfs: "<<x<<" "<<res<<" "<<endl;
	if(e[x].size()==1&&x!=1)ans=min(ans,res+1);
	for(auto v:e[x]){
		if(fa[x]==v)continue;
		res-=min(f[v][1],f[v][0]);
//		cerr<<"FKFK: "<<x<<" "<<v<<" "<<res<<endl;
		getans(v);
		res+=min(f[v][1],f[v][0]);
//		cerr<<"FK: "<<x<<" "<<v<<" "<<res<<endl;
	}
	res-=sum[x];
}
signed main(){
	T=read();
	while(T--){
		ans=1e18;
		n=read();
		for(int i=1;i<=n;++i)e[i].clear(),fa[i]=0;
		for(int i=1;i<n;++i){
			int x=read(),y=read();
			e[x].pb(y);e[y].pb(x);
		}
		dfs(1);
		res=0;
		getans(1);
		printf("%lld\n",ans);
	}
	return 0;
}