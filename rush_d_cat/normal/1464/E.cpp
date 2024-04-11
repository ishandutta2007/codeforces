#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
const LL MOD=998244353;

int n, m;
vector<int> g[N];
bool vis[N]; int dp[N],c[N];

LL mpow(LL a,LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}
LL inv(LL x){
	return mpow(x,MOD-2);
}
int dfs(int u){
	if(vis[u])return dp[u];
	vis[u]=1;
	set<int> s;
	for(auto v: g[u])s.insert(dfs(v));
	for(int i=0;;i++)if(!s.count(i))return dp[u]=i;
}


LL a[520][520];
void gauss(){
	for(int i=0;i<512;i++){
		if(a[i][i] == 0) continue;
		for(int j=i+1;j<512;j++){
			int k = 1LL * a[i][j] * inv(a[i][i]) % MOD;
			for(int x=0;x<=512;x++){
				a[j][x] -= a[i][x] * k;
				a[j][x] = (a[j][x] % MOD + MOD) % MOD;
			}
		}
	}
	for(int i=511;i>=0;i--){
		a[i][512] = a[i][512] * inv(a[i][i]) % MOD;
		a[i][i] = 1;
		for(int j=i-1;j>=0;j--){
			a[j][512] -= a[i][512] * a[j][i];
			a[j][512] = (a[j][512] % MOD + MOD) % MOD;
		}
	}
	LL ans = a[0][512];
	ans = (ans % MOD + MOD) % MOD;
	printf("%lld\n", ans);
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}	
	for(int i=1;i<=n;i++) c[dfs(i)] ++;
	
	LL inv = mpow(n+1, MOD-2);

	for(int i=0;i<512;i++){
		// x[i] = p * x[to] + inv
		for(int j=0;j<512;j++){
			int to = i ^ j, p = 1LL * c[j] * inv % MOD;
			a[i][to] = p;
		}
		a[i][i] -= 1; a[i][i] = (a[i][i] % MOD + MOD) % MOD;
		if(i) a[i][512] = ( (-inv) % MOD + MOD) % MOD;
	}
	gauss();
}