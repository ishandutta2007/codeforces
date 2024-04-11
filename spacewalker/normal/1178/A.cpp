#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	vector<int> pc{0};
	int tVotes = arr[0], cVotes = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[0] >= 2 * arr[i]) {
			pc.push_back(i);
			cVotes += arr[i];
		}
		tVotes += arr[i];
	}
	if (cVotes * 2 > tVotes) {
		printf("%lu\n", pc.size());
		for (int x : pc) printf("%d ", x + 1);
		printf("\n");
	}
	else {
		printf("0\n");
	}
	return 0;
}