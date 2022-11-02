#include <bits/stdc++.h>
using namespace std;

const double Eps = 1e-9;
using vi = vector <int>;
using vd = vector <double>;

#define pb push_back
#define fi first
#define se second

vd simplex(vector <vd> a, vd b, vd c) {
	int n = a.size(), m = a[0].size() + 1, r = n, s = m - 1;
	vector <vd> d(n + 2, vd(m + 1, 0)); vd x(m - 1);
	vi ix(n + m); iota(ix.begin(), ix.end(), 0);
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m - 1; j ++) d[i][j] = -a[i][j];
			d[i][m - 1] = 1; d[i][m] = b[i];
		if(d[r][m] > d[i][m]) r = i;
	}
	for(int j = 0; j < m - 1; j ++) d[n][j] = c[j];
	d[n + 1][m - 1] = -1;
	while(true) {
		if(r < n) { vd su;
			swap(ix[s], ix[r + m]); d[r][s] = 1 / d[r][s];
			for(int j = 0; j <= m; j ++) if(j != s) {
				d[r][j] *= -d[r][s]; if(d[r][j]) su.pb(j);
			}
			for(int i = 0; i <= n + 1; i ++) if(i != r) {
				for(int j = 0; j < su.size(); j ++)
					d[i][su[j]] += d[r][su[j]] * d[i][s];
				d[i][s] *= d[r][s];
		}} r = s = -1;
		for(int j = 0; j < m; j ++) if(s < 0 || ix[s] > ix[j])
			if(d[n + 1][j] > Eps || d[n + 1][j] > -Eps &&
				d[n][j] > Eps) s = j; if(s < 0) break;
		for(int i = 0; i < n; i ++) if(d[i][s] < -Eps) {
			if(r < 0) { r = i; continue; }
			double e = d[r][m] / d[r][s] - d[i][m] / d[i][s];
			if(e < -Eps || e < Eps &&
				ix[r + m] > ix[i + m]) r = i;
		} if(r < 0) return vd(); // 
	} if(d[n + 1][m] < -Eps) return vd(); // 
	for(int i = m; i < n + m; i ++)
		if(ix[i] < m - 1) x[ix[i]] = d[i - m][m];
	return x;
}

const int N = 511;
using ll = long long;
vector <pair <int, int>> e[N];
ll dis[N][N];
bool black[N];

void dfs(int x, int p, int r, ll d) {
	dis[r][x] = d;
	for(auto i : e[x]) if(i.fi != p)
		dfs(i.fi, x, r, d + i.se);
}

int main() {
	ios :: sync_with_stdio(false);
	int n, x; cin >> n >> x;
	for(int i = 0; i < n; i ++) cin >> black[i];
	for(int i = 1; i < n; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		u --; v --;
		e[u].pb({v, w});
		e[v].pb({u, w});
	}
	for(int i = 0; i < n; i ++)
		dfs(i, -1, i, 0);
	int cnt = accumulate(black, black + n, 0);
	vector <vd> a(n + 2, vd(n, 0));
	vd b(n + 2, 0), c(n, 0);
	for(int i = 0; i < n; i ++) {
		b[i] = -1;
		for(int j = 0; j < n; j ++) if(dis[i][j] <= x)
			a[i][j] = -1;
	}
	b[n] = cnt; b[n + 1] = -cnt;
	for(int i = 0; i < n; i ++) {
		a[n][i] = 1;
		a[n + 1][i] = -1;
	}
	for(int i = 0; i < n; i ++)
		if(!black[i]) c[i] = -1;
	auto v = simplex(a, b, c);
	if(!v.size()) cout << -1 << '\n';
	else {
		double ans = 0;
		for(int i = 0; i < n; i ++)
			ans += c[i] * v[i];
		cout << llround(-ans) << '\n';
	}
	return 0;
}