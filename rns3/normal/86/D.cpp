#include <bits/stdc++.h>
using namespace std;

#define N 202020
#define M 1010101

int n, q;
int le[N], ri[N];
long long ans[N];

bool cmp(int i, int j) {
	return ri[i] < ri[j];
}

int L = 1, R = 0;
int cnt[M];
long long now = 0;

void add(int x, int val) {
	now -= 1ll * cnt[x] * cnt[x] * x;
	cnt[x] += val;
	now += 1ll * cnt[x] * cnt[x] * x;
}

int a[N];

void go(int le, int ri) {
	while (L < le) add(a[L], -1), L ++;
	while (L > le) L --, add(a[L], 1);
	while (R > ri) add(a[R], -1), R --;
	while (R < ri) R ++, add(a[R], 1);
}

void solve(vector <int> &v, bool rv = 0) {
	if (v.empty()) return;
	sort(v.begin(), v.end(), cmp);
	if (rv) reverse(v.rbegin(), v.rend());
	for (int k = 0; k < v.size(); k ++) {
		go(le[v[k]], ri[v[k]]);
		ans[v[k]] = now;
	}
}

vector <int> v[N];

const int K = 500;

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1, x, y; i <= q; i ++) {
		scanf("%d %d", &x, &y);
		v[(x-1)/K].push_back(i);
		le[i] = x, ri[i] = y;
	}
	bool rv = 0;
	for (int i = 0; i <= (n / K); i ++) {
		solve(v[i], rv);
		rv = !rv;
	}
	for (int i = 1; i <= q; i ++) printf("%I64d\n", ans[i]);

	return 0;
}