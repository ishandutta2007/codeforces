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
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
mt19937 rnd(time(nullptr));
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define firn(i, n) for (int i = 1; i < (int)n; i++)
#define all(v) v.begin(), v.end()
#define int long long
const int mod = 1e9 + 7;

signed main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	forn(q, t) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int>a(n), b(m), c(k);
		forn(i, n) {
			cin >> a[i];
		}
		forn(i, m) {
			cin >> b[i];
		}
		forn(i, k) {
			cin >> c[i];
		}
		sort(all(a));
		sort(all(b));
		sort(all(c));
		int ans = 2e18;
		forn(i, n) {
			int l = 0;
			int r = m - 1;
			while (r - l > 1) {
				int mm = (r + l) / 2;
				if (b[mm] >= a[i]) {
					r = mm;
				}
				else {
					l = mm;
				}
			}
			int l1 = 0, r1 = k - 1;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] >= min(a[i], b[l])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			ans = min(ans, (a[i] - b[l]) * (a[i] - b[l]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[l]) * (c[r1] - b[l]));
			l1 = 0;
			r1 = k;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] > max(a[i], b[l])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			r1--;
			ans = min(ans, (a[i] - b[l]) * (a[i] - b[l]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[l]) * (c[r1] - b[l]));
			l1 = 0; r1 = k - 1;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] >= min(a[i], b[r])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			ans = min(ans, (a[i] - b[r]) * (a[i] - b[r]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[r]) * (c[r1] - b[r]));
			l1 = 0;
			r1 = k;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] > max(a[i], b[r])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			r1--;
			ans = min(ans, (a[i] - b[r]) * (a[i] - b[r]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[r]) * (c[r1] - b[r]));
		}
		swap(a, b);
		swap(n, m);
		forn(i, n) {
			int l = 0;
			int r = m - 1;
			while (r - l > 1) {
				int mm = (r + l) / 2;
				if (b[mm] >= a[i]) {
					r = mm;
				}
				else {
					l = mm;
				}
			}
			int l1 = 0, r1 = k - 1;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] >= min(a[i], b[l])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			ans = min(ans, (a[i] - b[l]) * (a[i] - b[l]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[l]) * (c[r1] - b[l]));
			l1 = 0;
			r1 = k;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] > max(a[i], b[l])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			r1--;
			ans = min(ans, (a[i] - b[l]) * (a[i] - b[l]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[l]) * (c[r1] - b[l]));
			l1 = 0; r1 = k - 1;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] >= min(a[i], b[r])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			ans = min(ans, (a[i] - b[r]) * (a[i] - b[r]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[r]) * (c[r1] - b[r]));
			l1 = 0;
			r1 = k;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] > max(a[i], b[r])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			r1--;
			ans = min(ans, (a[i] - b[r]) * (a[i] - b[r]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[r]) * (c[r1] - b[r]));
		}
		swap(a, c);
		swap(n, k);
		forn(i, n) {
			int l = 0;
			int r = m - 1;
			while (r - l > 1) {
				int mm = (r + l) / 2;
				if (b[mm] >= a[i]) {
					r = mm;
				}
				else {
					l = mm;
				}
			}
			int l1 = 0, r1 = k - 1;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] >= min(a[i], b[l])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			ans = min(ans, (a[i] - b[l]) * (a[i] - b[l]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[l]) * (c[r1] - b[l]));
			l1 = 0;
			r1 = k;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] > max(a[i], b[l])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			r1--;
			ans = min(ans, (a[i] - b[l]) * (a[i] - b[l]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[l]) * (c[r1] - b[l]));
			l1 = 0; r1 = k - 1;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] >= min(a[i], b[r])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			ans = min(ans, (a[i] - b[r]) * (a[i] - b[r]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[r]) * (c[r1] - b[r]));
			l1 = 0;
			r1 = k;
			while (r1 - l1 > 1) {
				int mm = (r1 + l1) / 2;
				if (c[mm] > max(a[i], b[r])) {
					r1 = mm;
				}
				else {
					l1 = mm;
				}
			}
			r1--;
			ans = min(ans, (a[i] - b[r]) * (a[i] - b[r]) + (a[i] - c[r1]) * (a[i] - c[r1]) + (c[r1] - b[r]) * (c[r1] - b[r]));
		}
		cout << ans << '\n';
	}

	
	return 0;
}