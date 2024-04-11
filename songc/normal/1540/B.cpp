#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
int A[220], B[220];
LL ans, D[220][220], P[220][220];
vector<int> adj[220];

LL Pow(LL x, LL y){
	if (!y) return 1;
	LL z = Pow(x, y/2);
	if (y&1) return z*z%MOD*x%MOD;
	return z*z%MOD;
}

void dfs(int u, int p, int t){
	if (t) A[u] = A[p]+1;
	else B[u] = B[p]+1;
	for (int v : adj[u]){
		if (v == p) continue;
		dfs(v, u, t);
	}
}

int main(){
	int u, v;
	scanf("%d", &N);
	for (int i=1; i<N; i++){
		scanf("%d %d", &u, &v); 
		adj[u].pb(v), adj[v].pb(u);
	}
	A[0]=B[0]=-1;
	D[0][0] = 1;
	LL ni = Pow(N, MOD-2), bi = Pow(2, MOD-2);
	for (int i=0; i<N; i++) for (int j=0; j<N; j++){
		D[i+1][j] = (D[i+1][j] + D[i][j]*bi)%MOD;
		D[i][j+1] = (D[i][j+1] + D[i][j]*bi)%MOD;
		LL x=0, y=0;
		for (int k=0; k<j; k++) x = (x + D[i-1][k])%MOD;
		for (int k=0; k<i; k++) y = (y + D[k][j-1])%MOD;
		P[i][j] = x * Pow(x+y, MOD-2) % MOD;
	}
	for (int i=1; i<=N; i++){
		for (int j=i+1; j<=N; j++){
			dfs(i, 0, 0), dfs(j, 0, 1);
			for (int k=1; k<=N; k++){
				int a=A[k]-(A[k]+B[k]-A[i])/2, b=B[k]-(A[k]+B[k]-A[i])/2;
				if (b == 0) continue;
				if (a == 0) ans = (ans+ni)%MOD;
				ans = (ans + ni*P[a][b]%MOD);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}