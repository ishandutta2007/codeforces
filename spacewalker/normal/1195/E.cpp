#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 3000;
int arr[NMAX][NMAX], sliderow[NMAX][NMAX];

int main() {
	int n, m, a, b; scanf("%d %d %d %d", &n, &m, &a, &b);
	ll g0, x, y, z; scanf("%lld %lld %lld %lld", &g0, &x, &y, &z);
	ll cterm = g0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			arr[i][j] = cterm;
			cterm = (cterm * x + y) % z;
		}
	}
	for (int i = 0; i < n; ++i) {
		deque<int> sids;
		for (int j = 0; j < b; ++j) {
			while (!sids.empty() && arr[i][sids.back()] > arr[i][j]) {
				sids.pop_back();
			}
			sids.push_back(j);
		}
		sliderow[i][0] = arr[i][sids.front()];
		for (int j = b; j < m; ++j) {
			if (sids.front() == j - b) sids.pop_front();
			while (!sids.empty() && arr[i][sids.back()] > arr[i][j]) {
				sids.pop_back();
			}
			sids.push_back(j);
			sliderow[i][j - b + 1] = arr[i][sids.front()];
		}
	}
	ll ans = 0;
	for (int j = 0; j + b <= m; ++j) {
		deque<int> sids;
		for (int i = 0; i < a; ++i) {
			while (!sids.empty() && sliderow[sids.back()][j] > sliderow[i][j]) {
				sids.pop_back();
			}
			sids.push_back(i);
		}
		ans += sliderow[sids.front()][j];
		for (int i = a; i < n; ++i) {
			if (sids.front() == i - a) sids.pop_front();
			while (!sids.empty() && sliderow[sids.back()][j] > sliderow[i][j]) {
				sids.pop_back();
			}
			sids.push_back(i);
			ans += sliderow[sids.front()][j];
		}
	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j + b - 1 < m; ++j) {
//			printf("%d ", sliderow[i][j]);
//		}
//		printf("\n");
//	}
	printf("%lld\n", ans);
	return 0;
}