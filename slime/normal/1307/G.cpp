#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
namespace MCMF  { //  
	const int M = 5005, N = 55;
	struct edge {
		int u, v, c, w;
		edge *next;
		edge *rev;
	}p[M], *h[N];
	int egcnt = 0;
	void ade(int u, int v, int c, int w) {
		edge *n1 = &p[egcnt++];
		edge *n2 = &p[egcnt++];
		n1->u = u, n1->v = v, n1->c = c, n1->w = w;
		n2->u = v, n2->v = u, n2->c = 0, n2->w = -w;
		n1->next = h[u], h[u] = n1;
		n2->next = h[v], h[v] = n2;
		n1->rev = n2, n2->rev = n1;
	} 
	int dis[N], s, t, inq[N];
	edge *pre[N];
	void init(int a, int b) {
		s = a, t = b;
		for (int i = 0; i < N; i++)
			h[i] = NULL;
	}
	vector<pi> ans;
	const int inf = 1e9 + 7;
	void spfa() {
		int tflow = 0, tcost = 0;
		while (1) {
			
			for (int i = 0; i < N; i++) dis[i] = inf, inq[i] = 0;
			queue<int> g;
			dis[s] = 0, g.push(s), inq[s] = 1;
			while (!g.empty()) {
				int fr = g.front(); g.pop();
				inq[fr] = 0;
				for (edge *p = h[fr]; p; p = p->next) {
					if (!p->c) continue;
					int ndis = p->w + dis[fr];
					if (ndis < dis[p->v]) {
						dis[p->v] = ndis, pre[p->v] = p;
						if (!inq[p->v]) inq[p->v] = 1, g.push(p->v);
					}
				}
			}
			if (dis[t] == inf) break;
			int pl = t, us = 0, uc = inf;
			while (pl != s) {
				us += pre[pl]->w;
				uc = min(uc, pre[pl]->c);
				pl = pre[pl]->u;
			}
			tflow += uc, tcost += us * uc;
			pl = t;
			while (pl != s) {
				pre[pl]->c -= uc;
				pre[pl]->rev->c += uc;
				pl = pre[pl]->u;
			}
			ans.pb(mp(tflow, tcost));
		}
	}
	db check(int r) {
		db res = inf;
		for (auto v : ans)
			res = min(res, 1.0 * (v.se + r) / v.fi);
		return res;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	MCMF::init(1, n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		MCMF::ade(u, v, 1, w);
	}
	MCMF::spfa();
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x;
		scanf("%d", &x);
		db ans = MCMF::check(x);
		printf("%.10lf\n", ans);
	}
	return 0;
}