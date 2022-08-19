#include <bits/stdc++.h>
using namespace std;
#define maxn 155
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
struct th {
	bitset<maxn> a[maxn];
	th() {
		for (int i = 0; i < maxn; i++)
			a[i][i] = 1;
	}
	th operator * (th &b) {
		bitset<maxn> u[maxn];
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				u[i][j] = b.a[j][i];
		th fn;
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				if ((a[i] & u[j]).count()) fn.a[i][j] = 1;
				else fn.a[i][j] = 0;
		return fn;
	}
}fr, ned, ur;
int dis[maxn][maxn];
struct edge {
	int u, v, d;
	bool operator < (const edge &r) const {
		return d < r.d;
	}
}p[maxn];
th ksm(th& a, int b) {
	th pw = a, res = th();
	for (int i = 1; i <= b; i <<= 1) {
		if (b & i) res = res * pw;
		pw = pw * pw;
	}
	return res;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &p[i].u, &p[i].v, &p[i].d);
	sort(p + 1, p + m + 1);
	fr = th();
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			fr.a[i][j] = 0, ned.a[i][j] = 0;
	fr.a[1][1] = 1;
	const int inf = 1070000000;
	int ans = inf * 2;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = inf;
	for (int i = 1; i <= m; i++) {
		int ntm = 0;
		ur = ksm(ned, p[i].d - p[i - 1].d);
		fr = fr * ur;
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dis[j][k] = min(dis[j][k], dis[j][p[i].u] + 1 + dis[p[i].v][k]);
		for (int j = 1; j <= n; j++)
			if (fr.a[1][j])
				ans = min(ans, dis[j][n] + p[i].d);
		ned.a[p[i].u][p[i].v] = 1;
	}
	if (ans >= inf) cout << "Impossible" << endl;
	else cout << ans << endl;
	return 0;
}