#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxM = 320290;
int f[maxM];

// 12 288
// 1 220 703 125

const long long P = 1220703125LL;
const int maxN = 2;

struct matrix {
	long long a[maxN][maxN];
};

matrix operator * (matrix A, matrix B) {
	matrix C;
	for (int i = 0; i < maxN; ++i)
		for (int j = 0; j < maxN; ++j) 
			C.a[i][j] = 0;

	for (int i = 0; i < maxN; ++i)
		for (int j = 0; j < maxN; ++j)
			for (int k = 0; k < maxN; ++k) {
				C.a[i][j] += A.a[i][k] * B.a[k][j];
				C.a[i][j] %= P;
			}
	for (int i = 0; i < maxN; ++i) 
		for (int j = 0; j < maxN; ++j)
			if (C.a[i][j] < 0) {
				C.a[i][j] += P;
			}
	return C;
}

matrix powmod(matrix A, long long n) {
	if (n == 0) {
		matrix res;
		for (int i = 0; i < maxN; ++i)
			for (int j = 0; j < maxN; ++j) {
				if (i == j) {
					res.a[i][j] = 1;
				} else {
					res.a[i][j] = 0;
				}
			}
		return res;
	}

	matrix B = powmod(A, n / 2LL);
	B = (B * B);
	if (n % 2LL == 0LL) {
		return B;
	}
	return A * B;
}

vector < int > get2(unsigned int x) {
	vector < int > res;
	if (x == 0) {
		res.push_back(0);
	}
	if (x == 1) {
		res.push_back(1);
	}

	unsigned int p = 12288;
	unsigned int a = 0, b = 1, c;
	
	for (unsigned int i = 2; i < p; ++i) {
		c = a + b;
		if (c >= (1 << 13)) {
			c -= (1 << 13);
		}
		if (x == c) {
			res.push_back(i);
		}
		a = b, b = c;
	}
	return res;
}

long long get(long long a, long long b) {
	for (long long i = 0; i < 12288LL; ++i) {
		long long cur = b + i * 4LL * 1220703125LL;
		if (cur % 12288LL == a) {
			return cur;
		}
	}
	return 1000000000000000000LL;
}

vector < long long > get5(unsigned int x) {
	vector < long long > res;
	if (x == 0) {
		res.push_back(0);
	}
	if (x == 1) {
		res.push_back(1);
	}
	unsigned int p = 195312500;
	unsigned int a = 0, b = 1, c;
	int index = -1;

	unsigned int y = (x % 48828125);

	vector < unsigned int > u;
	if (y == 0) {
		u.push_back(0);
	}
	if (y == 1) {
		u.push_back(1);
	}
	for (unsigned int i = 2; i < p; ++i) {
		c = a + b;
		if (c >= 48828125) {
			c -= 48828125;
		}
		if (y == c) {
			u.push_back(i);
		}
		a = b, b = c;
	}

	matrix A;
	A.a[0][0] = 0;
	A.a[0][1] = A.a[1][0] = A.a[1][1] = 1;

	for (int j = 0; j < u.size(); ++j) {
		int index = u[j];
		for (int i = 0; i < 25; ++i) {
			long long position = (long long)(index) + (long long)(i) * (long long)(195312500);
			matrix B = powmod(A, position);

			if (B.a[1][0] == x) {
				res.push_back(position);
			}
		}
	}

	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long x;
	cin >> x;

	/*f[0] = 0, f[1] = 1;
	for (int i = 2; ; ++i) {
		f[i] = (f[i - 1] + f[i - 2]) % (1 << 12);
		if (f[i - 1] == 0 && f[i] == 1) {
			cout << i - 1 << endl;
			break;
		}
	}*/

	int need2 = x % (1LL << 13);
	int need5 = x % 1220703125LL;

	vector < int > a = get2(need2);
	vector < long long > b = get5(need5);

	long long res = 1000000000000000000LL;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			res = min(res, get(a[i], b[j]));
		}
	}

	if (res == 1000000000000000000LL) {
		res = -1;
	}

	cout << res << endl;

	return 0;
}