#include <bits/stdc++.h>
using namespace std;

#define N 101010

const int K = 400;

int n;
int c[N];

vector <int> v[N];

int e = 0;
int id[N];

int le[N], ri[N];

void dfs(int x) {
	id[++e] = x;
	le[x] = e;
	for (int i = 0, y; i < v[x].size(); i ++) {
		y = v[x][i];
		if (le[y]) continue;
		dfs(y);
	}
	ri[x] = e;
}

long long s[N];
int cnt[N];

int mx = 0;

void add(int id, int d) {
	s[cnt[c[id]]] -= c[id];
	cnt[c[id]] += d;
	s[cnt[c[id]]] += c[id];
	if (s[mx+1]) mx ++;
	else if (mx && !s[mx]) mx --;
}

long long calc() {
	return s[mx];
}

int L, R;

void go(int le, int ri) {
	while (le > L) add(id[L], -1), L ++;
	while (ri > R) R ++, add(id[R], 1);
	while (le < L) L --, add(id[L], 1);
	while (ri < R) add(id[R], -1), R --;
}

vector <int> u[N];

bool cmp(int i, int j) {
	return ri[i] < ri[j];
}

long long ans[N];

void solve(vector <int> &u, bool rv) {
	if (rv) sort(u.begin(), u.end(), cmp);
	else sort(u.rbegin(), u.rend(), cmp);
	for (int i = 0; i < u.size(); i ++) {
		go(le[u[i]], ri[u[i]]);
		ans[u[i]] = calc();
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	for (int i = 1, x, y; i < n; i ++) scanf("%d %d", &x, &y), v[x].push_back(y), v[y].push_back(x);
	dfs(1);
	for (int i = 1, type; i <= n; i ++) {
		type = le[i] / K;
		u[type].push_back(i);
	}
	L = 1, R = 0;
	bool rv = 0;
	for (int i = 0; i < N; i ++) if (!u[i].empty()) {
		solve(u[i], rv);
		rv = !rv;
	}
	for (int i = 1; i <= n; i ++) printf("%I64d%c", ans[i], i == n ? '\n' : ' ');

	return 0;
}