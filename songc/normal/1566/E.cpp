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

int TC, N;
int ans;
vector<int> adj[202020];

bool dfs(int u, int p){
	bool chk=false;
	for (int v : adj[u]){
		if (p == v) continue;
		if (dfs(v, u)) chk=true;
	}
	if (u!=1 && chk) ans--;
	if (!chk) ans++;
	return !chk;
}

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		for (int i=1; i<=N; i++) adj[i].clear();
		for (int i=1; i<N; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].pb(v), adj[v].pb(u);
		}
		ans = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	}
	return 0;
}