#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;

int N, M;
int T[101010], W[101010];
LL ans;
vector<int> adj[101010];

void dfs(int u, map<LL,LL> &S){
	for (int v : adj[u]){
		map<LL,LL> t;
		dfs(v, t);
		if (S.size() < t.size()) swap(S, t);
		for (pii x : t) S[x.first] += x.second;
	}
	if (!W[u]) return;

	S[T[u]] += W[u];
	while (1){
		auto it = S.upper_bound(T[u]);
		if (it == S.end()) return;
		if (W[u] < it->second){
			it->second -= W[u];
			return;
		}
		W[u] -= it->second;
		S.erase(it);
	}
}

int main(){
	scanf("%d %d %*d", &N, &M);
	for (int i=2; i<=N; i++){
		int u;
		scanf("%d", &u);
		adj[u].push_back(i);
	}
	for (int i=1; i<=M; i++){
		int u;
		scanf("%d", &u);
		scanf("%d %d", &T[u], &W[u]);
	}
	map<LL,LL> S;
	dfs(1, S);
	for (pii x : S) ans += x.second;
	printf("%lld\n", ans);
	return 0;
}