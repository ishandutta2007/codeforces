#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 310000;
const long long P = 1000000007LL;
vector < int > g[maxN];
int n, q;
int v[maxN];
int mode[maxN], p[maxN];

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1;
	}
	long long b = powmod(a, n / 2);
	b = (b * b) % P;
	if (n % 2 == 1) {
		return (a * b) % P;
	}
	return b;
}

long long inv(long long a) {
	return powmod(a, P - 2);
}

long long t[4 * maxN], add[4 * maxN];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = 0;
		add[i] = 1;
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = 0;
	add[i] = 1;
}

void setvalue(int i, int l, int r, int k, long long value) {
	if (l == r) {
		t[i] = (add[i] * value) % P;
		return;
	}

	add[2 * i] = (add[2 * i] * add[i]) % P;
	t[2 * i] = (t[2 * i] * add[i]) % P;
	add[2 * i + 1] = (add[2 * i + 1] * add[i]) % P;
	t[2 * i + 1] = (t[2 * i + 1] * add[i]) % P;
	add[i] = 1;
	if (k > (l + r) / 2) {
		setvalue(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		setvalue(2 * i, l, (l + r) / 2, k, value);
	}
	t[i] = (t[2 * i] + t[2 * i + 1]) % P;
	t[i] = (t[i] * add[i]) % P;
}

void update(int i, int l, int r, int cl, int cr, long long value) {
	if (l == cl && r == cr) {
		t[i] = (t[i] * value) % P;
		add[i] = (add[i] * value) % P;
		return ;
	}
	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}
	t[i] = (t[2 * i] + t[2 * i + 1]) % P;
	t[i] = (t[i] * add[i]) % P;
}

long long get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return (get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr) * add[i]) % P;
	}
	if (cr <= (l + r) / 2) {
		return (get(2 * i, l, (l + r) / 2, cl, cr) * add[i]) % P;
	}
	long long a = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	long long b = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return ((a + b) * add[i]) % P;
}

int order[maxN];
int l[maxN], r[maxN], m;
long long cnt[maxN];

void dfs(int v) {
	l[v] = m;
	order[m++] = v;
	for (int i = 0; i < g[v].size(); ++i) {
		dfs(g[v][i]);
	}
	r[v] = m - 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &v[0], &q);
	n = 1;
	for (int i = 0; i < q; ++i) {
		scanf("%d", &mode[i]);
		if (mode[i] == 1) {
			scanf("%d%d", &p[i], &v[n]);
			--p[i];
			g[p[i]].push_back(n);
			++n;
		} else {
			scanf("%d", &p[i]);
			--p[i];
		}
	}

	dfs(0);

	build(1, 0, n - 1);
	setvalue(1, 0, n - 1, l[0], v[0]);
	cnt[0] = 1;

	int nn = 1;
	for (int i = 0; i < q; ++i) {
		if (mode[i] == 1) {
			update(1, 0, n - 1, l[p[i]], r[p[i]], (inv(cnt[p[i]]) * (cnt[p[i]] + 1)) % P);
			++cnt[p[i]];
			setvalue(1, 0, n - 1, l[nn], v[nn]);
			cnt[nn] = 1;
			++nn;
		} else {
			long long res = get(1, 0, n - 1, l[p[i]], r[p[i]]);
			res *= inv(get(1, 0, n - 1, l[p[i]], l[p[i]]));
			res %= P;
			res *= cnt[p[i]];
			res %= P;
			res *= v[p[i]];
			res %= P;
			printf("%d\n", (int)(res));
		}
	}


	return 0;
}