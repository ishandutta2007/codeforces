#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
int n, m;
char s[maxN];

int p[4 * maxN], q[4 * maxN], a[4 * maxN], b[4 * maxN];
int rev[4 * maxN];

struct Q {
	int p, q, a, b;
	Q() {
	}
	Q(int p, int q, int a, int b) : p(p), q(q), a(a), b(b) {
	}
};

void push(int i, int l, int r) {
	if (rev[i] && l != r) {
		swap(a[2 * i], b[2 * i]);
		swap(p[2 * i], q[2 * i]);
		rev[2 * i] ^= 1;
		
		swap(a[2 * i + 1], b[2 * i + 1]);
		swap(p[2 * i + 1], q[2 * i + 1]);
		rev[2 * i + 1] ^= 1;
		rev[i] ^= 1;
	}
}

Q get(int i, int l, int r, int cl, int cr) {
	push(i, l, r);
	if (l == cl && r == cr) {
		return Q(p[i], q[i], a[i], b[i]);
	}

	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}

	Q x = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	Q y = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);

	Q res;
	res.p = max(x.p + y.b, x.a + y.p);
	res.q = max(x.b + y.q, x.q + y.a);
	res.a = x.a + y.a;
	res.b = x.b + y.b;
	return res;
}

void update(int i, int l, int r, int cl, int cr) {
	push(i, l, r);
	if (l == cl && r == cr) {
		rev[i] ^= 1;
		swap(p[i], q[i]);
		swap(a[i], b[i]);
		return ;
	}

	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	}

	Q x = Q(p[2 * i], q[2 * i], a[2 * i], b[2 * i]);
	Q y = Q(p[2 * i + 1], q[2 * i + 1], a[2 * i + 1], b[2 * i + 1]);
	Q res;
	res.p = max(x.p + y.b, x.a + y.p);
	res.q = max(x.b + y.q, x.q + y.a);
	res.a = x.a + y.a;
	res.b = x.b + y.b;
	p[i] = res.p;
	q[i] = res.q;
	a[i] = res.a;
	b[i] = res.b;
}

void build(int i, int l, int r) {
	if (l == r) {
		p[i] = 1;
		q[i] = 1;
		a[i] = (s[l] == '4');
		b[i] = (s[l] == '7');
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);

	Q x = Q(p[2 * i], q[2 * i], a[2 * i], b[2 * i]);
	Q y = Q(p[2 * i + 1], q[2 * i + 1], a[2 * i + 1], b[2 * i + 1]);
	Q res;
	res.p = max(x.p + y.b, x.a + y.p);
	res.q = max(x.b + y.q, x.q + y.a);
	res.a = x.a + y.a;
	res.b = x.b + y.b;
	p[i] = res.p;
	q[i] = res.q;
	a[i] = res.a;
	b[i] = res.b;
}

char f[10];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	scanf("%s", &s);
	build(1, 0, n - 1);

	for (int i = 1; i <= m; ++i) {
		scanf("%s", &f);
		if (f[0] == 'c') {
			printf("%d\n", get(1, 0, n - 1, 0, n - 1));
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			update(1, 0, n - 1, l - 1, r - 1);
		}
	}


	return 0;
}