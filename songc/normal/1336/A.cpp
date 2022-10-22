#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
#define INF (1ll<<60)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, K;
LL ans;
vector<int> adj[202020], V;

int f(int u, int p, int d){
	int r=0;
	for (int v : adj[u]){
		if (v == p) continue;
		r += f(v, u, d+1);
	}
	V.pb(r-d);
	return r+1;
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i=1; i<N; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	f(1, 0, 0);
	sort(all(V));
	for (int i=0; i<K; i++) ans -= V[i];
	printf("%lld\n", ans);
	return 0;
}