#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n,m;
PII dp[3010][3010];
vector<int>vec[3010];
int b[3010],w[3010];
int siz[3010];
PII tmp[3010];
const int inf=0x153f3f3f3f3f3f3fll;
void dfs(int x,int f){
	dp[x][1]=mp(0,w[x]-b[x]);
	siz[x]=1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs(v,x);
		for(int j=1;j<=siz[x]+siz[v]+1&&j<=m;++j) tmp[j]=mp(-1,-inf);
		for(int j=1;j<=siz[x];++j){
			for(int k=1;k<=siz[v];++k){
				int sfi=dp[x][j].fi+dp[v][k].fi;
				sfi+=(dp[v][k].se>0);
				if(sfi>tmp[j+k].fi) tmp[j+k].fi=sfi,tmp[j+k].se=dp[x][j].se;
				else if(sfi==tmp[j+k].fi) tmp[j+k].se=max(tmp[j+k].se,dp[x][j].se);
				sfi-=(dp[v][k].se>0);
				if(sfi>tmp[j+k-1].fi) tmp[j+k-1].fi=sfi,tmp[j+k-1].se=dp[x][j].se+dp[v][k].se;
				else if(sfi==tmp[j+k-1].fi) tmp[j+k-1].se=max(tmp[j+k-1].se,dp[x][j].se+dp[v][k].se);
			}
		}
		siz[x]+=siz[v];
		for(int j=1;j<=siz[x];++j) dp[x][j]=tmp[j];
	}
}
signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) vec[i].clear();
		for(int i=1;i<=n;++i) for(int j=0;j<=m;++j) dp[i][j]=mp(-1,-0x3f3f3f3f);
		for(int i=0;i<=m;++i) tmp[i]=mp(-1,-0x3f3f3f3f);
		for(int i=1;i<=n;++i) b[i]=read();
		for(int i=1;i<=n;++i) w[i]=read();
		for(int i=1;i<n;++i){
			int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
		}
		dfs(1,0);
		printf("%d\n",dp[1][m].fi+(dp[1][m].se>0));
	}
}