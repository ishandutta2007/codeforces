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
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
vector<int>vec[15010];
int fa[15010],dep[15010];
int dp[2][15010];
int siz[15010],sz[15010];
int sum[15010],s_u[15010];
vector<int>cir,sub;
int tot;
bool flag;
int res[15010];
bool incir[15010];
bool fl;
void dfs(int x,int f){
	if(flag) return ;
	fa[x]=f;
	siz[x]=1;
	for(int v:vec[x]){
		if(v==f) continue ;
		if(siz[v]){
			int u=x;
			while(u!=v){
				incir[u]=1;cir.pb(u);u=fa[u];
			}
			cir.pb(v);incir[v]=1;
			flag=1;
			return ;
		}
		else dfs(v,x);
		if(flag) return ;
	}
}
void solve(int x,int f,int fr){
	siz[x]=1;
	sum[x]=0;
	for(int v:vec[x]){
		if(v==f||v==fr) continue ;
		solve(v,x,fr);siz[x]+=siz[v];sum[x]+=sum[v];
	}
	sum[x]+=siz[x];
}
void dfs2(int x,int f,int fr){
	dep[x]=dep[f]+1;sub.pb(x);
	for(int v:vec[x]){
		if(v==f||v==fr) continue ;
		dfs2(v,x,fr);
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	dfs(0,-1);
	memset(siz,0,sizeof(siz));
	for(int x:cir){
		for(int v:vec[x]){
			if(incir[v]) continue ;
			solve(v,x,x);
			s_u[x]+=sum[v];
		}
		tot+=s_u[x];
	}
	for(int i=0;i<cir.size();++i){
		sz[i]=1;
		for(int v:vec[cir[i]]){
			if(incir[v]) continue ;
			sz[i]+=siz[v];
		}
	}
	for(int i=0;i<cir.size();++i) sz[i+cir.size()]=sz[i];
	for(int i=1;i<(cir.size()<<1);++i) sz[i]+=sz[i-1];
	for(int x:cir){
		int add=-1;
		dep[x]=1;
		for(int v:vec[x]){
			if(incir[v]) continue ;
			sub.clear();
			int det=sum[v],si=siz[v];dfs2(v,x,x);
			for(int u:sub){
				solve(u,x,x);
				add=max(add,dep[u]*(n-si)+sum[u]-det);
			}
		}
		if(add==-1){
			res[x]=n;
		}
		else res[x]=s_u[x]+add;
	}
	for(int i=0;i<cir.size();++i) dp[fl][i]=tot-s_u[cir[i]]+res[cir[i]];
	for(int i=1;i<cir.size();++i){
		fl^=1;memset(dp[fl],0,sizeof(dp[fl]));
		for(int j=0;j<cir.size();++j){
			int s=sz[i+j-1];
			if(j>0) s-=sz[j-1];
			dp[fl][j]=max(dp[fl][j],dp[fl^1][j]+(n-s));
			int pre=(j==0?cir.size()-1:j-1);
			dp[fl][pre]=max(dp[fl][pre],dp[fl^1][j]+(n-s));
		}
	}
	int ans=0;
	for(int i=0;i<cir.size();++i) ans=max(ans,dp[fl][i]);
	printf("%d\n",ans);
}