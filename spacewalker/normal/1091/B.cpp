#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> obelisk(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &(obelisk[i].first), &(obelisk[i].second));
	}
	vector<pair<int, int>> clues(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &(clues[i].first), &(clues[i].second));
	}
	sort(clues.begin(), clues.end());
	vector<pair<int, int>> guess(n);
	for (int i = 0; i < n; ++i) {
		guess[i].first = obelisk[0].first + clues[i].first;
		guess[i].second = obelisk[0].second + clues[i].second;
		// printf("g %d %d\n", guess[i].first, guess[i].second);
	}
	for (int i = 0; i < n; ++i) {
		vector<pair<int, int>> ccl(n);
		for (int j = 0; j < n; ++j) {
			ccl[j].first = guess[i].first - obelisk[j].first;
			ccl[j].second = guess[i].second - obelisk[j].second;
			// printf("c %d %d\n", ccl[j].first, ccl[j].second);
		}
		sort(ccl.begin(), ccl.end());
		if (ccl == clues) {
			printf("%d %d\n", guess[i].first, guess[i].second);
			break;
		}
	}
	return 0;
}