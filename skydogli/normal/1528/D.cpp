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
#define mn 605
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int n,m,ti[mn][mn];
int f[mn],vis[mn],g[mn];
vector<pii >e[mn];
const int inf=1e18;
void solve(int x){
	for(int i=0;i<n;++i)f[i]=inf,vis[i]=0;
	f[x]=0;
	for(int i=1;i<=n;++i){
		int pos=-1;
		for(int j=0;j<n;++j)
			if(!vis[j]&&(pos==-1||f[pos]>f[j]))pos=j;
		if(pos==-1)return;
		vis[pos]=1;
		int t=f[pos]%n;
		for(int j=0;j<n;++j)g[j]=inf;
		for(auto a:e[pos]){
			g[(a.x+t)%n]=a.y;
		}
		for(int j=1;j<n;++j)if(g[j]>g[j-1]+1)g[j]=g[j-1]+1;
		if(g[0]>g[n-1]+1){
			g[0]=g[n-1]+1;
			for(int j=1;j<n;++j)if(g[j]>g[j-1]+1)g[j]=g[j-1]+1;
		}
		for(int j=0;j<n;++j)
			if(f[pos]+g[j]<f[j]){
				f[j]=f[pos]+g[j];
			}
	}
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		int a=read(),b=read(),c=read();
//		ti[a][b]=1;
		e[a].pb(mp(b,c));
//		E[a][b]=c;
	}
	for(int i=0;i<n;++i){
		solve(i);
		for(int j=0;j<n;++j)printf("%lld ",f[j]);
		puts("");
	}
	return 0;
}