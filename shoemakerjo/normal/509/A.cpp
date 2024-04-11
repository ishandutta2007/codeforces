#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n][n];
	for (int i = 0; i < n; ++i) {
		nums[0][i] = 1;
		nums[i][0] = 1;
//		cout << i << endl;
	}
	int ma = 1;
	for(int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			nums[i][j] = nums[i-1][j] + nums[i][j-1];
			ma = max(ma, nums[i][j]);
		}
	}
	cout << ma << '\n';
}