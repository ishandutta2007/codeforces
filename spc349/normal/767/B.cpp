#include <bits/stdc++.h>
using namespace std;

long long a[100000];

int main() {
	long long L, R, D; cin >> L >> R >> D;
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	long long minj = 1000000000000000000, ans = 0, cur = L;
	for (int i = 0; i < n; i++) {
		if (cur > R) break;
		if (a[i]) {
			if (cur < a[i]) {
				ans = cur;
				break;
			}
			if (cur - a[i] + 1 < minj) minj = cur - a[i] + 1, ans = a[i] - 1;
		}
		cur = max(cur, a[i]) + D;
	}
	if (cur + D <= R) ans = cur;
	cout << ans << endl;
	return 0;
}