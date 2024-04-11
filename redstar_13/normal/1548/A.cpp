#include<bits/stdc++.h>

using namespace std;

const int NN = 202020;

set<int> adj[NN];
int ans = 0;
int flag[NN];
int n, m;

int insert(int u, int v) {
	if(u > v) swap(u, v);
	if(flag[u] == 0) {
		flag[u] = 1;
		ans --;
	}
	adj[u].insert(v);
}

int erase(int u, int v) {
	if(u > v) swap(u, v);
	adj[u].erase(v);
	ans += flag[u];
	flag[u] = 0;
	if(adj[u].size()) {
		flag[u] = 1;
		ans --;
	}
}

void solve() {
	int op;
	scanf("%d", &op);
	if(op == 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		insert(u, v);
		return ;
	}
	if(op == 2) {
		int u, v;
		scanf("%d %d", &u, &v);
		erase(u, v);
		return ;
	}
	printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	cin >> n >> m;
	ans = n;
	for(int i = 0; i < m; i ++) {
		int u, v;
		scanf("%d %d", &u, &v);
		insert(u, v);
	}
	int q;
	cin >> q;
	
	while(q--) solve();
}