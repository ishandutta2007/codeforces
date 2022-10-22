#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
vector<int>vec[300010];
const int mod=998244353;
int dp[300010][3];
void dfs(int x,int f){
	dp[x][0]=1;
	int sum=0ll;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs(v,x);
		dp[x][1]=(1ll*dp[x][1]*(dp[v][0]+dp[v][1]*2ll)%mod+1ll*(dp[x][0]+dp[x][2])*(dp[v][0]+dp[v][2])%mod)%mod;
		dp[x][2]=1ll*dp[x][2]*(dp[v][0]+dp[v][1]*2ll)%mod+1ll*dp[x][0]*dp[v][1]%mod;
		dp[x][0]=1ll*dp[x][0]*(dp[v][0]+dp[v][1])%mod;
	}
}
signed main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v);vec[v].pb(u);
	}
	dfs(1,0);
	printf("%lld\n",(dp[1][0]+dp[1][1])%mod);
	return 0;
}