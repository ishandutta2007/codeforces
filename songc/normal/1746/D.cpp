#include <bits/stdc++.h>
#define fi first
#define se second
#define lb lower_bound
#define pb push_back
#define MOD 1000000007
#define INF (1ll<<60);
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, K;
LL ans;
LL A[202020];
vector<int> adj[202020];
vector<LL> C[202020];

void f(int u, int x){
	int n = adj[u].size();
	if (n == 0){
		ans += A[u] * x;
		for (int i=1; i<=20; i++) C[u].pb(A[u]);
		return;
	}
	for (int v : adj[u]) A[v]+=A[u], f(v, x/n);
	x %= n;
	vector<int> vv;
	while (C[u].size() <= n+20){
		if (vv.empty()){
			for (int v : adj[u]){
				vv.pb(C[v].back());
				C[v].pop_back();
			}
			sort(vv.begin(), vv.end());
		}
		C[u].pb(vv.back());
		vv.pop_back();
	}
	reverse(C[u].begin(), C[u].end());
	while (x--) ans += C[u].back(), C[u].pop_back();
}

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &K);
		int x;
		ans = 0;
		for (int i=1; i<=N; i++) adj[i].clear(), C[i].clear();
		for (int i=2; i<=N; i++) scanf("%d", &x), adj[x].pb(i);
		for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
		f(1, K);
		printf("%lld\n", ans);
	}
	return 0;
}