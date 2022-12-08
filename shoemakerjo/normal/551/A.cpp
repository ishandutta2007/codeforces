#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int ans[n];

	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		ans[i] = 1;
		for (int j = 0; j < n; j++) {
			if (nums[j] > nums[i]) ans[i]++;
		}
		cout << ans[i];
	}
	cout << endl;
	// cin >> n;


}