#include <bits/stdc++.h>
using namespace std;
#define maxn 500005
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define se second
#define mp make_pair
#define pi pair<int, int>
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int u[maxn], v[maxn];
struct oni {
	int fa[maxn], col[maxn], sz[maxn];
	int q[100], ed;
	int lk[maxn];
	void init() {
		ed = 0;
		for (int i = 0; i < maxn; i++)
			fa[i] = i, col[i] = 0, sz[i] = 1, lk[i] = 0;
	}
	void gfa(int a) {
		q[ed++] = a;
		if (a == fa[a]) return ;
		gfa(fa[a]);
	}
	int gf(int a) {
		ed = 0;
		gfa(a);
		return q[ed - 1];
	}
	int gc(int a) {
		ed = 0;
		gfa(a);
		int ans = 0;
		for (int i = 0; i < ed; i++)
			ans ^= col[q[i]];
		return ans;
	}
	bool check(int id) {
		int ufa = gf(u[id]), vfa = gf(v[id]);
		if (ufa != vfa) return 1;
		if (gc(u[id]) == gc(v[id])) return 0;
		return 1;
	}
	void link(int id) {
		int ufa = gf(u[id]), vfa = gf(v[id]);
		lk[id] = 0;
		if (ufa == vfa) return ;
		if (sz[ufa] > sz[vfa]) swap(ufa, vfa);
		lk[id] = ufa, 
		fa[ufa] = vfa, 
		sz[vfa] += sz[ufa];
		col[ufa] = 1 ^ gc(u[id]) ^ gc(v[id]);
	}
	void cut(int id) {
		if (!lk[id]) return ;
		int ns = lk[id];
		if (fa[ns] == ns) exit(1);
		ed = 0, 
		gfa(fa[ns]);
		for (int i = 0; i < ed; i++)
			sz[q[i]] -= sz[ns];
		fa[ns] = ns, col[ns] = 0;
		lk[id] = 0;
	}
}sol[55];
int e[maxn], c[maxn];
int nr[maxn]; // 
int ans[maxn]; 
struct ST {
	int l, r;
	ST *ch[2];
	vector<pi> act; 
}p[maxn << 1], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r;
	if (l == r) return ;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
}
void push(ST *a, int l, int r, pi num) {
	if (l > r) return ;
	if (a->l == l && a->r == r) {
		a->act.pb(num);
		return ;
	}
	int mid = (a->l + a->r) >> 1;
	if (r <= mid) push(a->ch[0], l, r, num);
	else if (l > mid) push(a->ch[1], l, r, num);
	else push(a->ch[0], l, mid, num), 
		push(a->ch[1], mid + 1, r, num);
}
int n, m, k, q;
vi to[maxn];
void work(ST *a) {
	for (auto i : a->act)
		sol[i.fi].link(i.se);
	if (a->l == a->r) {
		if (a->l != q + 1) {
			int npl = a->l;
			int nx = *lower_bound(to[e[npl]].begin(), to[e[npl]].end(), npl + 1);
			if (sol[c[npl]].check(e[npl])) {
				ans[npl] = 1;
				nr[e[npl]] = c[npl];
				push(root, npl + 1, nx, mp(c[npl], e[npl]));
			}
			else if (nr[e[npl]]) push(root, npl + 1, nx, mp(nr[e[npl]], e[npl]));
		}
	}
	else work(a->ch[0]), work(a->ch[1]);
	for (auto i : a->act)
		sol[i.fi].cut(i.se);
}
int main() {
	
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= k; i++)
		sol[i].init();
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &u[i], &v[i]);
	for (int i = 1; i <= q; i++) 
		scanf("%d%d", &e[i], &c[i]), 
		to[e[i]].pb(i);
	for (int i = 1; i <= m; i++)
		to[i].pb(q + 1);
	root = &p[stcnt++];
	bdtree(root, 1, q + 1);
	work(root);
	for (int i = 1; i <= q; i++)
		if (ans[i]) printf("YES\n");
		else printf("NO\n");
	return 0;
}
/*
3 3 2 1
1 2
2 3
1 3
1 1
*/