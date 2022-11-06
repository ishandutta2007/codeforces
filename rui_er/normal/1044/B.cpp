//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e3+5; 

int T, n, colA[N], colB[N], vis[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
vector<int> a, b, e[N];
int ask(char op, int val) {
	printf("%c %d\n", op, val);
	fflush(stdout);
	int res = 0;
	if(op != 'C') {
		scanf("%d", &res);
		if(res == -1) exit(0);
	}
	return res;
}
int bfs(int s) {
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(colA[u]) return u;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v : e[u]) {
			if(!vis[v]) q.push(v);
		}
	}
	return -1;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n-1) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int k;
		scanf("%d", &k);
		a.resize(k);
		rep(i, 0, k-1) scanf("%d", &a[i]);
		for(int i : a) colA[i] = 1;
		scanf("%d", &k);
		b.resize(k);
		rep(i, 0, k-1) scanf("%d", &b[i]);
		for(int i : b) colB[i] = 1;
		int u = ask('B', b[0]);
		if(colA[u]) ask('C', u);
		else {
			int v = bfs(u);
			int qwq = ask('A', v);
			if(colB[qwq]) ask('C', v);
			else ask('C', -1);
		}
		rep(i, 1, n) colA[i] = colB[i] = vis[i] = 0;
		a.clear(); b.clear();
		rep(i, 1, n) e[i].clear();
	}
	return 0;
}