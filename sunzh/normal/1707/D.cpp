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
#define int long long
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,mod;
vector<int>vec[2010];
int dp[2010][2010],C[2010][2010];
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int prs[2010][2010];
int mul[2010],val[2010];
int ans[2010],sf[2010],pr[2010];
void addx(int &x,int y){
	(x+=y)>=mod?x-=mod:x;
}
void dfs(int x,int fa){
	for(int v:vec[x]) if(v!=fa){
		dfs(v,x);val[v]=0;
	}
	for(int i=1;i<n;++i){
		mul[i]=1;
		for(int v:vec[x]) if(v!=fa){
			mul[i]=1ll*mul[i]*prs[v][i]%mod;
		}
		sf[vec[x].size()]=1;
		for(int j=0;j<vec[x].size();++j){
			if(vec[x][j]!=fa){
				pr[j]=(j==0?prs[vec[x][j]][i]:1ll*pr[j-1]*prs[vec[x][j]][i]%mod);
			}
			else if(j==0) pr[j]=1;else pr[j]=pr[j-1];
		}
		for(int j=vec[x].size()-1;j>=0;--j) sf[j]=1ll*sf[j+1]*(vec[x][j]==fa?1:prs[vec[x][j]][i])%mod;
		dp[x][i]=mul[i];
		if(x!=1) for(int j=0;j<vec[x].size();++j) if(vec[x][j]!=fa){
			int v=vec[x][j];
			addx(dp[x][i],1ll*val[v]*dp[v][i]%mod);
			addx(val[v],1ll*(j==0?1:pr[j-1])*sf[j+1]%mod);
		}
	}
	for(int i=1;i<n;++i) prs[x][i]=(prs[x][i-1]+dp[x][i])%mod;
}
signed main(){
	n=read(),mod=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	C[0][0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	dfs(1,0);
	for(int i=1;i<n;++i){
		int s=dp[1][i];
		for(int j=1;j<i;++j) (s-=1ll*ans[j]*C[i][j]%mod)%=mod;
		printf("%d ",ans[i]=(s+mod)%mod);
	}
}