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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;
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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	matrix A(2, vector < long long > (2, 0));
	A[0][0] = A[1][1] = 3;
	A[1][0] = A[0][1] = 1;
	long long n;
	cin >> n;
	A = pow(A, n);

	cout << A[0][0] << endl;

	return 0;
}