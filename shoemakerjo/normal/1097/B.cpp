#include <bits/stdc++.h>

using namespace std;

int n;
int nums[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool ok = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int mask = 0; mask < (1 << n); mask++) {
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (mask & (1 << j)) {
				cur += nums[j];
			}
			else cur -= nums[j];
		}
		if (cur >= 0 && cur % 360 == 0) ok = true;
	}
	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;

	
}