#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GGC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define int long long
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int l = -1;
	int r = 1e18;
	while (r - l > 1) {
		int m = (r + l) / 2;
		vector<int>c(k);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int t = 0;
			int y = (a[i] + b[i]) / b[i];
			t += y;
			if (t >= k) {
				continue;
			}
			c[t]++;
			cnt++;
			int x = a[i] - b[i] * y + m;
			while (cnt < k + 10 && t < k) {
				y = (x + b[i]) / b[i];
				t += y;
				if (t < k) {
					c[t]++;
					cnt++;
					x += m - y * b[i];
				}
			}
		}
		int f = 0;
		int col = 0;
		for (int i = 0; i < k; i++) {
			col += c[i];
			if (col > i) {
				f = 1;
			}
		}
		if (cnt > k + 1) {
			f = 1;
		}
		if (f == 1) {
			l = m;
		}
		else {
			r = m;
		}
	}
	if (r == 1e18) {
		cout << -1;
	}
	else {
		cout << r;
	}
	return 0;
}