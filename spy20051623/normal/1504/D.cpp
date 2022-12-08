#include <bits/stdc++.h>
using namespace std;

struct pt {
	int x, y;
};

void pr(int c, int x, int y) {
	cout << c << ' ' << x << ' ' << y << endl;
	fflush(stdout);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, i, j, k, l;
	vector<pt> a, b;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if ((i + j) % 2 == 0)
				a.push_back({i, j});
			else
				b.push_back({i, j});
		}
	}
	j = k = 0;
	for (i = 0; i < n * n; ++i) {
		cin >> l;
		if (l == 1) {
			if (k < b.size()) {
				pr(2, b[k].x, b[k].y);
				++k;
			} else {
				pr(3, a[j].x, a[j].y);
				++j;
			}
		} else if (l == 2) {
			if (j < a.size()) {
				pr(1, a[j].x, a[j].y);
				++j;
			} else {
				pr(3, b[k].x, b[k].y);
				++k;
			}
		} else {
			if (j < a.size()) {
				pr(1, a[j].x, a[j].y);
				++j;
			} else {
				pr(2, b[k].x, b[k].y);
				++k;
			}
		}
	}
	return 0;
}