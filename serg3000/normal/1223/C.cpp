#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#define int long long
signed main() {
	int q;
	cin >> q;
	for (int w = 0; w < q; w++) {
		int n;
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] *= -1;
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			a[i] *= -1;
		}
		int x, c, y, d, k;
		cin >> x >> c >> y >> d >> k;
		int l = 0;
		int r = n + 1;
		while (r - l > 1) {
			int cnt1 = 0, cnt2 = 0, cnt3 = 0;
			int m = (r + l) / 2;
			for (int i = 0; i < m; i++) {
				if ((i + 1) % c == 0 && (i + 1) % d == 0) {
					cnt3++;
				}
				else {
					if ((i + 1) % c == 0) {
						cnt1++;
					}
					else {
						if ((i + 1) % d == 0) {
							cnt2++;
						}
					}
				}
			}
			int ans = 0;
			for (int i = 0; i < cnt3; i++) {
				ans += a[i] / 100 * (x + y);
			}
			if (x > y) {
				for (int i = cnt3; i < cnt3 + cnt1; i++) {
					ans += a[i] / 100 * x;
				}
				for (int i = cnt3 + cnt1; i < cnt3 + cnt1 + cnt2; i++) {
					ans += a[i] / 100 * y;
				}
			}
			else {
				for (int i = cnt3; i < cnt3 + cnt2; i++) {
					ans += a[i] / 100 * y;
				}
				for (int i = cnt3 + cnt2; i < cnt3 + cnt1 + cnt2; i++) {
					ans += a[i] / 100 * x;
				}
			}
			if (ans < k) {
				l = m;
			}
			else {
				r = m;
			}
		}
		if (l != n) {
			cout << r << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

	return 0;
}