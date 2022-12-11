#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int ict[1010][100][2];
int pow10[1010];

// to fix the bug, i have to make sure i set the second parameter to 1
// only when the digit is nonzero

int main() {
	int n, k, m; scanf("%d %d %d", &n, &k, &m);
	pow10[0] = 1;
	for (int i = 1; i <= n; ++i) pow10[i] = (pow10[i-1] * 10) % k;
	for (int d = (n == 1 ? 1 : 0); d < 10; ++d) {
		++ict[1][d % k][(d % k == 0 && d > 0 ? 1 : 0)];
	}
	// for (int cmod = 0; cmod < k; ++cmod) {
	// 	printf("start value %d %d %d\n", cmod, ict[1][cmod][0], ict[1][cmod][1]);
	// }
	for (int digCount = 2; digCount <= n; ++digCount) {
		// printf("ATT DIGIT %d\n", digCount);
		// fill in the entries without a zero suffix
		for (int pmod = 0; pmod < k; ++pmod) {
			for (int lastD = 0; lastD <= 9; ++lastD) {
				if (lastD == 0 && digCount == n) continue; // don't take lead zeroes
				int cVal = (pmod + (lastD * pow10[digCount-1])) % k;
				if (cVal > 0) {
					ict[digCount][cVal][0] = (ict[digCount][cVal][0] + ict[digCount-1][pmod][0]) % m;
					// printf("pmod %d dig %d has new mod %d val abs %d\n", pmod, lastD, cVal, ict[digCount][cVal][0]);
				} else if (cVal == 0 && lastD > 0) {
					ict[digCount][0][1] = (ict[digCount][0][1] + ict[digCount-1][pmod][0]) % m;
				} else {
					ict[digCount][0][0] = (ict[digCount][0][1] + ict[digCount-1][pmod][0]) % m;
				}
			}
		}
		for (int pmod = 0; pmod < k; ++pmod) {
			for (int lastD = 0; lastD <= 9; ++lastD) {
				if (lastD == 0 && digCount == n) continue; // don't take lead zeroes
				int cVal = (pmod + (lastD * pow10[digCount-1])) % k;	
				ict[digCount][cVal][1] = (ict[digCount][cVal][1] + ict[digCount-1][pmod][1]) % m;
				// printf("pmod %d dig %d has new mod %d val pres %d\n", pmod, lastD, cVal, ict[digCount][cVal][1]);
			}
		}
		// for (int cmod = 0; cmod < k; ++cmod) {
		// 	printf("value %d %d %d\n", cmod, ict[digCount][cmod][0], ict[digCount][cmod][1]);
		// }
	}
	int ans = 0;
	for (int cmod = 0; cmod < k; ++cmod) {
		ans = (ans + ict[n][cmod][1]) % m;
	}
	printf("%d\n", ans);
	return 0;
}