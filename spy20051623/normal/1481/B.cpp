#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, k, h[105], i, s, e, d, r;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		memset(h, 0, sizeof(h));
		for (i = 1; i <= n; ++i) {
			cin >> h[i];
		}
		h[0] = h[n + 1] = 0x7fffffff;
		r = -1;
		while (1) {
			for (e = 1; h[e] >= h[e + 1]; ++e);
			for (s = e; h[s] == h[s - 1]; --s);
			if (e == n)
				break;
			d = min(h[s - 1] - h[s], h[e + 1] - h[e]);
			if (k > d * (e - s + 1)) {
				k -= d * (e - s + 1);
				for (i = s; i <= e; ++i)
					h[i] += d;
			} else {
				k = (k - 1) % (e - s + 1) + 1;
				r = e + 1 - k;
				break;
			}
		}
		cout << r << endl;
	}
	return 0;
}