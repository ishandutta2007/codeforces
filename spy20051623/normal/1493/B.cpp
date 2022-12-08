#include <bits/stdc++.h>
using namespace std;

int ok[10] = {0, 1, 2, 5, 8};
map<int, int> mp;
int H, M;

struct t {
	int d[4];
	int hh, mm;
	void in(int h, int m) {
		hh = h;
		mm = m;
		d[0] = h / 10;
		d[1] = h % 10;
		d[2] = m / 10;
		d[3] = m % 10;
	}
	void print() {
		cout << d[0] << d[1] << ':' << d[2] << d[3] << endl;
	}
};

bool op(t x, t &y) {
	int i;
	if (x.mm >= M || x.hh >= H)
		return false;
	for (i = 0; i < 4; ++i) {
		if (x.d[i] == 3 || x.d[i] == 4 || x.d[i] == 6 || x.d[i] == 7 || x.d[i] == 9)
			return false;
		y.d[3 - i] = mp[x.d[i]];
	}
	y.hh = y.d[0] * 10 + y.d[1];
	y.mm = y.d[2] * 10 + y.d[3];
	if (y.hh >= H || y.mm >= M)
		return false;
	return true;
}

int de(t x, t y) {
	int res = (x.hh - y.hh) * M + x.mm - y.mm;
	if (res < 0)
		res += H * M;
	return res;
}

int main() {
//	freopen("in.txt", "r", stdin);
	mp[0] = 0;
	mp[1] = 1;
	mp[2] = 5;
	mp[5] = 2;
	mp[8] = 8;
	int T, h, m, i, j, k, l, bestd, r;
	t x, y, best, st;
	cin >> T;
	while (T--) {
		cin >> H >> M;
		bestd = 0x3f3f3f3f;
		scanf("%d:%d", &h, &m);
		st.in(h, m);
		for (i = 0; i < 5; ++i)
			for (j = 0; j < 5; ++j)
				for (k = 0; k < 5; ++k)
					for (l = 0; l < 5; ++l) {
						x.in(10 * ok[i] + ok[j], 10 * ok[k] + ok[l]);
						if (op(x, y)) {
							r = de(y, st);
							if (r < bestd) {
								bestd = r;
								best = y;
							}
						}
					}
		best.print();
	}
	return 0;
}