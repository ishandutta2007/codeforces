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
const int maxN = 1100;
int n, m, k;

long long d[maxN][maxN];
long long s1[maxN][maxN], s2[maxN][maxN];

long long calc(int n, int k) {
	memset(d, 0, sizeof(d));
	memset(s1, 0, sizeof(s1));
	memset(s2, 0, sizeof(s2));
	d[0][n] = 1LL;
	for (int i = 0; i <= n; ++i) {
		s1[0][i] = d[0][i];
		if (i > 0) {
			s1[0][i] += s1[0][i - 1];
			s1[0][i] %= P;
		}

		s2[0][i] = (d[0][i] * (long long)(i)) % P;
		if (i > 0) {
			s2[0][i] += s2[0][i - 1];
			s2[0][i] %= P;
		}
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j + 2 <= n; ++j) {
			long long A = s2[i - 1][n] - s2[i - 1][j + 1];
			A -= (long long)(j + 1) * (s1[i - 1][n] - s1[i - 1][j + 1]);
			A = (A % P);
			if (A < 0) {
				A += P;
			}
			d[i][j] = A;
		}

		for (int j = 0; j <= n; ++j) {
			s1[i][j] = d[i][j];
			if (j > 0) {
				s1[i][j] += s1[i][j - 1];
				s1[i][j] %= P;
			}

			s2[i][j] = (d[i][j] * (long long)(j)) % P;
			if (j > 0) {
				s2[i][j] += s2[i][j - 1];
				s2[i][j] %= P;
			}
		}
	}

	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		res += d[k][i];
		res %= P;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	long long res = calc(n, k) * calc(m, k);
	cout << (res % P) << endl;

	return 0;
}