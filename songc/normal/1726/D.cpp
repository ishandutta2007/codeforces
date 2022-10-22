#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, M;
int ans[202020], U[202020], V[202020];
bool vis[202020];
vector<pii> adj[202020];

void dfs(int u){
	vis[u] = true;
	for (pii v : adj[u]){
		if (vis[v.fi]) continue;
		ans[v.se] = 1;
		dfs(v.fi);
	}
}

int f(int u, int x, int b1, int b2, int b3){
	vis[u] = true;
	for (pii v : adj[u]){
		if (vis[v.fi]) continue;
		if (v.se == b1 || v.se == b2 || v.se == b3) continue;
		if (v.fi == x) return v.se;
		int r = f(v.fi, x, b1, b2, b3);
		if (r != -1) return r;
	}
	return -1;
}

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		for (int i=1; i<=N; i++) vis[i] = false, adj[i].clear();
		for (int i=1; i<=M; i++){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].pb(pii(v, i));
			adj[v].pb(pii(u, i));
			ans[i] = 0;
			U[i] = u, V[i] = v;
			if (u > v) swap(U[i], V[i]);
		}
		dfs(1);
		if (N+2 == M){
			vector<int> v;
			vector<pii> vv;
			for (int i=1; i<=M; i++) if (ans[i] == 0) v.pb(i), vv.pb(pii(U[i], V[i]));
			sort(vv.begin(), vv.end());
			if (vv[0].fi == vv[1].fi && vv[0].se == vv[2].fi && vv[1].se == vv[2].se){
				int x=0;
				if (pii(U[v[0]], V[v[0]]) == vv[0]) x=v[0];
				if (pii(U[v[1]], V[v[1]]) == vv[0]) x=v[1];
				if (pii(U[v[2]], V[v[2]]) == vv[0]) x=v[2];
				for (int i=1; i<=N; i++) vis[i] = false;
				ans[f(vv[0].fi, vv[0].se, v[0], v[1], v[2])] = 0;
				ans[x] = 1;
			}
		}
		for (int i=1; i<=M; i++) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}