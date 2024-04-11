#include <bits/stdc++.h>
#define ll long long
#define maxn 150005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
struct bit {
	int d[maxn];
	int lb(int x) {
		return x & -x;
	}
	void upd(int a, int num) {
		while (a < maxn) {
			d[a] = (d[a] + num) % mod;
			a += lb(a);
		}
	}
	void upd(int l, int r, int num) {
		upd(l, num), upd(r + 1, -num);
	}
	ll q(int a) {
		ll ans = 0;
		while (a) {
			ans += d[a], a -= lb(a);
		}
		return ans % mod;
	}
}s;
int n;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct edge {
	int u, v, fl;
	edge *next;
	edge *rev;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void ade(int u, int v) {
	edge *n1 = &p[egcnt++];
	edge *n2 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->fl = 1;
	n2->u = v, n2->v = u, n2->fl = 1;
	n1->rev = n2, n2->rev = n1;
	n1->next = h[u], h[u] = n1;
	n2->next = h[v], h[v] = n2; 
}
int mxsz;
int ns, nans;
int sz[maxn], dfn[maxn], dfcnt, fa[maxn];
int q[maxn], ed;
void dfs2(int a, int fa) {
	// *** ed
	q[ed++] = a;
	for (edge *p = h[a]; p; p = p->next) {
		if (p->v == fa) continue;
		dfs2(p->v, a);
	} 
} 
void dfs1(int a) {
	dfn[a] = ++dfcnt;
	sz[a] = 1;
	for (edge *p = h[a]; p; p = p->next) {
		if (p->v == fa[a]) continue;
		fa[p->v] = a, dfs1(p->v);
		sz[a] += sz[p->v];
	}
}
int d[maxn];	
const int sqr = 400;
int blsz[maxn / sqr * 2 + 2][maxn];
int id[maxn], rs[maxn], qs; 
int main() {
	cin >> n >> qs;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		ade(u, v);
		d[u]++, d[v]++;
	}
	dfs1(1);
	int idcnt = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] < sqr) continue;
		else {
			id[i] = ++idcnt;
			for (edge *p = h[i]; p; p = p->next) {
				ed = 0;
				dfs2(p->v, i);
				for (int i = 0; i < ed; i++)
					blsz[idcnt][q[i]] = ed;
			}
		}
	} 
	ll bk = ksm(n, mod - 2);
	ll ss = 0;
	for (int i = 0; i < qs; i++) {
		int tp, v, k;
		scanf("%d%d", &tp, &v);
		if (tp == 2) {
			ll ans = s.q(dfn[v]);
			for (int i = 1; i <= idcnt; i++)
				ans += 1ll * rs[i] * blsz[i][v], ans %= mod;
			ans = ans * bk % mod;
			ans = ss - ans; ans %= mod;
			if (ans < 0) ans += mod;
			printf("%lld\n", ans);
		}
		else {
			scanf("%d", &k);
			ss = (ss + k) % mod; 
			if (d[v] >= sqr) rs[id[v]] = (rs[id[v]] + k) % mod;
			else {
				for (edge *p = h[v]; p; p = p->next) {
					if (p->v == fa[v]) {
						int cur = 1ll * (n - sz[v]) * k % mod;
						s.upd(1, dfn[v] - 1, cur);
						s.upd(dfn[v] + sz[v], n, cur);
					}
					else {
						int cur = 1ll * sz[p->v] * k % mod;
						s.upd(dfn[p->v], dfn[p->v] + sz[p->v] - 1, cur);
					}
				}
			}
		}
		
	}
	return 0;
}
/*
CHHOCH
*/