#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 1000000007
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,cnt,dep[210],par[10][210],vis[210],dp[210][210][2],sum[210][210];
vector<int> g[210];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline void dfs(int x,int pr)
{
	par[0][x]=pr;
	for(int i=0;i<g[x].size();i++) if(g[x][i]!=pr){
		dep[g[x][i]]=dep[x]+1;
		dfs(g[x][i],x);
	}
}

inline void init()
{
	dfs(1,-1);
	for(int k=0;k+1<10;k++){
		for(int i=1;i<=n;i++){
			if(par[k][i]<0) par[k+1][i]=-1;
			else par[k+1][i]=par[k][par[k][i]];
		}
	}
}

inline int lca(int u,int v)
{
	if(dep[u]>dep[v]) swap(u,v);
	for(int k=0;k<10;k++){
		if(((dep[v]-dep[u])>>k)&1){
			v=par[k][v];
		}
	}
	if(u==v) return u;
	for(int k=10-1;k>=0;k--){
		if(par[k][u]!=par[k][v]){
			u=par[k][u];v=par[k][v];
		}
	}
	return par[0][u];
}

inline int dist(int u,int v)
{
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}

inline void dfs2(int x,int pr)
{
	cnt++;
	for(int i=0;i<g[x].size();i++) if(g[x][i]!=pr&&!vis[g[x][i]]){
		dfs2(g[x][i],x);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int rev2=my_pow(2,MOD-2);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0&&j==0) dp[i][j][0]=1;
			else{
				if(i>0) add(dp[i][j][0],1ll*(dp[i-1][j][0]+dp[i-1][j][1])*rev2%MOD);
				if(j>0) add(dp[i][j][1],1ll*(dp[i][j-1][0]+dp[i][j-1][1])*rev2%MOD);
			}
		}
	}
	for(int i=0;i<=n;i++){
		sum[0][i]=dp[0][i][1];
		for(int j=1;j<=n;j++){
			sum[j][i]=sum[j-1][i];
			add(sum[j][i],dp[j][i][1]);
		}
	}
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	init();
	int rev=my_pow(n,MOD-2);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			memset(vis,0,sizeof(vis));
			for(int l=1;l<=n;l++) if(dist(i,l)+dist(j,l)==dist(i,j)) vis[l]=1;
			for(int l=1;l<=n;l++) if(vis[l]){
				cnt=0;dfs2(l,-1);
				if(dist(j,l)==dist(i,j)){
					continue;
				}
				if(dist(i,l)==dist(i,j)){
					add(ans,1ll*rev*cnt%MOD);
					continue;
				}
				add(ans,1ll*rev*cnt%MOD*sum[dist(i,l)-1][dist(j,l)]%MOD);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}