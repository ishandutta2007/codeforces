#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int l, r, x;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> x;
		l--; r--; x--;
		int before = 0, after = 0;
		for (int j = l; j < x; j++) {
			if (nums[j] > nums[x]) before++;
		}
		for (int j = x+1; j <= r; j++) {
			if (nums[x] > nums[j]) after++;
		}
		if (before == after) cout << "Yes\n";
		else cout << "No\n";
	}
	// cin >> n;
}