#include <bits/stdc++.h>

using namespace std;

int n;
int nums[105];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = -1;

	int maxval = -1;
	//just try all up to 200
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		maxval = max(maxval, nums[i]);
	}

	for (int i = maxval; i <= 300; i++) {
		int osum = 0;
		int mysum = 0;
		for (int j = 0; j < n; j++) {
			osum += nums[j];
			mysum += i - nums[j];
		}
		if (mysum > osum) {
			cout << i << endl;
			return 0;
		}
	}
	
}