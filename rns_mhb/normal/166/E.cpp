#include <bits/stdc++.h>
using namespace std;

#define L 4
const int mod = 1e9 + 7;

struct matrix {
	int a[L][L];

	void init() {
		for (int i = 0; i < L; i ++) memset(a[i], 0, L * sizeof (int));
	}

	matrix operator * (const matrix &B) const {
		matrix C;
		C.init();
		for (int i = 0; i < L; i ++)
			for (int j = 0; j < L; j ++)
				for (int k = 0; k < L; k ++)
					C.a[i][j] = (C.a[i][j] + 1ll * a[i][k] * B.a[k][j]) % mod;
		return C;
	}
}A;

int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 4; i ++) for (int j = 0; j < 4; j ++) A.a[i][j] = 1;
	for (int i = 0; i < 4; i ++) A.a[i][i] = 0;
	matrix B;
	B.init();
	for (int i = 0; i < 4; i ++) B.a[i][i] = 1;
	while (n) {
		if (n & 1) B = B * A;
		n >>= 1;
		A = A * A;
	}
	printf("%d\n", B.a[0][0]);
}