#include <bits/stdc++.h>
using namespace std;
int r[70000];

int ask(int m, int a, int b) {
	int res;
	if (m == 0)
		cout << "OR";
	else if (m == 1)
		cout << "AND";
	else
		cout << "XOR";
	cout << ' ' << a << ' ' << b << endl;
	cin >> res;
	return res;
}

struct dt {
	int id;
	int x;
} d[70000];

int cmp1(dt x, dt y) {
	return x.x < y.x;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, i, j, k, res;
	cin >> n;
	d[1].id = 1;
	for (i = 2; i <= n; ++i) {
		d[i].id = i;
		d[i].x = ask(2, 1, i);
	}
	sort(d + 2, d + n + 1, cmp1);
	for (i = 1; i < n; ++i) {
		if (d[i].x == d[i + 1].x)
			break;
	}
	if (i < n) {
		j = ask(1, d[i].id, d[i + 1].id);
		r[1] = j ^ d[i].x;
		for (k = 2; k <= n; ++k)
			r[d[k].id] = r[1] ^ d[k].x;
	} else {
		j = ask(1, 1, d[2].id);
		res = 0;
		for (k = 0; (1 << k) < n; ++k) {
			if ((j & (1 << k)) == 0)
				continue;
			res |= 1 << k;
		}
		for (i = 3; i <= n; ++i) {
			if ((d[2].x & d[i].x) == 0)
				break;
		}
		j = ask(1, 1, d[i].id);
		for (k = 0; (1 << k) < n; ++k) {
			if ((j & (1 << k)) == 0)
				continue;
			res |= 1 << k;
		}
		r[1] = res;
		for (k = 2; k <= n; ++k)
			r[d[k].id] = r[1] ^ d[k].x;
	}
	cout << '!';
	for (i = 1; i <= n; ++i) {
		cout << ' ' << r[i];
	}
	cout << endl;
	return 0;
}