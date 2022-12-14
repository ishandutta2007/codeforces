#include <bits/stdc++.h>
using namespace std;

#define N 101010
const int K = 500;

int a[N], b[N], n, m;

struct data {
	int st, en, mov, d;
	data(int st = 0, int en = 0, int mov = 0, int d = 0) : st(st), en(en), mov(mov), d(d) {}
	bool operator < (const data &B) const {return st < B.st;}
};

data D[K+2];

int x, y;

struct data_set {
	int e, dmn;
	vector <int> en, mov, d;
	void init(int sz) {
		e = sz;
		en.resize(e + 1);
		mov.resize(e + 1);
		d.resize(e + 1);
	}

	bool check() {
		if (en[e] < x || dmn > y) return 0;
		int i = lower_bound(en.begin() + 1, en.begin() + e + 1, x) - en.begin();
		if (d[i] > y) return 0;
		y -= d[i];
		x += mov[i];
		return 1;
	}

	void refresh() {
		dmn = d[1];
		for (int i = 2; i <= e; i ++) dmn = min(dmn, d[i]);
	}
} S[N/K];

inline int nanugi(int a, int b) {
	return (a + b - 1) / b;
}

void prep() {
	for (int i = K; i < n; i += K) {
		int st = b[i], en = b[i] + i - 2;
		int e = 0;
		D[++e] = data(st, en, 0, 0);
		for (int j = i + 1, k, h; j <= min(i + K, n); j ++) {
			int jj = j - 1;
			for (int f = 1; f <= e; f ++) {
				k = nanugi(b[j] - D[f].st - D[f].mov, jj);
				h = nanugi(b[j] - D[f].en - D[f].mov, jj);
				if (k == h) {
					D[f].mov += k * jj;
					D[f].d += k;
				}
				else {
					int mid = b[j] - h * jj;
					D[++e] = data(D[f].st, -D[f].mov + mid - 1, D[f].mov + k * jj, D[f].d + k);
					D[f] = data(-D[f].mov + mid, D[f].en, D[f].mov + h * jj, D[f].d + h);
				}
			}
		}
		sort(D + 1, D + e + 1);
		int id = i / K;
		S[id].init(e);
		for (int j = 1; j <= e; j ++) {
			S[id].en[j] = D[j].en;
			S[id].mov[j] = D[j].mov;
			S[id].d[j] = D[j].d;
		}
		S[id].refresh();
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) b[i] = a[i] - i + 1;
	prep();
	while (m --) {
		scanf("%d %d", &x, &y);
		if (x < b[1]) {
			printf("%d\n", x);
			continue;
		}
		int cur = lower_bound(b + 1, b + n + 1, x + 1) - b - 1;
		int d;
		while (1) {
			if (!y || cur == n) {
				long long tmp = x + 1ll * y * n;
				printf("%I64d\n", tmp);
				break;
			}
			if (cur % K == 0) {
				if (S[cur/K].check()) {
					cur = min(cur + K, n);
					continue;
				}
			}
			d = min(y, nanugi(b[cur+1] - x, cur));
			y -= d, x += d * cur;
			cur ++;
		}
	}

	return 0;
}