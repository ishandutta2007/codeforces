#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		if(i == 0) ans += a[i] * (n - a[i] + 1);
		else if (i == n) ans += a[i - 1] * (n - a[i - 1] + 1);
		else {
			long long l = min(a[i], a[i - 1]), r = max(a[i], a[i - 1]);
			ans += l * (r - l);
			ans += (n - r + 1) * (r - l);
		}
	}
	cout << ans / 2 << endl;
	return 0;
}