#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
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

long long getFibo(long long n) {
	matrix A(2, vector < long long > (2, 1));
	A[0][0] = 0;
	if (n == 1) {
		return 1 % P;
	}
	A = pow(A, n - 1);
	long long res = A[0][0] + A[1][0];
	return (res % P);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> P;
	long long l, r, k;
	cin >> l >> r >> k;

	long long d = ((double)(r) + (double)(l) * (double)(k)) / (double)(r - l);
	long long x = (r - l + 1) / (k - 1);
	long long res = 1;
	const long long maxD = 20000000;
	for (long long i = x; i >= x - maxD && i >= 1; --i) {
		long long a = (l + i - 1) / i;
		long long b = r / i;
		if (b - a + 1 >= k) {
			res = i;
			break;
		}
	}

	const long long maxP = 1000000;
	for (long long i = d + maxP; i >= d - maxP && i >= 1; --i) {
		long long left_bound = (l + i - 1) / i;
		long long right_bound = r / (i + k - 1);
		if (right_bound >= left_bound) {
			res = max(res, right_bound);
		}
	}

	cout << getFibo(res) << endl;

	return 0;
}