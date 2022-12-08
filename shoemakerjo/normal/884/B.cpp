#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	int nums[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sum += nums[i];
	}
	if (sum + n-1 == x) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	cin >> n;

}