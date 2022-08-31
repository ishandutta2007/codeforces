//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
int a[2][maxn];
int fl[maxn], e[maxn];
int fa[maxn], c[maxn];
priority_queue<pi> x;
int gfa(int a) {
	if (fa[a] == a) return a;
	int f = gfa(fa[a]);
	c[a] ^= c[fa[a]];
	fa[a] = f;
	return f;
}
void ade(int u, int v, int co) {
	int uf = gfa(u), vf = gfa(v);
	fa[uf] = vf;
	c[uf] = c[u] ^ c[v] ^ co;
}
vi tr[maxn];
int main() {
	int n;
	cin >> n;
	int f = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[0][i], &a[1][i]);
		int m = min(a[0][i], a[1][i]), x = max(a[0][i], a[1][i]);
		if (m > n) f = 0;
		if (x <= n) f = 0;
		e[m] = x - n;
		if (a[0][i] == m) fl[m] = 0;
		else fl[m] = 1;
	}
//	cout << f << endl;
	for (int i = 1; i <= n; i++)
		fa[i] = i, c[i] = 0;//, cout << i << ' ' << e[i] << endl;
	for (int i = 1; i <= n; i++) {
		pi um = mp(-e[i], i);
		while (!x.empty()) {
			pi t = x.top();
			if (-t.fi < e[i]) {
				x.pop();
				ade(t.se, i, 1);
				chkmax(um, t);
			}
			else break;
		}
		x.push(um);
	}
	for (int i = 1; i <= n; i++)
		tr[gfa(i)].pb(i);
	//	cout << i << ' ' << fa[i] << ' ' << c[i] << endl;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (fa[i] == i) {
			int r = 0;
			for (auto v : tr[i]) 
				if (c[v] != fl[v]) r += 1;
			vector<pi> h;
			for (auto v : tr[i]) {
				if (c[v]) h.pb(mp(v, n + e[v]));
				else h.pb(mp(n + e[v], v));
			}
			sort(h.begin(), h.end());
			for (int i = 0; i < (int)h.size() - 1; i++) 
				if (h[i].se < h[i + 1].se) f = 0;
			ans += min(r, (int)tr[i].size() - r);
		}
	}
	if (!f) ans = -1;
	cout << ans << endl;
	return 0;
}