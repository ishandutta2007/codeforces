#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> lengths(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> lengths[i];
	}
	// [i - lengths[i], i)
	vector<int> farthestReach(n, 0);
	for (int i = 0; i < n; ++i) {
		farthestReach[i] = i - lengths[i];
	}

	vector<int> suffixMin(n, farthestReach[n - 1]);

	for (int i = n - 2; i >= 0; --i) {
		suffixMin[i] = min(farthestReach[i], suffixMin[i + 1]);
	}

	int totalAlive = 1;
	for (int i = 0; i < n - 1; ++i) {
		if (i < suffixMin[i + 1]) {
			++totalAlive;
		}
	}

	cout << totalAlive;

	return 0;
}