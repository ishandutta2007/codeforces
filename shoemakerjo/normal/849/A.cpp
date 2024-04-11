#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) cin >> nums[i];
	if (n%2 == 1) {
		if (nums[n-1]%2==1 && nums[0]%2==1) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
	else {
		bool ok = false;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n-1; j++) {
				if ((i+1) % 2 == 0) continue;
				if ((j-i) % 2 == 0) continue;
				if ((n-j-1)%2 == 0) continue;
				if (nums[0] %2 == 1 && nums[i]%2 == 1 && nums[i+1] %2 == 1 
					&& nums[j]%2==1 && nums[j+1]%2==1 && nums[n-1]%2 == 1) ok = true;
			}
		}
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
	cin >> n;
}