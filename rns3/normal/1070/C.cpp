#include <bits/stdc++.h>
using namespace std;

#define N 1010101
#define M 202020

int n, k, m;

vector <int> v[N], u[N];

int le[M], ri[M], c[M], p[M], id[M], rk[M];
long long a[M], b[M];
long long tot = 0, tot_p = 0;

set <int> S;
set <int> :: iterator it;

void add(int id, int d) {
	for (int i = rk[id]; i <= m; i += i & -i) {
		a[i] += d * c[id];
		b[i] += d * 1ll * c[id] * p[id];
	}
	tot += d * c[id];
	tot_p += d * 1ll * c[id] * p[id];
	if (d == 1) S.insert(rk[id]);
	else S.erase(rk[id]);
}

long long calc() {
	if (tot <= k) return tot_p;
	long long cs = 0, ps = 0;
	int now = 0, i = 1 << 18;
	while (i) {
		if (now + i <= m && k - cs >= a[now+i]) {
			cs += a[now+i];
			ps += b[now+i];
			now += i;
		}
		i >>= 1;
	}
	it = S.lower_bound(now + 1);
	int j = *it;
	j = id[j];
	ps += (k - cs) * p[j];
	return ps;
}

bool cmp(int i, int j) {
	return p[i] < p[j];
}

int main() {
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= m; i ++) scanf("%d %d %d %d", &le[i], &ri[i], &c[i], &p[i]), id[i] = i;
	sort(id + 1, id + m + 1, cmp);
	for (int i = 1; i <= m; i ++) rk[id[i]] = i;
	for (int i = 1; i <= m; i ++) {
		v[le[i]].push_back(i);
		u[ri[i]+1].push_back(i);
	}
	long long rlt = 0, now = 0;
	for (int h = 1; h <= n; h ++) {
		if (!u[h].empty() || !v[h].empty()) {
			for (int j = 0; j < v[h].size(); j ++) add(v[h][j], 1);
			for (int j = 0; j < u[h].size(); j ++) add(u[h][j], -1);
			now = calc();
		}
		rlt += now;
	}
	printf("%I64d\n", rlt);

	return 0;
}