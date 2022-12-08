#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sum = 0;
	int nums[6];
	for (int i = 0; i < 6; i++) {
		cin >> nums[i];
		sum += nums[i];
	}	
	bool ok = false;

	for (int i = 0; i < 6; i++) {
		for (int j = i+1; j < 6; j++) {
			for (int k = j+1; k < 6; k++) {
				if ((nums[i]+nums[j]+nums[k])*2 == sum) {
					ok = true;
				}
			}
		}
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
	cin >> sum;
}