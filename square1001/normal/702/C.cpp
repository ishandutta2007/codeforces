#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
int n, m, imos[100009]; ll a[100009], b[100009];
bool solve(ll x) {
	fill(imos, imos + n + 2, 0);
	for (int i = 0; i < m; i++) {
		int ptl = lower_bound(a, a + n, b[i] - x) - a;
		int ptr = lower_bound(a, a + n, b[i] + x + 1) - a;
		imos[ptl]++;
		imos[ptr]--;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += imos[i];
		if (sum <= 0) return false;
	}
	return true;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (int i = 0; i < m; i++) scanf("%lld", &b[i]);
	ll l = 0, r = 1LL << 31;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (solve(mid)) r = mid;
		else l = mid;
	}
	while (solve(r - 1)) r--;
	cout << r << endl;
	return 0;
}