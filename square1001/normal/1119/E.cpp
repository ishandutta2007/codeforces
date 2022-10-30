#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long sum = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		long long delta = min(sum / 3, a[i] / 2);
		sum -= delta * 3;
		ans += delta;
	}
	cout << ans << endl;
	return 0;
}