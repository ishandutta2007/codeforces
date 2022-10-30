#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back

using namespace std;
typedef long long INT;
typedef vector<int> VI;

#define NN 101
#define MM 41
#define c 20

inline void add(int &u, INT x) {u=(u+x)%mod;}

int n, k, dp[NN][MM], tmp[MM];
VI adj[NN];

inline void dfs(int u, int fa=0) {
	dp[u][c-1]=1;
	int mul=1, x;
	INT sum;
	for(int v: adj[u]) if(v!=fa) {
		dfs(v, u);
		for(int i=-k; i<=k; i++) tmp[c+i]=dp[u][c+i], dp[u][c+i]=0;
		sum=0;
		for(int i=-k; i<=k; i++) {
			for(int j=-k; j<=k; j++) {
				if(i+j>=0) add(dp[u][c+max(i, j-1)], (INT)tmp[c+i]*dp[v][c+j]);
				else {
					x=c+min(i, j-1);
					if(x>=0) add(dp[u][x], (INT)tmp[c+i]*dp[v][c+j]);
				}
			}
			sum+=dp[v][c+i];
		}
		mul=mul*(sum%mod)%mod;
	}
	add(dp[u][c+k], mul);
}

main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	scanf("%d %d", &n, &k);
	for(int i=1, u, v; i<n; i++) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	INT ans=0;
	for(int i=0; i<=k; i++) ans+=dp[1][c+i];
	printf("%d", ans%mod);
}