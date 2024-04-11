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
int n,d;
vector<int>vec[3010];
int dp[3010][3010];
int sum[3010][3010];
int mx;
const int mod=1e9+7;
void dfs(int x,int fa){
	if(!vec[x].size()){
		for(int i=1;i<=mx;++i) sum[x][i]=i,dp[x][i]=1;return ;
	}
	for(int v:vec[x]){
		dfs(v,x);
	}
	for(int i=1;i<=mx;++i){
		int res=1;
		for(int v:vec[x]){
			res=1ll*res*sum[v][i]%mod;
		}
		dp[x][i]=res;
	}
	for(int i=1;i<=mx;++i) sum[x][i]=(sum[x][i-1]+dp[x][i])%mod;
}
int qpow(int x,int k=mod-2){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1; 
	}
	return res;
}
int g[3010];
int fac[3010],ifac[3010];

int main(){
	n=read(),d=read();mx=min(d,n);
	for(int i=2;i<=n;++i){
		int p=read();
		vec[p].pb(i);
	}
	dfs(1,0);
	fac[0]=1;
	auto C=[&](int x,int y){
		return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
	};
	for(int i=1;i<=mx;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[mx]=qpow(fac[mx]);
	for(int i=mx-1;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	for(int i=1;i<=mx;++i){
		g[i]=dp[1][i];
		for(int j=1;j<i;++j){
			g[i]=(g[i]-1ll*C(i-1,j-1)*g[j]%mod+mod)%mod;
		}
	}
	int ans=0;
	int cob=d;
	for(int i=1;i<=mx;++i){
		(ans+=1ll*cob*g[i]%mod)%=mod;
		cob=1ll*cob*(d-i)%mod*qpow(i+1)%mod;
	}
	printf("%d\n",ans);
}