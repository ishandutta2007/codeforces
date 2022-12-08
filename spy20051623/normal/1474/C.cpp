#include <bits/stdc++.h>
using namespace std;
int a[2005];
int b[1005][2];
int h[1000005];
int h1[1000005];

main() {
	int t, n, i, cnt, in, flag, p, q;
	cin >> t;
	while (t--) {
		memset(h1, 0, sizeof(h1));
		cin >> n;
		cnt = 0;
		for (i = 0; i < 2 * n; ++i) {
			cin >> in;
			if (h1[in] == 0) {
				a[cnt] = in;
				++h1[in];
				++cnt;
			} else ++h1[in];
		}
		sort(a, a + cnt);
		b[0][0] = a[cnt - 1];
		--h1[a[cnt - 1]];
		for (q = 0; q < cnt; ++q) {
			memset(h, 0, sizeof(h));
			for (int tt = 0; tt < cnt; ++tt)
				h[a[tt]] = h1[a[tt]];
			if (h[a[q]]) {
				--h[a[q]];
				b[0][1] = a[q];
				flag = 0;
				i = cnt - 1;
				p = 1;
				if (n == 1)
					flag = 1;
				while (p < n) {
					if (h[a[i]] == 0)
						--i;
					else {
						b[p][0] = a[i];
						--h[a[i]];
						if (h[b[p - 1][0] - a[i]] == 0) {
							flag = 0;
							break;
						} else {
							b[p][1] = b[p - 1][0] - a[i];
							--h[b[p - 1][0] - a[i]];
							++p;
							flag = 1;
						}
					}
				}
			}
			if (flag)
				break;
		}
		if (!flag)
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			cout << b[0][0] + b[0][1] << endl;
			for (i = 0; i < n; ++i)
				cout << b[i][0] << " " << b[i][1] << endl;
		}
	}
}