#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
constexpr int NMAX = 5000010;
int bacCount[NMAX], bacPart[NMAX+1], k;

int getRangeSum(int i, int j) {
	return bacPart[j+1] - bacPart[i];
}

int main() {
	int n; scanf("%d %d", &n, &k);
	vector<int> bsize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &bsize[i]);
		++bacCount[bsize[i]];
	}
	for (int i = 1; i <= NMAX; ++i) {
		bacPart[i] = bacPart[i-1] + bacCount[i-1];
	}
	int hindiKain = 0;
	for (int bs : bsize) {
		if (getRangeSum(bs + 1, bs + k) == 0) ++hindiKain;
	}
	printf("%d\n", hindiKain);
	return 0;
}