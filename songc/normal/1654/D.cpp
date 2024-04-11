#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 998244353
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N;
vector<int> adj[202020], X[202020], Y[202020];
map<int,int> P, A;
LL ans, Q;

LL Pow(LL x, LL y){
	if (!y) return 1;
	LL z = Pow(x, y/2);
	if (y&1) return z*z%MOD*x%MOD;
	return z*z%MOD;
}

void dfs(int u, int p){
	for (int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		int x=X[u][i], y=Y[u][i];
		if (v == p) continue;

		vector<pii> Vx, Vy;
		for (int j=2; j*j<=x; j++){
			int cnt=0;
			while (x % j == 0) x /= j, cnt++;
			if (cnt) Vx.pb(pii(j, cnt));
		}
		if (x>1) Vx.pb(pii(x, 1));
		for (int j=2; j*j<=y; j++){
			int cnt=0;
			while (y % j == 0) y /= j, cnt++;
			if (cnt) Vy.pb(pii(j, cnt));
		}
		if (y>1) Vy.pb(pii(y, 1));

		for (pii t : Vy) P[t.fi] -= t.se;
		for (pii t : Vx){
			P[t.fi] += t.se;
			A[t.fi] = max(A[t.fi], P[t.fi]);
		}
		dfs(v, u);
		for (pii t : Vx) P[t.fi] -= t.se;
		for (pii t : Vy) P[t.fi] += t.se;
	}
}

void f(int u, int p, LL a){
	ans = (ans + a) % MOD;
	for (int i=0; i<adj[u].size(); i++){
		int v = adj[u][i];
		LL x=X[u][i], y=Y[u][i];
		if (v == p) continue;

		LL b = a * Pow(x, MOD-2) % MOD;
		b = b * y % MOD;
		f(v, u, b);
	}
}

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		for (int i=1; i<N; i++){
			int u, v, x, y;
			scanf("%d %d %d %d", &u, &v, &x, &y);
			adj[u].pb(v), X[u].pb(x), Y[u].pb(y);
			adj[v].pb(u), X[v].pb(y), Y[v].pb(x);
		}
		A.clear(), P.clear();
		dfs(1, 0);
		ans=0, Q=1;
		for (pii t : A) Q = Q * Pow(t.fi, t.se) % MOD;
		f(1, 0, Q);
		printf("%lld\n", ans);
		for (int i=1; i<=N; i++){
			adj[i].clear();
			X[i].clear();
			Y[i].clear();
		}
	}
	return 0;
}