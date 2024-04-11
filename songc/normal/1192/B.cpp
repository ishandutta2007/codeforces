#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, Q, num;
int X[101010], L[101010], R[101010];
LL W[101010], K, ans;
vector<pii> adj[101010];

struct Node{
	LL P=0, M=0, lazy=0;
	LL LM=0, MR=0, LMR=0;

	Node operator+=(const LL &r){
		P += r, M -= 2*r;
		LM -= r, MR -= r, lazy += r;
	}
	Node operator+(const Node &r)const{
		Node ret;
		ret.P = max(P, r.P);
		ret.M = max(M, r.M);
		ret.LM = max(LM, r.LM);
		ret.LM = max(ret.LM, P + r.M);
		ret.MR = max(MR, r.MR);
		ret.MR = max(ret.MR, M + r.P);
		ret.LMR = max(LMR, r.LMR);
		ret.LMR = max(ret.LMR, LM + r.P);
		ret.LMR = max(ret.LMR, P + r.MR);
		return ret;
	}
} T[808080];

void update(int id, int s, int e, int ts, int te, LL v){
	if (e < ts || te < s) return;
	if (ts <= s && e <= te){
		T[id] += v;
		return;
	}
	T[id*2] += T[id].lazy;
	T[id*2+1] += T[id].lazy;
	T[id].lazy = 0;

	int mid = (s+e)/2;
	update(id*2, s, mid, ts, te, v);
	update(id*2+1, mid+1, e, ts, te, v);
	T[id] = T[id*2] + T[id*2+1];
}

void dfs(int u, int p){
	L[u] = ++num;
	for (pii v : adj[u]){
		if (v.first == p) continue;
		X[v.second] = v.first;
		dfs(v.first, u);
		++num;
	}
 	R[u] = num;
}

int main(){
	scanf("%d %d %lld", &N, &Q, &K);
	for (int i=1; i<N; i++){
		int u, v;
		scanf("%d %d %lld", &u, &v, &W[i]);
		adj[u].push_back(pii(v, i));
		adj[v].push_back(pii(u, i));
	}
	dfs(1, 0);
	for (int i=1; i<N; i++) update(1, 1, 2*N, L[X[i]], R[X[i]], W[i]);
	while (Q--){
		LL k, w;
		scanf("%lld %lld", &k, &w);
		k = (k + ans) % (N-1) + 1;
		w = (w + ans) % K;

		update(1, 1, 2*N, L[X[k]], R[X[k]], w-W[k]);
		W[k] = w, ans = T[1].LMR;

		printf("%lld\n", ans);
	}
	return 0;
}