#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		int n;
		long long k;
		cin >> n >> k;
		vector<long long> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		a.push_back(1e15);
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
		}
		
		vector<int> maxs(n + 1, 0);
		int l = n - 1;
		int r = n - 1;
		for (; l >= 0; --l) {
			while (a[l] + k < a[r]) {
				--r;
			}
			maxs[l] = max(r - l + 1, maxs[l + 1]);
		}
		
		int res = 0;
		l = 0;
		r = 1;
		for (; l < n; ++l) {
			while (a[l] + k >= a[r]) {
				++r;
			}
			res = max(res, r - l + maxs[r]);
		}
		cout << res << '\n';
		
	}
	return 0;
}