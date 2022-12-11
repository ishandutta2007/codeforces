#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> steps(k, 0);
	for (int cS = 0; cS < k; ++cS) {
		scanf("%d", &steps[cS]);
	}

	vector<int> stillIn(n, 0);
	for (int i = 0; i < n; ++i) {
		stillIn[i] = i + 1;
	}

	int cLeaderIdx = 0;
	int cCycleLength = n;
	for (int turn = 0; turn < k; ++turn) {
		int toKillIdx = (cLeaderIdx + steps[turn]) % cCycleLength;
		printf("%d\n", stillIn[toKillIdx]);
		vector<int> newStillIn;
		for (int toCheck = 0; toCheck < cCycleLength; ++toCheck) {
			if (toCheck == toKillIdx) {
				continue;
			}
			newStillIn.push_back(stillIn[toCheck]);
		}
		newStillIn.swap(stillIn);
		--cCycleLength;
		cLeaderIdx = toKillIdx;
	}

	return 0;
}