//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
#define vl vector<ll>
const int maxn = 1005;
ll f[maxn][maxn];
int n, k;
 
vl mv(vl a, int b) {
	vl res(n);
	vector<pi> h;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && a[j] - j == a[i] - i) j += 1;
		ll cur = 0;
		int nl = i - 1, nr = j;
		for (int u = i; u < j; u++) {
			cur += f[u][b];
			if (cur < 0) {
				cur = 0; 
				nl = u;
			}
		}
		if (nl >= i) h.pb(mp(i, nl));
		cur = 0;
		for (int u = j - 1; u >= i; u--) {
			cur += f[u][b];
			if (cur > 0) {
				cur = 0;
				nr = u;
			}
		}
		if (nl + 1 <= nr - 1) h.pb(mp(nl + 1, nr - 1));
		if (nr < j) h.pb(mp(nr, j - 1));
		i = j;
	}
	vector<ll> g(h.size());
	for (int i = 0; i < h.size(); i++)
		for (int j = h[i].fi; j <= h[i].se; j++)
			g[i] += f[j][b];
 
	for (int i = 0; i < h.size(); i++) {
		if (g[i] == 0) 
			for (int j = h[i].fi; j <= h[i].se; j++) res[j] = a[j];
		else if (g[i] > 0) {
			int mv = 0;
			if (i == h.size() - 1 || g[i + 1] >= 0 || 
				abs(g[i]) > abs(g[i + 1]) || a[h[i + 1].fi] != a[h[i].se] + 2)
				mv = 1;
			else mv = 0;
			for (int j = h[i].fi; j <= h[i].se; j++) res[j] = a[j] + mv;
		}
		else {
			int mv = 0;
			if (i == 0 || g[i - 1] <= 0 || 
				abs(g[i]) >= abs(g[i - 1]) || a[h[i - 1].se] + 2 != a[h[i].fi])
				mv = 1;
			else mv = 0;
			for (int j = h[i].fi; j <= h[i].se; j++) res[j] = a[j] - mv;
		}
	}
	return res;
}
vl mvrd(vl a, ll rd) {
	while (rd) {
		vl cur = a;
		vl nmx = a, nmn = a;
		for (int j = 0; j < k; j++) {
			cur = mv(cur, j);
			for (int u = 0; u < n; u++)
				chkmax(nmx[u], cur[u]), 
				chkmin(nmn[u], cur[u]);
		}
		int flag = 1;
		int ndis = k * 2 + 10;
		ll nm = rd;
		for (int j = 0; j < n - 1; j++)
			if (cur[j] - a[j] != cur[j + 1] - a[j + 1]) {
				if (nmx[j] + 5 > nmn[j + 1]) flag = 0;
				else {
					ll mv = cur[j] - a[j] - (cur[j + 1] - a[j + 1]);
					if (mv > 0) chkmin(nm, (nmn[j + 1] - nmx[j] - ndis) / mv);
				}
			}
		chkmax(nm, 1ll);
		if (!flag) nm = 1;
		vl res(n);
		for (int i = 0; i < n; i++)
			res[i] = a[i] + nm * (cur[i] - a[i]);
		a = res;
		rd -= nm;
	}
	return a;
}
vl cal(vl a, ll t) {
	ll rd = t / k; t %= k;
	a = mvrd(a, rd);
	for (int i = 0; i < t; i++)
		a = mv(a, i % k);
	return a;
}
ll ans[maxn];
pair<ll, int> h[maxn];
ll t[maxn], id[maxn];
int main() {
	cin >> n >> k;
	vl st(n);
	for (int i = 0; i < n; i++) cin >> st[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			cin >> f[i][j];
	int q;
	cin >> q;
	vi cid;
	for (int i = 1; i <= q; i++) {
		cin >> id[i] >> t[i];
		h[i] = mp(t[i] / k, t[i] % k);
		cid.pb(i);
	}
	sort(cid.begin(), cid.end(), [&](int i, int j) {
		return h[i] < h[j];
	});
	vl ff = st;
	ll ls = 0;
	for (auto v : cid) {
		ll nt = h[v].fi;
		ff = mvrd(ff, nt - ls); ls = nt;
		vl cr = ff;
		for (int j = 0; j < h[v].se; j++)
			cr = mv(cr, j);
		ans[v] = cr[id[v] - 1];
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
    return (0-0); //<3
}
/*
2 1
0 4
1
-1
1
1 1
2 1
1 2
2 2
1 3
2 3
 
*/