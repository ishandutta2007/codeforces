#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	int temp;
	vector<int> wormLabels(1, -1);
	int wormsPresent = 0;
	for (int pile = 1; pile <= n; ++pile) {
		scanf("%d", &temp);
		wormsPresent += temp;
		for (int cWorm = wormLabels.size(); cWorm <= wormsPresent; ++cWorm) {
			wormLabels.push_back(pile);
		}
	}

	int m; scanf("%d", &m);
	while (m--) {
		scanf("%d", &temp);
		printf("%d\n", wormLabels[temp]);
	}
	return 0;
}