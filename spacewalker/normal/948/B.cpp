#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000
using namespace std;

vector <int> maxDiv(MAX + 1, 0);

int main() {
	maxDiv[0] = -1;
	maxDiv[1] = -1;
	for (int i = 2; i <= MAX; ++i) {
		maxDiv[i] = i;
	}
	for (int i = 2; i <= MAX; ++i) {
		if (maxDiv[i] == i) {
			for (int toMark = 2*i; toMark <= MAX; toMark += i) {
				maxDiv[toMark] = i;
			}
		}
	}
	vector<int> minPrecursor(MAX + 1, -1);
	for (int i = 0; i <= MAX; ++i) {
		if (maxDiv[i] == i) {
			continue;
		} else {
			minPrecursor[i] = i - maxDiv[i] + 1;
		}
	}
	int n; cin >> n;
	//cout << "md  " << maxDiv[n] << endl;
	int ans = 2 * MAX;
	//cout << "range from " << n - maxDiv[n] + 1 << " to " << n << endl;
	for (int i = n - maxDiv[n] + 1; i <= n; ++i) {
		if (minPrecursor[i] >= 0) {
			ans = min(ans, minPrecursor[i]);
		}
	}
	cout << ans << endl;
	return 0;
}