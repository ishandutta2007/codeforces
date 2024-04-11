#include <bits/stdc++.h>
using namespace std;

struct pt {
	int x, y;
} p[200005];

int cmp(pt a, pt b) {
	return a.x < b.x;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, j, k, sum;
	p[0] = {1, 1};//(1,1)
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> p[i].x;
		}
		for (i = 1; i <= n; ++i) {
			cin >> p[i].y;
		}
		sort(p + 1, p + n + 1, cmp);//
		sum = 0;
		for (i = 1; i <= n; ++i) {
			j = p[i - 1].x - p[i - 1].y;//r1-c1
			k = p[i].x - p[i].y;//r2-c2
			if (j == k) {
				if (j % 2 == 0)//0
					sum += p[i].x - p[i - 1].x;
			} else {
				if (j % 2 == 0 && k % 2 != 0)//
					sum += (k - j) / 2;
				else
					sum += (k - j + 1) / 2;
			}
		}
		cout << sum << endl;
	}
	return 0;
}