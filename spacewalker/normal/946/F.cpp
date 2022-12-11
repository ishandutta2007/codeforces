#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 110;
constexpr int MOD = 1000000007;

ll back1[NMAX][NMAX][2][2], back2[NMAX][NMAX][2][2], back0[NMAX][NMAX][2][2];
int fibLength[NMAX];
ll pow2fib[NMAX];

char strng[NMAX];

ll modexp(ll b, int e) {
	if (e == 0) return 1;
	else return (e & 1 ? b : 1) * modexp(b * b % MOD, e/2) % MOD;
}

int main() {
	fibLength[0] = fibLength[1] = 1;
	for (int i = 2; i < NMAX; ++i) 
		fibLength[i] = (fibLength[i-1] + fibLength[i-2]) % (MOD - 1);
	for (int i = 0; i < NMAX; ++i) pow2fib[i] = modexp(2, fibLength[i]);
	int n, x; scanf("%d %d", &n, &x);
	scanf("%s", strng);
	if (x <= 1) {
		if (n == 1 && (strng[0] == '1') == (x == 1)) printf("1\n");
		else printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int b1 = 0; b1 < 2; ++b1) {
			for (int b2 = 0; b2 < 2; ++b2) {
				back0[i][i][b1][b2] = strng[i] == '1' ? 1 : 0;
				back1[i][i][b1][b2] = strng[i] == '0' ? 1 : 0;
			}
		}
	}
	for (int cx = 2; cx <= x; ++cx) {
		swap(back2, back1);
		swap(back1, back0);
		memset(back0, 0, sizeof back0);
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				for (int b1 = 0; b1 < 2; ++b1) {
					for (int b2 = 0; b2 < 2; ++b2) {
						for (int k = i; k < j; ++k) {
							back0[i][j][b1][b2] = (back0[i][j][b1][b2] + back1[i][k][b1][0] * back2[k + 1][j][0][b2] % MOD) % MOD;
						}
						back0[i][j][b1][b2] = (back0[i][j][b1][b2] + (b1 ? pow2fib[cx - 1] : 1) * back2[i][j][b1][b2] % MOD) % MOD;
						back0[i][j][b1][b2] = (back0[i][j][b1][b2] + back1[i][j][b1][b2] * (b2 ? pow2fib[cx - 2] : 1) % MOD) % MOD;
//						printf("%d %d %d %d %d = %lld\n", cx, i, j, b1, b2, back0[i][j][b1][b2]);
					}
				}
			}
		}
	}
	printf("%lld\n", back0[0][n-1][1][1]);
	return 0;
}