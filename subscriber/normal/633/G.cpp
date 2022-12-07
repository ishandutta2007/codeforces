#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;
typedef unsigned long long ull;

ull bs[400444][18];
ull te[18], h[18];

int sz, n, m;

int in[N], out[N], u[N];
int T;

int a[N];
vector<int> v[N];

int down[400444];

void dfs(int x, int p) {
	in[x] = T;
	u[T] = x;
	T++;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) {
		dfs(v[x][i], x);
	}
	out[x] = T - 1;
}

void upd(int pos) {
	for (int i = 0; i < sz; i++) bs[pos][i] = bs[pos + pos][i] | bs[pos + pos + 1][i];
}

void init(int pos, int l, int r) {
	if (l == r) {
		int t = a[u[l]] % m;
		bs[pos][t >> 6] |= pw(t & 63);
		return;
	}
	init(pos + pos, l, (l + r) / 2);
	init(pos + pos + 1, (l + r) / 2 + 1, r);
	upd(pos);
}

void mod(int pos, int l, int r, int ll, int rr, int va) {
	ll = max(ll, l);
	rr = min(rr, r);
	if (ll > rr) return;
	if (l == ll && r == rr) {
		down[pos] = (down[pos] + va) % m;

		for (int i = 0; i < 18; i++) te[i] = 0;

		for (int i = 0; i < sz; i++) {
			int to = (i * 64 + va) % m;
			int r = (to >> 6);
			int sh = to & 63;

			if (sh == 0) {
				te[r] |= bs[pos][i];
			} else {
				te[r] |= bs[pos][i] << sh;
				te[r + 1] |= bs[pos][i] >> (64 - sh);
			}
		}
		int mo = 0;
		for (int i = m; i < m + 65; i++) {
			if (te[i >> 6] & pw(i & 63)) {
				te[mo >> 6] |= pw(mo & 63);
				te[i >> 6] ^= pw(i & 63);
			}
			mo++;
			if (mo == m) mo = 0;
		}			
		for (int i = 0; i < sz; i++) bs[pos][i] = te[i];
		return;
	}
	if (down[pos] != 0) {
		mod(pos + pos, l, (l + r) / 2, l, (l + r) / 2, down[pos]);
		mod(pos + pos + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, r, down[pos]);
		down[pos] = 0;
		upd(pos);
	}

	mod(pos + pos, l, (l + r) / 2, ll, rr, va);
	mod(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr, va);
	down[pos] = 0;
	upd(pos);
}

void col(int pos, int l, int r, int ll, int rr) {
	ll = max(l, ll);
	rr = min(r, rr);
	if (ll > rr) return;
	if (l == ll && r == rr) {
		for (int i = 0; i < sz; i++) h[i] |= bs[pos][i];
		return;
	}
	if (down[pos] != 0) {
		mod(pos + pos, l, (l + r) / 2, l, (l + r) / 2, down[pos]);
		mod(pos + pos + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, r, down[pos]);
		down[pos] = 0;
		upd(pos);
	}

	col(pos + pos, l, (l + r) / 2, ll, rr);
	col(pos + pos + 1, (l + r) / 2 + 1, r, ll, rr);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);

	cin >> n >> m;
	sz = m / 64 + 1;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	vector<int> e;
	for (int i = 2; i < m; i++) {
		int ok = 1;
		for (int j = 0; j < e.size(); j++) if (i % e[j] == 0) ok = 0;
		if (ok) e.pb(i);
	}

	dfs(0, 0);

	init(1, 0, n - 1);

	int q;
	cin >> q;
	while (q--) {
		int ty, x;
		cin >> ty >> x;
		x--;
		if (ty == 1) {
			int va;
			cin >> va;

			mod(1, 0, n - 1, in[x], out[x], va % m);
		} else {
			for (int i = 0; i < sz; i++) h[i] = 0;
			col(1, 0, n - 1, in[x], out[x]);

//			for (int i = 0; i < m; i++) if (h[i >> 6] & pw(i & 63)) cout << i << " ";
//			cout << endl;

			int ans = 0;
			for (int i = 0; i < e.size(); i++) if (h[e[i] >> 6] & pw(e[i] & 63)) ans++;
			cout << ans << endl;
		}

	}
	
	return 0;
}