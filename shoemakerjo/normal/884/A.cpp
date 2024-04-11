#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	int nums[n];
	for (int i = 0; i < n; i++) cin >> nums[i];
	int cur = t;
	for (int i = 0; i < n; i++) {
		cur -= 86400-nums[i];
		if (cur <= 0) {
			cout << i+1 << endl;
			break;
		}
	}
	cin >> n;
}