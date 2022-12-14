#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
long long s, c[60][60]; 
long long n, k, ans;

void Add(long long &x, long long y) {
	x += y;
	while (x >= P) x -= P;
}

struct Martix {
	long long a[90][90];
	Martix () {
		memset(a, 0, sizeof a);
	}

	Martix operator * (const Martix &B) const {
		Martix C;
		for (int k = 0; k < n; k ++)
			for (int i = 0; i < n; i ++)
				for (int j = 0; j < n; j ++)
					Add(C.a[i][j], 1ll * a[i][k] * B.a[k][j] % P);
		return C;
	}

	Martix operator ^ (long long B) const {
		Martix A = (*this), C;
		for (int i = 0; i < n; i ++) C.a[i][i] = 1;
		for (; B; B >>= 1, A = A * A) if (B & 1) C = C * A;
		return C;
	}
}E;

int main() {
	scanf("%lld%d", &s, &k);
	n = k * 2 + 3;
	for (int i = 0; i <= k; i ++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j ++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	for (int i = 0; i <= k; i ++) for (int j = 0; j <= i; j ++)
		E.a[i][j] = E.a[i + k + 1][j] = E.a[i][j + k + 1] = c[i][j];
	E.a[2 * k + 2][k] = E.a[2 * k + 2][2 * k + 2] = 1;
	E = E ^ s;
	for (int i = 0; i < 2 * k + 2; i ++) Add(ans, E.a[2 * k + 2][i]);
	printf("%d\n", ans);
	return 0;
}