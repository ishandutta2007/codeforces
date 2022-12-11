#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	printf("0 0\n");
	vector<pair<int, int>> states = {{2, 0}, {1, 1}, {1, -1}};
	for (int i = 1; i < n; ++i) {
		printf("%d %d\n", states[i%3].first, states[i%3].second);
		states[i%3].first += 2;
	}
	return 0;
}