#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sum+=nums[i];

	}
	if (sum%3!=0) {
		cout << 0 << endl;
	}
	else {
		long long prefix[n];
		prefix[0] = nums[0];
		long long ot = 0;
		long long ans = 0;
		if (prefix[0]==sum/3) ot++;
		for (int i = 1; i < n-1; i++) {
			prefix[i] = prefix[i-1]+nums[i];
			if (prefix[i]==2*sum/3) {
				ans+=ot;
			}
			if (prefix[i]==sum/3) ot++;
		}
		cout << ans << endl;
	}
	// cin >>  n;
}