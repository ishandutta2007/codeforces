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
int T,n,m,k;
int u[MN],v[MN],w[MN];
vector<pii > e[MN];
map<int,int>G[MN];
vc p;
int vis[MN],f[MN];
int E[705][705];
int prim(){
	for(int i=1;i<=n;++i)f[i]=1e18,vis[i]=0;
	f[1]=0;
	int ans=0;
	for(int i=1;i<=n;++i){
		int pos=0;
		for(int j=1;j<=n;++j)
			if(!vis[j]&&(!pos||f[pos]>f[j]))pos=j;
		vis[pos]=1;
		ans+=f[pos];
		for(int j=1;j<=n;++j)
			if(f[j]>E[pos][j])f[j]=E[pos][j];
	}
	return ans;
}
int F[MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
priority_queue<pii,vector<pii >,greater<pii > >Q;
signed main(){
	n=read();m=read();
	k=n*(n-1)/2-m;
	for(int i=1;i<=m;++i){
		u[i]=read(),v[i]=read(),w[i]=read();
		e[u[i]].pb(mp(v[i],w[i]));
		e[v[i]].pb(mp(u[i],w[i]));
		G[u[i]][v[i]]=G[v[i]][u[i]]=w[i];
	}
	if(k>=n){
		for(int i=1;i<=n+1;++i)F[i]=i;
		for(int i=2;i<=n;++i)f[i]=1e18;
		F[1]=2;f[1]=0;
		int ans=0,tot=0;Q.push(mp(0,1));
		while(!Q.empty()){
			pii w=Q.top();Q.pop();
			if(vis[w.y])continue;
			tot++;
			int x=w.y;
			F[x]=Find(x+1);
			vis[w.y]=1;ans+=w.x;
			for(int i=Find(1);i<=n;i=Find(i+1)){
				if(!G[x].count(i)&&f[i]){
					f[i]=0;F[i]=Find(i+1);
					Q.push(mp(0,i));
				}
				else if(G[x].count(i)&&f[i]&&!vis[i]){
					if(f[i]>G[x][i]){
						f[i]=G[x][i];
						Q.push(mp(f[i],i));
					}
				}
			}
		}
		assert(tot==n);
		printf("%lld\n",ans);
	}
	else{
		int va=0,ans=1e18;
		for(int i=1;i<=m;++i)E[u[i]][v[i]]=E[v[i]][u[i]]=w[i],va^=w[i];
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j){
				if(!G[i].count(j)){
					E[i][j]=E[j][i]=va;
					ans=min(ans,prim());
					E[i][j]=E[j][i]=0;
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}