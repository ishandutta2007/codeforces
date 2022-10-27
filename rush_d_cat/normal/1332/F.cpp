#include <bits/stdc++.h>
using namespace std;
const int N=300000+10;
typedef long long LL;
const LL MOD = 998244353;
int n;
vector<int> G[N];
LL f[N][3];
LL mpow(LL a,LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}
void merge(int u, int v) {
	//printf("merge %d %d\n", u,v);
	//printf("[%lld, %lld, %lld] [%lld, %lld, %lld]\n", f[u][0],f[u][1],f[u][2],f[v][0],f[v][1],f[v][2]);
	LL dp[3]={0};
	dp[0]=f[u][0]%MOD*((f[v][0]+f[v][1]+f[v][2])%MOD)%MOD; // 
	dp[0]+=f[u][0]%MOD*((f[v][0]+f[v][1]+f[v][2]+f[v][2])%MOD)%MOD; dp[0]%=MOD; //
	dp[0]+=f[u][2]*((f[v][0]+f[v][1]+f[v][2]+f[v][2])%MOD)%MOD; dp[0]%=MOD;

	dp[1]=f[u][1]*((f[v][0]+f[v][1]+f[v][2])%MOD)%MOD + f[u][1]*((f[v][0]+f[v][2])%MOD)%MOD; dp[1]%=MOD;
	dp[1]+=f[u][2]*((f[v][0]+f[v][2])%MOD)%MOD; dp[1]%=MOD;

	dp[2]=f[u][2]*((f[v][0]+f[v][1]+f[v][2])%MOD)%MOD;
	f[u][0]=dp[0], f[u][1]=dp[1], f[u][2]=dp[2];
}
void dfs(int u,int p){
	f[u][0]=f[u][1]=0;
	f[u][2]=1;
	for(auto v: G[u]){
		if(v==p)continue;
		dfs(v,u);
		merge(u,v);
	}
	//printf("%d: %d %d %d\n", u, f[u][0], f[u][1], f[u][2]);
}
int main() {
	scanf("%d", &n);
	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,1);
	LL ans = (f[1][0] + f[1][1] + f[1][2]) % MOD;
	ans = (ans % MOD - 1 + MOD) % MOD;
	cout << ans << endl;
}
/*
f[u][0]: u u u 
f[u][1]: u u u 
f[u][2]: u u  



1, 2, 
1, 2, 12, 

*/