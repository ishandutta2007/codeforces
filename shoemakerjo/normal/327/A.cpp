#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n+1];
	nums[0] = -1;
	for (int i = 1; i <= n; ++i) {
		cin >> nums[i];
	}
	int prefix1[n+1];
	int prefix0[n+1];

	prefix1[0] = 0;
	prefix0[0] = 0;
	for (int i = 1; i <= n; ++i) {
		prefix1[i] = prefix1[i-1];
		prefix0[i] = prefix0[i-1];
		if (nums[i]==1) {
			prefix1[i]++;
		}
		else prefix0[i]++;
	}
	int start = prefix1[n];
	int ans = prefix1[n];
	bool allOne = true;
	for (int i = 0; i <= n; i++) {
		if (i > 0 && nums[i]==0) allOne = false;
//		cout << prefix1[i] << " " << prefix0[i] << endl;
		for (int j = 0; j <= i; j++) {
			int lost = prefix1[i]-prefix1[j];
			int gain = prefix0[i]-prefix0[j];
			ans = max(ans, start+gain-lost);
		}
	}
	if (allOne) ans--;
	cout << ans << endl;

}