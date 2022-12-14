#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

void write(int x) {
	if (x < 0) putchar('-'), write(-x);
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 1 << 20;

int n, pre;

struct tree {
	int length[4]; // 0: left 1: right 2: length of segment 3: ans
	long long val[3]; // 0: left 1: right

	tree () {
		memset(length, 0, sizeof length);
		memset(val, 0, sizeof val);
	}

	void update(long long v) {
		val[2] += v;
		val[0] = val[1] = (val[2] > 0) - (val[2] < 0);
		length[0] = length[1] = length[2] = (bool) val[2];
		length[3] = 1;
	}

	void merge(const tree &a, const tree &b) {
		val[0] = a.val[0];
		val[1] = b.val[1];
		length[0] = a.length[0];
		length[1] = b.length[1];
		length[2] = a.length[2] + b.length[2];
		length[3] = max(a.length[3], b.length[3]);
		if (a.val[1] >= b.val[0] && a.val[1] && b.val[0]) {
			length[3] = max(length[3], a.length[1] + b.length[0]);
			if (length[0] == a.length[2]) length[0] += b.length[0];
			if (length[1] == b.length[2]) length[1] += a.length[1];
		}
	}

} t[maxn << 2];


void insert(int k, int v) {
	k += maxn;
	t[k].update(v);
	for (; k >>= 1;) t[k].merge(t[k << 1], t[k << 1 | 1]);
}

int main() {
	n = read();
	for (int i = 1, x; i <= n; i ++) {
		if (i == 1) pre = read();
		else x = read(), insert(i - 1, x - pre), pre = x;
	}
	for (int m = read(), l, r, d; m; m --) {
		l = read(), r = read(), d = read();
		if (l > 1) insert(l - 1, d);
		if (r < n) insert(r, -d);
		write(t[1].length[3] + 1), puts("");
	}
	return 0;
}