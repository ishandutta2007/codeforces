#include <bits/stdc++.h>
using namespace std;
int a[200005];
int res[200005];
int h[200005];

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, cnt, i, j, k, minm;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(res, 0, sizeof(int) * (n + 5));
		memset(h, 0, sizeof(int) * (n + 5));
		cnt = 1;
		cin >> a[0];
		h[a[0]] = 1;
		for (i = 1; i < n; ++i) {
			cin >> j;
			h[j] = 1;
			if (j != a[cnt - 1]) {
				a[cnt++] = j;
				++res[j];
			}
		}
		--res[a[cnt - 1]];
		minm = 0x3f3f3f3f;
		for (i = 1; i <= n; ++i) {
			if (h[i])
				minm = min(minm, res[i]);
		}
		cout << minm + 1 << endl;
	}
	return 0;
}