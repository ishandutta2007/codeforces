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
	int n, q;
	cin >> n >> q;
	vector<int>a(n);
	vector<pair<int, int>>zap(q);
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		for (int j = x; j <= y; j++) {
			a[j]++;
		}
		zap[i] = { x, y };
	}
	vector<int>pref(n);
	if (a[0] == 1) {
		pref[0] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == 1) {
			pref[i] = pref[i - 1] + 1;
		}
		else {
			pref[i] = pref[i - 1];

		}
	}
	vector<int>pref2(n);
	if (a[0] == 2) {
		pref2[0] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (a[i] == 2) {
			pref2[i] = pref2[i - 1] + 1;
		}
		else {
			pref2[i] = pref2[i - 1];

		}
	}
	int colvo = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			colvo++;
		}
	}
	int ans = 0;
	for (int i = 0; i < q; i++) {
		for (int j = i + 1; j < q; j++) {
			int c = colvo;
			c -= pref[zap[i].second];
			c -= pref[zap[j].second];
			if (zap[i].first != 0) {
				c += pref[zap[i].first - 1];
			}
			if (zap[j].first != 0) {
				c += pref[zap[j].first - 1];
			}
			int l = max(zap[i].first, zap[j].first);
			int r = min(zap[i].second, zap[j].second);
			if (r >= l) {
				c -= pref2[r];
				if (l != 0) {
					c += pref2[l - 1];
				}
			}
			ans = max(ans, c);
		}
	}
	cout << ans;
	return 0;
}