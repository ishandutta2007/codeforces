#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<long long> a(n * k);
		for (int i = 0; i < n * k; ++i) {
			cin >> a[i];
		}
		int x = n - ceil((double)(n) / 2) + 1;
		long long res = 0;
		for (int i = (n - x) * k; i < k * n; i += x) {
			res += a[i];
		}
		cout << res << "\n";
	}
	return 0;
}