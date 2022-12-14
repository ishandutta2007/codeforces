#include <bits/stdc++.h>
using namespace std;

#define N 100010

const double pi = 3.141592653589793;

int n, r, h, id[N], idx[N];
long long w[N], fen[N], ans;

bool cmp(int r, int s) {
	if (w[r] == w[s]) return s < r;
	return w[r] < w[s];
}

void add(int x, long long y) {
	ans = max(ans, y);
	while (x <= n) {
		fen[x] = max(fen[x], y);
		x += x & -x;
	}
}

long long calc(int x) {
	long long res = 0;
	while (x) {
		res = max(res, fen[x]);
		x -= x & -x;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &r, &h);
		w[i] = 1ll * r * r * h;
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i ++) idx[id[i]] = i;
	for (int i = 1; i <= n; i ++) add(idx[i], calc(idx[i]) + w[i]);
	printf("%.8lf", pi * ans);
	return 0;
}