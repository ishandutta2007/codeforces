#include <bits/stdc++.h>
using namespace std;

const int N = 100005, P = 1000000007;
int a, b, c, d, lA, lB, fac[N], ifac[N];
char _A[N], *A, _B[N], *B;

int power(int a, int x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1LL * a * a % P)
		if (x & 1) ans = 1LL * ans * a % P;
	return ans;
}
int binom(int n, int m) {
	if (n < m) return 0;
	return 1LL * fac[n] * ifac[m] % P * ifac[n - m] % P;
}
int divide(int n, int m) {
	if (n == 0) return m == 0;
	return binom(n - 1, m - 1);
}
int count(bool first, int a, int b, int c, int d) {
	if (a < 0 || b < 0 || c < 0 || d < 0) return 0;
	if (!first && !(b == c || b == c + 1)) return 0;
	if (first && !(b == c || c == b + 1)) return 0;
	int r0 = (!first ? c + 1 : c), r1 = (!first ? b : b + 1);
	int c0 = a + r0, c1 = d + r1;
	return 1LL * divide(c0, r0) * divide(c1, r1) % P;
}
int solve(int l, char *s) {
	if (a + b + c + d + 1 < l)
		return count(1, a, b, c, d);
	if (a + b + c + d + 1 > l)
		return 0;
	int ans = 0, na = 0, nb = 0, nc = 0, nd = 0;
	for (int i = 1; i < l; i++) {
		if (s[i]) ans = (ans + count(0, a - na - (!s[i - 1]), b - nb, c - nc - s[i - 1], d - nd)) % P;
		if (!s[i - 1]) (s[i] ? nb : na)++;
		else (s[i] ? nd : nc)++;
	}
	return ans;
}

int main() {
	scanf("%s%s%d%d%d%d", _A, _B, &a, &b, &c, &d);
	for (A = _A; *A == '0'; A++);
	for (B = _B; *B == '0'; B++);
	lA = strlen(A), lB = strlen(B);
	for (int i = 0; i < lA; i++) A[i] -= '0';
	for (int i = 0; i < lB; i++) B[i] -= '0';
	for (int i = fac[0] = 1; i < N; i++) fac[i] = 1LL * fac[i - 1] * i % P;
	ifac[N - 1] = power(fac[N - 1], P - 2);
	for (int i = N - 1; i; i--) ifac[i - 1] = 1LL * ifac[i] * i % P;
	reverse(B, B + lB);
	int pos = 0;
	while (pos < lB && B[pos]) B[pos++] = 0;
	B[pos] = 1;
	if (pos == lB) lB++;
	reverse(B, B + lB);
	int ans = (solve(lB, B) - solve(lA, A) + P) % P;
	printf("%d\n", ans);
	return 0;
}