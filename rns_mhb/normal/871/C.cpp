#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

#define N 101010
#define M 303030

int n, m;
int x[N], y[N], xx[N], yy[N], type[M], q[M];

vector <int> v[M], u[M];

map <int, bool> mp;
map <int, bool> :: iterator it;

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &y[i]), xx[i] = x[i], yy[i] = y[i];
	sort (xx + 1, xx + n + 1);
	sort (yy + 1, yy + n + 1);
	for (int i = 1; i <= n; i ++) {
		x[i] = lower_bound(xx + 1, xx + n + 1, x[i]) - xx;
		x[i] <<= 1;
		y[i] = lower_bound(yy + 1, yy + n + 1, y[i]) - yy;
		y[i] <<= 1;
		y[i] |= 1;
	}
	int m = n * 2 + 3;
	for (int i = 1; i <= n; i ++) {
		u[x[i]].push_back(i);
		u[y[i]].push_back(i);
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
	}
	int ans = 1;
	int cnt = 0;
	for (int k = 0; k <= m; k ++) if (!v[k].empty() && !type[k]) {
		cnt ++;
		int e = 0;
		q[++e] = k;
		type[k] = cnt;
		for (int f = 1; f <= e; f ++) {
			int now = q[f];
			for (int i = 0; i < v[now].size(); i ++) if (!type[v[now][i]]) {
				type[v[now][i]] = cnt;
				q[++e] = v[now][i];
			}
		}
		mp.clear();
		for (int i = 1; i <= e; i ++) {
			for (int j = 0; j < u[q[i]].size(); j ++) {
				mp[u[q[i]][j]] = 1;
			}
		}
		int sz = 0;
		for (it = mp.begin(); it != mp.end(); it ++) sz ++;//printf("%d %d\n", sz, e);
		if (sz >= e) ans = 1ll * ans * expmod(2, e) % mod;
		else ans = 1ll * ans * (expmod(2, e) - 1) % mod;
	}
	printf("%d\n", ans);

	return 0;
}