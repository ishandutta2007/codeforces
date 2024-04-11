#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, p;
	scanf("%d", &n);
	if (n % 2) {
		printf("Second\n");
		fflush(stdout);
		vector<int> x[n];
		for (int i = 0; i < 2 * n; ++i) scanf("%d", &p), x[p - 1].push_back(i);
		int blocks[2 * n];
		for (int i = 0; i < n; ++i) {
			blocks[x[i][0]] = x[i][1];
			blocks[x[i][1]] = x[i][0];
		}
		bool picked[2 * n];
		fill_n(picked, 2 * n, 0);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			if (!picked[i] && !picked[i + n]) {
				picked[i] = true, sum += i;
				for (int j = blocks[i]; true; j = blocks[j]) {
					if (j < n) {
						if (j == i) break;
						j += n;
						picked[j] = true, sum += j;
					} else {
						if (j == i + n) break;
						j -= n;
						picked[j] = true, sum += j;
					}
				}
			}
		}
		sum += n;
		if (sum % (2 * n)) {
			for (int i = 0; i < 2 * n; ++i) {
				if (!picked[i]) printf("%d ", i + 1);
			}
		} else {
			for (int i = 0; i < 2 * n; ++i) {
				if (picked[i]) printf("%d ", i + 1);
			}
		}
	} else {
		printf("First\n");
		fflush(stdout);
		for (int i = 0; i < 2 * n; ++i) printf("%d ", i % n + 1);
	}
	fflush(stdout);
	return 0;
}