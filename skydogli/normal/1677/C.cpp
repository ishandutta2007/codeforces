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
int a[MN],b[MN],vis[MN],o,u;
vc e[MN];
void dfs(int x){
	vis[x]=1;o^=1;
	if(!o)u++;
	for(auto v:e[x]){
		if(vis[v])continue;
		dfs(v);
	}
}
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		int ans=0,cnt=0;
		u=0;
		for(int i=1;i<=n;++i)e[i].clear(),vis[i]=0;
		for(int i=1;i<=n;++i){
			b[i]=read();
			e[a[i]].pb(b[i]);
			if(a[i]==b[i])cnt++;
		}
		for(int i=1;i<=n;++i)
		if(!vis[i]){o=0;dfs(i);}
		for(int i=1;i<=n-i+1&&u;++i){
			u--;
			ans+=n-i+1-i;
		}
		printf("%lld\n",ans*2);
	}
	return 0;
}