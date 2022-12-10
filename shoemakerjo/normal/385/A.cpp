#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	int ans = 0;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i= 0; i < n-1; i++) {
		int cur = nums[i];
		cur -= nums[i+1];
		cur -= c;
		ans = max(ans, cur);
	}
	cout << ans << endl;
	// cin >> n;
}