#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	long long n, a, b, summ = 0;
	cin >> n >> a >> b;
	vector<vector<long long>>arr(n, vector<long long>(2));
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		summ += arr[i][1];
	}
	vector<vector<int>>arr2(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		arr2[i][0] = max((long long)0, arr[i][0] - arr[i][1]);
		arr2[i][1] = i;
	}
	vector<int>s(n);
	for (int i = 0; i < n; i++) {
		s[i] = max((long long)0, arr[i][0] - arr[i][1]);
	}
	sort(arr2.begin(), arr2.end());
	long long mn = 0;
	if (b > 0) {
		for (int i = n - 1; i > n - 1 - (min(b - 1, n)); i--) {
			mn += arr2[i][0];
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long x = arr[i][0], y = arr[i][1];
		for (int j = 0; j < a; j++) {
			x *= 2;
		}
		long long cnt = 0;
		if (b > 0) {
			cnt += x - y;

			cnt += mn;
			if (b - 1 < n) {
				if (s[i] > arr2[n - 1 - (min(b - 1, n))][0]) {
					cnt += arr2[n - 1 - (min(b - 1, n))][0];
					cnt -= s[i];
				}
			}
			else {
				cnt -= s[i];
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans + summ;
	return 0;
}