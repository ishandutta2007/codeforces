#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M, Q;
set<int> adj[202020];
int ans;
bool isok[201010];

void update(int p) {
	bool isok2;
	if (adj[p].empty()) {
		isok2 = true;
	} else {
		isok2 = p > *--adj[p].end();
	}
	if (isok[p]) --ans;
	if (isok2) ++ans;
	isok[p] = isok2;
	// printf("%d\n", ans);
}

void add_edge(int u, int v) {
	adj[u].insert(v);
	adj[v].insert(u);
	update(u);
	update(v);
}

void rm_edge(int u, int v) {
	adj[u].erase(v);
	adj[v].erase(u);
	update(u);
	update(v);
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		isok[i] = true;
	}
	ans = N;
	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		add_edge(u, v);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int u, v;
			scanf("%d%d", &u, &v);
			--u; --v;
			add_edge(u, v);
		} else if (t == 2) {
			int u, v;
			scanf("%d%d", &u, &v);
			rm_edge(--u, --v);
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}