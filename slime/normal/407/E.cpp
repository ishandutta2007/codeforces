#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int k, d, n;
int a[maxn];
int L, R;
map<int, int> pl;
struct ST {
	int l, r;
	ST *ch[2];
	ll lz, mns;
}p[maxn << 1], *root;
int stcnt = 0;
void upd(ST *a) {
	a->mns = min(a->ch[0]->mns, a->ch[1]->mns);
}
void bdtree(ST *a, int l, int r) {
	a->l = l, a->r = r, a->lz = 0;
	if (l == r) {
		a->mns = -l;
		return ;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
	upd(a); 
}
void actlz(ST *a, ll lz) {
	a->lz += lz, a->mns += lz;
}
void pushdown(ST *a) {
	if (a->lz)
		actlz(a->ch[0], a->lz), 
		actlz(a->ch[1], a->lz), 
		a->lz = 0;
}
void push(ST *a, int l, int r, int lz) {
	if (a->l == l && a->r == r) {
		actlz(a, lz);
		return ;
	}
	int mid = (a->l + a->r) >> 1;
	pushdown(a);
	if (r <= mid) push(a->ch[0], l, r, lz);
	else if (l > mid) push(a->ch[1], l, r, lz);
	else 
		push(a->ch[0], l, mid, lz),
		push(a->ch[1], mid + 1, r, lz);
	upd(a);
}
int qpl(ST *a, int num) {
	// <= num 
	if (a->l == a->r) return a->l;
	pushdown(a);
	if (a->ch[1]->mns <= num) return qpl(a->ch[1], num);
	else return qpl(a->ch[0], num);
}
const int inf = 2e9 + 7;
struct sta {
	vector<pi> r;
	sta() {} 
	void init(int num) {
		r.clear(); 
		r.pb(mp(inf, num));
	} 
	void pb(int pl, int num) {
		pi q = mp(num, pl);
		while (q > r[r.size() - 1]) { 
			push(root, r[r.size() - 1].se, r[r.size() - 2].se - 1, -r[r.size() - 1].fi), 
		//	cout << "PUSH" <<  r[r.size() - 1].se << ' ' << r[r.size() - 2].se - 1 << ' ' <<  -r[r.size() - 1].fi << endl, 
			r.pop_back();
		} 
		r.pb(q);
	//	cout << "!!!!" << q.fi << ' ' << r[r.size() - 1].fi << endl; 
		push(root, r[r.size() - 1].se, r[r.size() - 2].se - 1, r[r.size() - 1].fi);
	//	cout << "PUSH" <<  r[r.size() - 1].se << ' ' << r[r.size() - 2].se - 1 << ' ' << r[r.size() - 1].fi << ' ' << r.size() << endl; 
	}
}ss[2];
void work(vi g, int pls) {
/*	cout << "WORK" << endl; 
	for (int i = 0; i < g.size(); i++)
		cout << g[i] << ' ' ;
	cout << endl; 
*/	pl.clear();
	ss[0].init(g.size()), 
	ss[1].init(g.size());
	root = &p[stcnt++];
	int sz = g.size() - 1;
	bdtree(root, 0, sz);
	for (int i = sz; i >= 0; i--) {
		ss[0].pb(i, g[i]), 
		ss[1].pb(i, -g[i]);
		if (pl[g[i]]) 
			push(root, pl[g[i]], sz, 1e9);
		pl[g[i]] = i;
		int npl = qpl(root, k - i);
	//	cout << npl << ' ' << R << ' ' << endl; 
		if (npl - i > R - L || (npl - i == R - L && pls + i < L)) 
			R = npl + pls, 
			L = pls + i; 
	}
}
int main() {
	L = 1, R = 0;
	cin >> n >> k >> d;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (d == 0) {
		int nl = 1, nr = 0;
		for (int i = 0; i < n; ) {
			int j = i;
			while (j < n && a[j] == a[i]) j++;
			if (j - 1 - i > nr - nl)
				nl = i, nr = j - 1;
			i = j; 
		}
		cout << nl + 1 << ' ' << nr + 1 << endl;
		return 0;
	}
	vi r;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && (a[i] - a[j]) % d == 0) j++;
		r.resize(j - i);
		for (int s = i; s < j; s++)
			r[s - i] = a[s];
		for (int s = r.size() - 1; s >= 0; s--)
			r[s] = (r[s] - r[0]) / d;
		work(r, i);
		i = j;
	}
	cout << L + 1 << ' ' << R + 1 << endl;
	return 0;
}