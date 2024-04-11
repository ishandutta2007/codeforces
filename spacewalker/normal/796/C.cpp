#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#define INF 2000000000

using namespace std;

int main() {
	int bankCount; scanf("%d", &bankCount);

	vector<int> strength(bankCount, 0);
	vector<vector<int>> neighbors(bankCount, vector<int>());

	for (int bank = 0; bank < bankCount; ++bank) {
		scanf("%d", &strength[bank]);
	}

	for (int neighPair = 0; neighPair < bankCount - 1; ++neighPair) {
		int ui, vi;
		scanf("%d %d", &ui, &vi);
		--ui; --vi;
		neighbors[ui].push_back(vi);
		neighbors[vi].push_back(ui);
	}

	 vector<int> bestNeighStr(bankCount, -INF);
	 for (int bank = 0; bank < bankCount; ++bank) {
	 	int cBestStr = -INF;
	 	for (int neighbor : neighbors[bank]) {
	 		cBestStr = max(cBestStr, strength[neighbor]);
	 	}
	 	bestNeighStr[bank] = cBestStr;
	 }

	multiset<int, greater<int>> bestStr;
	for (int bank = 0; bank < bankCount; ++bank) {
		bestStr.insert(strength[bank]);
	}

	vector<int> bestSurroundingStr(bankCount, -INF);

	for (int bank = 0; bank < bankCount; ++bank) {

		bestStr.erase(bestStr.find(strength[bank]));
		for (int neighbor : neighbors[bank]) {
			bestStr.erase(bestStr.find(strength[neighbor]));
		}
		if (!bestStr.empty()) {
			bestSurroundingStr[bank] = *(bestStr.begin());
		}
		bestStr.insert(strength[bank]);
		for (int neighbor : neighbors[bank]) {
			bestStr.insert(strength[neighbor]);
		}
	}

	int bestScore = INF;
	for (int bank = 0; bank < bankCount; ++bank) {
		int cBestScore = strength[bank];
		cBestScore = max(cBestScore, bestNeighStr[bank] + 1);
		cBestScore = max(cBestScore, bestSurroundingStr[bank] + 2);
		bestScore = min(bestScore, cBestScore);
	}

	printf("%d", bestScore);
	return 0;
}