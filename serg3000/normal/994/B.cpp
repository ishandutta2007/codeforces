#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define int long long
signed main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>>a(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cin >> a[i][0];
		a[i][2] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i][1];
	}
	vector<int>b(k);
	vector<int>ans(n);
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		long long s = 0;
		for (int j = 0; j < k; j++) {
			s += b[j];
		}
		s += a[i][1];
		ans[i] = s;
		if (k > 0) {
			if (a[i][1] > b[0]) {
				b[0] = a[i][1];
				sort(b.begin(), b.end());
			}
		}

	}
	vector<int>ans2(n);
	for (int i = 0; i < n; i++) {
		ans2[a[i][2]] = ans[i];
	}
	for (int i = 0; i < n; i++) {
		cout << ans2[i] << " ";
	}
	return 0;
}