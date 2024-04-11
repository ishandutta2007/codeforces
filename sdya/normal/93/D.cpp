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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;
const long long P2 = 500000004LL;
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

bool isValid(int i, int j) {
	if (min(i, j) == 0 && max(i, j) == 2) {
		return false;
	}
	if (min(i, j) == 1 && max(i, j) == 3) {
		return false;
	}
	return i != j;
}

matrix A;

long long get(long long n) {
	if (n == 0) {
		return 0LL;
	}
	if (n == 1) {
		return 4LL;
	}
	vector < long long > start(17, 0);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (isValid(i, j)) {
				++start[i * 4 + j];
				++start[16];
			}
		}
	}
	start[16] += 4;

	matrix B = pow(A, n - 2);
	long long res = 0;
	for (int i = 0; i < 17; ++i) {
		res += start[i] * B[i][16];
		res %= P;
	}
	return res;
}

long long solve(long long n) {
	long long x = get(n);
	long long y = get((n + 1) / 2);
	long long cnt = (x + y) * P2;
	return cnt % P;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	A.assign(17, vector < long long > (17, 0));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (!isValid(i, j) || !isValid(j, k)) {
					continue;
				}
				if (i == 0 && j == 1 && k == 2) {
					continue;
				}
				if (i == 2 && j == 1 && k == 0) {
					continue;
				}
				int x = i * 4 + j;
				int y = j * 4 + k;

				++A[x][y];
				++A[x][16];
			}
		}
	}
	A[16][16] = 1;

	long long l, r;
	cin >> l >> r;
	long long res = solve(r) - solve(l - 1);
	res = ((res % P) + P) % P;
	cout << res << endl;

	
	return 0;
}