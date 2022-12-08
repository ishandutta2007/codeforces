#include <bits/stdc++.h>

using namespace std;

struct dt {
	int a, b, c, d, e, n;
} x[200005];

char s[400005];

int cmp1(dt &u, dt &v) {
	return u.a * 2 - u.n > v.a * 2 - v.n;
}

int cmp2(dt &u, dt &v) {
	return u.b * 2 - u.n > v.b * 2 - v.n;
}

int cmp3(dt &u, dt &v) {
	return u.c * 2 - u.n > v.c * 2 - v.n;
}

int cmp4(dt &u, dt &v) {
	return u.d * 2 - u.n > v.d * 2 - v.n;
}

int cmp5(dt &u, dt &v) {
	return u.e * 2 - u.n > v.e * 2 - v.n;
}

void solve() {
	int n;
	scanf("%d", &n);
	memset(x, 0, sizeof(dt) * (n + 5));
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		int len = strlen(s);
		x[i].n = len;
		for (int j = 0; j < len; ++j) {
			if (s[j] == 'a')++x[i].a;
			if (s[j] == 'b')++x[i].b;
			if (s[j] == 'c')++x[i].c;
			if (s[j] == 'd')++x[i].d;
			if (s[j] == 'e')++x[i].e;
		}
	}
	int ans, p, q, maxm = 0;
	sort(x, x + n, cmp1);
	ans = p = q = 0;
	for (int i = 0; i < n; ++i) {
		p += x[i].a;
		q += x[i].n - x[i].a;
		if (p > q)++ans;
		else break;
	}
	maxm = max(maxm, ans);
	sort(x, x + n, cmp2);
	ans = p = q = 0;
	for (int i = 0; i < n; ++i) {
		p += x[i].b;
		q += x[i].n - x[i].b;
		if (p > q)++ans;
		else break;
	}
	maxm = max(maxm, ans);
	sort(x, x + n, cmp3);
	ans = p = q = 0;
	for (int i = 0; i < n; ++i) {
		p += x[i].c;
		q += x[i].n - x[i].c;
		if (p > q)++ans;
		else break;
	}
	maxm = max(maxm, ans);
	sort(x, x + n, cmp4);
	ans = p = q = 0;
	for (int i = 0; i < n; ++i) {
		p += x[i].d;
		q += x[i].n - x[i].d;
		if (p > q)++ans;
		else break;
	}
	maxm = max(maxm, ans);
	sort(x, x + n, cmp5);
	ans = p = q = 0;
	for (int i = 0; i < n; ++i) {
		p += x[i].e;
		q += x[i].n - x[i].e;
		if (p > q)++ans;
		else break;
	}
	maxm = max(maxm, ans);
	printf("%d\n", maxm);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}