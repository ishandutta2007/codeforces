#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n+1][2];
	int L = 0, R = 0;
	int l, r;
	for (int i = 1; i <=n; i++) {
		cin >> l >> r;
		nums[i][0] = l;
		nums[i][1] = r;
		L+=l;
		R+=r;
	}
	int val = abs(L-R);
	int ans = 0;
	int curl, curr;
	for (int i = 1; i <= n; i++) {
		curl = L - nums[i][0]+nums[i][1];
		curr = R - nums[i][1] + nums[i][0];
		if (abs(curl-curr) > val) {
			val = abs(curl-curr);
			ans = i;
		}
	}
	cout << ans << endl;
	// cin >> n;
}