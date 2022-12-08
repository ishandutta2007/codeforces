#include <bits/stdc++.h>
using namespace std;
int a[10000];

long long b[10000];

int n;

int lowbit(int x) {
	return x & (-x);
}

void update(int x, int k) {
	for (int i = x; i <= n; i += lowbit(i))
		b[i] += k;
}

long long getsum(int x) {
	long long res = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		res += b[i];
	return res;
}

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, i, j, k, sum, bb;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		sum = 0;
		memset(b, 0, sizeof(b));
		i = 1;
		while (a[i] == 1)
			++i;
		for (i; i <= n; ++i) {
			bb = getsum(i);
			if (a[i] - 1 > bb)
				sum += a[i] - bb - 1;
			update(i + 2, 1);
			if (i + a[i] <= n)
				update(i + a[i] + 1, -1);
			else
				update(n + 1, -1);
			if (bb >= a[i]) {
				update(i + 1, bb - a[i] + 1);
				update(i + 2, a[i] - 1 - bb);
			}
		}
		cout << sum << endl;
	}
	return 0;
}