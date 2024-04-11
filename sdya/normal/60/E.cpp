#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long P;
const long long inf = 6000000000000000000LL;
typedef vector < vector < long long > > matrix;

matrix mul(const matrix& A, const matrix& B) {
	int n = A.size();
	matrix C(n, vector < long long > (n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			long long current = 0;
			for (int k = 0; k < n; ++k) {
				current += A[i][k] * B[k][j];
				if (current >= inf) {
					current %= P;
				}
			}
			C[i][j] = current % P;
		}
	}
	return C;
}

matrix pow(const matrix& A, long long n) {
	if (n == 0) {
		matrix B(A.size(), vector < long long > (A.size(), 0));
		for (int i = 0; i < A.size(); ++i) {
			B[i][i] = 1;
		}
		return B;
	}
	matrix B = pow(A, n / 2);
	B = mul(B, B);

	if (n % 2 == 0) {
		return B;
	} else {
		return mul(B, A);
	}
}

const int maxN = 1100000;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long n, x, y;
	cin >> n >> x >> y >> P;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	if (n == 1) {
		cout << (long long)(a[0]) % P << endl;
		return 0;
	}

	long long s = 0;
	for (int i = 0; i < n; ++i) {
		s += a[i];
	}
	s %= P;

	matrix A(2, vector < long long > (2));
	A[0][0] = 0LL % P;
	A[0][1] = 1LL % P;
	A[1][0] = 1LL % P;
	A[1][1] = 1LL % P;

	A = pow(A, x);
	long long u = a[0];
	long long v = (long long)(a[n - 2]) * A[1][0] + (long long)(a[n - 1]) * A[1][1];

	u %= P;
	v %= P;

	matrix B(2, vector < long long > (2));
	B[0][0] = 1LL % P;
	B[0][1] = (((long long)(-a[0] - a[n - 1]) % P) + P) % P;
	B[1][0] = 0;
	B[1][1] = 3LL % P;

	B = pow(B, x);

	s = (B[0][1] + s * B[1][1]) % P;

	matrix C(2, vector < long long > (2));
	C[0][0] = 1LL % P;
	C[0][1] = (((-u - v) % P) + P) % P;
	C[1][0] = 0;
	C[1][1] = 3LL % P;

	C = pow(C, y);

	s = (C[0][1] + s * C[1][1]) % P;
	cout << s << endl;

	return 0;
}