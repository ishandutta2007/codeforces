#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N = 5e4L + 11, M = 1e6L + 11;
int u[M], v[M];
int t[N];
vector <int> l[N];

struct edge {
	int u, v;
};

int c[M];
int solve(int l, int r, vector <edge> es) {
	if(l + 1 == r) {
		c[l] = 1;
		return 0;
	}
	int m = (l + r) / 2;
	vector <edge> el, er, en;
	for(edge e : es)
		if(e.v < m)
			el.pb(e);
		else if(e.u >= m)
			er.pb(e);
		else
			en.pb(e);
	int ret = solve(l, m, el) + solve(m, r, er);
	int t = 0;
	for(edge e : en)
		if(c[e.u] != c[e.v]) t ++;
	if(t < en.size() - t) {
		t = en.size() - t;
		for(int i = m; i < r; i ++)
			c[i] = 3 - c[i];
	}
	ret += t;
	return ret;
}

int main() {
	srand(25252);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		scanf("%d%d", u + i, v + i);
		swap(u[i], v[i]);
	}	
	int T = 0;
	for(int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x);
		while(x --) {
			int y; scanf("%d", &y);
			T = max(T, y);
			l[i].pb(y);
		}
	}
	while(1) {
		for(int i = 1; i <= n; i ++) {
			t[i] = l[i][rand() % l[i].size()];
		}
		vector <edge> es;
		for(int i = 1; i <= m; i ++) {
			int a = t[u[i]], b = t[v[i]];
			if(a > b) swap(a, b);
			if(a != b) es.pb({a, b});
		}
		if(solve(1, T + 1, es) * 2 >= m)
			break;
	}
	for(int i = 1; i <= n; i ++)
		printf("%d ", t[i]);
	puts("");
	for(int i = 1; i <= T; i ++)
		printf("%d ", c[i]);
	puts("");
}