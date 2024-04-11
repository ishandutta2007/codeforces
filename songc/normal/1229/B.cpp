#include <bits/stdc++.h>
#define MOD 1000000007ll
using namespace std;
typedef long long LL;
typedef pair<LL,int> pii;

int N;
LL ans;
LL A[101010];
vector<int> adj[101010];
vector<pii> V[101010];

LL GCD(LL x, LL y){
	if (y == 0) return x;
	return GCD(y, x%y);
}

void dfs(int u, int p, int zc){
	vector<pii> T;
	for (pii x : V[p]){
		ans += GCD(x.first, A[u]) * x.second;
		ans %= MOD;
		T.push_back(pii(GCD(x.first, A[u]), x.second));
	}
	if (A[u] == 0) zc++;
	else {
		T.push_back(pii(A[u], zc+1));
		ans += A[u] * (zc+1);
		zc = 0;
		ans %= MOD;
	}
	pii t = pii(-1, 0);
	for (pii x : T){
		if (x.first == t.first) t.second += x.second;
		else{
			if (t.first != -1) V[u].push_back(t);
			t = x;
		}
	}
	if (t.first != -1) V[u].push_back(t);
	for (int v : adj[u]){
		if (v == p) continue;
		dfs(v, u, zc);
	}
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
	for (int i=1; i<N; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}