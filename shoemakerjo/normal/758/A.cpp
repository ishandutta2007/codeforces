#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	int ma = 0;
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
		ma = max(ma, nums[i]);
	}
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (ma-nums[i]);
	}
	cout << sum << endl;
	// cin >> n;
}