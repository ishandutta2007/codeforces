#include <iostream>
using namespace std;

int main() {
	int c1, c2, c3, c4;
	cin >> c1 >> c2 >> c3 >> c4;
	int best = c4;
	
	int n, m;
	cin >> n >> m;
	
	int bestA = c3, bestB = c3;
	int currentA = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v == 0) {
			continue;
		}
		currentA += min(c2, c1 * v);
	}
	int currentB = 0;
	for (int i = 0; i < m; ++i) {
		int v;
		cin >> v;
		if (v == 0) {
			continue;
		}
		currentB += min(c2, c1 * v);
	}
	bestA = min(bestA, currentA);
	bestB = min(bestB, currentB);
	best = min(best, bestA + bestB);
	cout << best << endl;
	return 0;
}