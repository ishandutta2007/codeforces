#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> readVector(int size) {
	vector<int> res(size, 0);
	for (int i = 0; i < size; ++i) {
		scanf("%d", &res[i]);
	}
	return res;
}

bool isIncreasing(vector<int> &a) {
	for (int i = 0; i < a.size() - 1; ++i) {
		if (a[i] > a[i+1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> hitagi = readVector(n);
	vector<int> kaiki = readVector(k);

	sort(kaiki.begin(), kaiki.end(), greater<int>());
	int kptr = 0;
	for (int i = 0; i < n; ++i) {
		if (hitagi[i] == 0) {
			hitagi[i] = kaiki[kptr++];
		}
	}

	printf("%s", (isIncreasing(hitagi) ? "NO" : "YES"));

	return 0;
}