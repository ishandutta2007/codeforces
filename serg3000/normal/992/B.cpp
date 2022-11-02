#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define int long long
signed main() {
	int l, r, x, y;
	cin >> l >> r >> x >> y;
	vector<int>ans1;
	vector<int>ans2;
	for (int i = x; i <= sqrt(x * y); i+=x) {
		int a = i; int b = x * y / i;
		while (b > 0) {
			int z = b;
			b = a % b;
			a = z;
		}
		
		if (y % i == 0 && (x * y / i) % x == 0 && a == x) {
			ans1.push_back(i);
			ans2.push_back(x * y / i);
			if (i * i != x * y) {
				ans2.push_back(i);
				ans1.push_back(x * y / i);
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < (int)ans1.size(); i++) {
		if (ans2[i] <= r && ans2[i] >= l && ans1[i] >= l && ans1[i] <= r) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}