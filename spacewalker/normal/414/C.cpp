#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int LMAX = 21;

int midSort[1 << LMAX], arr[1 << LMAX];
ll invAtLayer[LMAX][2]; // 0 = normal; 1 = if inverted

int n;

void addInversions(int i, int j, int lts) {
	if (i != j) {
		int k = (i + j) / 2;
		addInversions(i, k, lts - 1);
		addInversions(k + 1, j, lts - 1);
//		printf("BEGIN L %d\n", lts);
		int earliestGT = i, ptp = i;
		for (int x = k + 1; x <= j; ++x) {
			while (earliestGT <= k && arr[earliestGT] <= arr[x]) {
				midSort[ptp++] = arr[earliestGT++];
		}
//			printf("%d eg %d\n", x, earliestGT);
//			if (earliestGT <= k) printf("%d ref elem %d\n", arr[x], arr[earliestGT]);
			invAtLayer[lts][0] += k + 1 - earliestGT;
			midSort[ptp++] = arr[x];
		}
		while (earliestGT <= k) {
			midSort[ptp++] = arr[earliestGT++];
		}
		earliestGT = k + 1;
		for (int x = i; x <= k; ++x) {
			while (earliestGT <= j && arr[earliestGT] <= arr[x]) ++earliestGT;
			invAtLayer[lts][1] += j + 1 - earliestGT;
		}
		for (int x = i; x <= j; ++x) arr[x] = midSort[x];
//		printf("END SUBARR:\n");
//		for (int x = i; x <= j; ++x) printf("%d ", arr[x]);
//		printf("\n");
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 1 << n; ++i) scanf("%d", arr + i);
	addInversions(0, (1 << n) - 1, n);	
	int baliktadBa = 0;
	int m; scanf("%d", &m);
//	for (int i = 0; i <= n; ++i) {
//		printf("%d layer %lld %lld\n", i, invAtLayer[i][0], invAtLayer[i][1]);
//	}
	for (int qta = 0; qta < m; ++qta) {
		int x; scanf("%d", &x);
		baliktadBa ^= (1 << x);
		ll ans = 0;
		int isCurReversed = 0;
		for (int b = n; b >= 0; --b) {
			isCurReversed ^= (baliktadBa & (1 << b)) == 0 ? 0 : 1;
			ans += invAtLayer[b][isCurReversed];
		}
		printf("%lld\n", ans);
	}
	return 0;
}