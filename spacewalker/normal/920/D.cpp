#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 5010;
constexpr int INF = 1000000000;

bool modSumPossible[NMAX][NMAX];

void printTransfer(int x, int y, int cnt) {
	if (cnt <= 0) return;
	printf("%d %d %d\n", cnt, x + 1, y + 1);
}

int ceilDiv(int a, int b) {
	return (a / b) + (a % b != 0);
}

int main() {
	int n, k; ll v; scanf("%d %d %lld", &n, &k, &v);
	vector<ll> initAmt(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &initAmt[i]);
	int allSum = accumulate(begin(initAmt), end(initAmt), 0);
	modSumPossible[0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int mval = 0; mval < k; ++mval) {
			modSumPossible[i+1][mval] = modSumPossible[i][mval] || modSumPossible[i][(mval + k - (initAmt[i] % k)) % k];
		}
	}
	vector<int> fullTake, hivemind;
	if (!modSumPossible[n][v%k] || allSum - (allSum + k - (v % k)) % k < v) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = n, cmv = v%k; i > 0; --i) {
		if (modSumPossible[i-1][(cmv + k - (initAmt[i-1] % k)) % k]) {
			fullTake.push_back(i-1);
			cmv = (cmv + k - (initAmt[i-1] % k)) % k;
		} else {
			hivemind.push_back(i-1);
		}
	}
	if (v % k == 0) {
		// alternate strategy
		for (int i = 1; i < n; ++i) printTransfer(i, 0, ceilDiv(initAmt[i], k));
		printTransfer(0, 1, v / k);
	} else {
		// transfer all fullTakes to fullTake[0]
		int goalTank = fullTake[0];
		ll onCenter = initAmt[goalTank];
		for (int v : fullTake) {
			if (v == goalTank) continue;
//			printf("FT %d\n", v);
			printTransfer(v, goalTank, ceilDiv(initAmt[v], k));
			onCenter += initAmt[v];
		}
		for (int v : hivemind) {
//			printf("HM %d\n", v);
			printTransfer(v, (goalTank + 1) % n, ceilDiv(initAmt[v], k));	
		}
//		printf("OC %lld\n", onCenter);
		if (onCenter < v) {
			printTransfer((goalTank + 1) % n, goalTank, (v - onCenter) / k);
		}
		if (onCenter > v) {
			printTransfer(goalTank, (goalTank + 1) % n, (onCenter - v) / k);
		}
	}
	return 0;
}