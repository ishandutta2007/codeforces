#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

template<typename t> void wt(t x) {
	if (x >= 10) wt(x / 10);
	putchar(x % 10 + 48);
}
#define mk make_pair
#define X first
#define Y second
typedef pair <long long, int> pli;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
const int sz = 333;
struct data {
	int a, b;
	bool operator < (const data &x) const {
		return b < x.b;
	}
} b[N];
int num, tot, n, w, A, B;

struct block {
	long long s, t, c, mxp, mx, up, a[sz + 1];
	void rebuild() {
		for (int i = s; i <= t; i ++) a[i - s + 1] += 1ll * i * c;
		c = mxp = mx = 0;
		for (int i = s; i <= t; i ++) if (a[i - s + 1] > mx) mx = a[i - s + 1], mxp = i;
		up = inf;
		for (int i = mxp + 1; i <= t; i ++) up = min(up, (mx - a[i - s + 1]) / (i - mxp) + 1);
	}
}p[1000];

void insert(data a) {
	int x = a.a, i; ++ num;
	for (i = 1; i <= tot && p[i].t < x; i ++) {
		p[i].c ++;
		if ((--p[i].up) <= 0) p[i].rebuild();
		else p[i].mx += p[i].mxp;
	}
	if (i <= tot) {
		for (int j = p[i].s; j <= x; j ++) p[i].a[j - p[i].s + 1] += j;
		p[i].rebuild();
	}
}

pli query() {
	pli re = mk(0, 0);
	for (int i = 1; i <= tot; i ++) if (p[i].mx > re.X) re = mk(p[i].mx, p[i].mxp);
	return re;
}

int main() {
	n = rd(), w = rd();
	for (int i = 1; i <= n; i ++) b[i].a = rd(), b[i].b = rd();
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i ++) B = max(B, b[i].b);
	for (int i = 1; i <= n; i ++) A = max(A, b[i].a);
	int j = 1;
	for (int i = 1; i <= A; i ++) {
		p[i].s = j, p[i].t = min(A, j + sz - 1);
		p[i].mx = 0, p[i].mxp = j, p[i].up = 0, j += sz;
		if (p[i].t == A) tot = i, i = A;
	}
	j = 1;
	for (int i = 0; i < B + 2; i ++) {
		for (; j <= n && b[j].b < i; j ++) insert(b[j]);
		pli ans = query();
		wt(ans.X + 1ll * w * (n - num) * i), putchar(32), wt(ans.Y), putchar(10);
	}
	return 0;
}