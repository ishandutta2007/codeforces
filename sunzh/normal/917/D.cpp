#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
vector<int>vec[110];
int dp[110][110][2];
int sz[110];
int tmp[110][2];
const int mod=1e9+7;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
void dfs(int x,int f){
	dp[x][0][0]=dp[x][0][1]=1;sz[x]=0;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs(v,x);
		for(int j=0;j<=sz[x]+sz[v]+1;++j) tmp[j][0]=tmp[j][1]=0;
		for(int j=0;j<=sz[x];++j){
			for(int k=0;k<=sz[v];++k){
				(tmp[j+k][0]+=1ll*dp[x][j][0]*dp[v][k][1]%mod)%=mod;
				(tmp[j+k][1]+=1ll*dp[x][j][1]*dp[v][k][1]%mod)%=mod;
				(tmp[j+k+1][0]+=1ll*dp[x][j][0]*dp[v][k][0]%mod)%=mod;
				(tmp[j+k+1][1]+=1ll*dp[x][j][0]*dp[v][k][1]%mod)%=mod;
				(tmp[j+k+1][1]+=1ll*dp[x][j][1]*dp[v][k][0]%mod)%=mod;
			}
		}
		for(int j=0;j<=sz[x]+sz[v]+1;++j) dp[x][j][0]=tmp[j][0],dp[x][j][1]=tmp[j][1];
		sz[x]+=sz[v]+1;
	}
}
int fac[1010],ifac[1010];
int C(int x,int y){
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=100;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[100]=qpow(fac[100]);
	for(int i=99;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v);vec[v].pb(u);
	}
	dfs(1,0);
	// for(int k=0;k<n;++k) printf("%d %d\n",dp[1][k][0],dp[1][k][1]);
	for(int k=0;k<n-1;++k) dp[1][k][1]=1ll*dp[1][k][1]*qpow(n,(n-k)-2)%mod;
	dp[1][n-1][1]=1;
	for(int k=0;k<n;++k){
		int ans=0;
		for(int l=k;l<n;++l) (ans+=(((l-k)&1)?mod-1ll*C(l,k)*dp[1][l][1]%mod:1ll*C(l,k)*dp[1][l][1]%mod))%=mod;
		printf("%d ",ans);
	}
}