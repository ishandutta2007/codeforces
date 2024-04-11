#include <bits/stdc++.h>
using namespace std;
int d[200005];
int n;

int lowbit(int x) {
	return x & (-x);
}

void update(int x, int k) {
	if (x < 1)
		x = 1;
	for (int i = x; i <= n; i += lowbit(i))
		d[i] += k;
}

long long sum(int x) {
	long long res = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		res += d[i];
	return res;
}

int main() {
//	freopen("in.txt", "r", stdin);
	long long t, i, o, p;
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 1; i <= n; ++i) {
			cin >> o;
			if (o > 0) {
				update(i + 1 - o, 1);
				update(i + 1, -1);
			}
		}
		for (i = 1; i <= n; ++i) {
			p = sum(i);
			cout << (p > 0) << ' ';
		}
		cout << endl;
		memset(d, 0, sizeof(int) * (n + 5));
	}
	return 0;
}