#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, temp; scanf("%d", &n);
	vector<int> heights(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &heights[i]);
	}

	sort(heights.begin(), heights.end()); // excluding boilerplate, input and output, this is the only line.

	for (int i = 0; i < n; ++i) {
		printf("%s%d", (i > 0 ? " " : ""), heights[i]);
	}
	return 0;
}