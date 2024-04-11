#define _CRT_SECURE_NO_WARNINGS
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
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5100;
const int P = 1000000007;
int n;
char s[maxN];

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1LL;
	}

	long long b = powmod(a, n / 2LL);
	b = (b * b) % (long long)(P);

	if (n % 2LL == 0LL) {
		return b;
	}
	return (a * b) % (long long)(P);
}

long long inverse(long long a) {
	return powmod(a, P - 2);
}

inline void add(int &x, int value) {
	x += value;
	if (x >= P) {
		x -= P;
	}
}

inline void rem(int &x, int value) {
	x -= value;
	if (x < 0) {
		x += P;
	}
}

int nt[maxN][26];

int d[maxN][maxN];
int cnt[maxN];

long long f[maxN];

long long cnk(int n, int k) {
	long long A = f[n];
	long long B = inverse(f[n - k]) * inverse(f[k]);
	B %= (long long)(P);
	return (A * B) % (long long)(P);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (f[i - 1] * (long long)(i)) % (long long)(P);
	}

	scanf("%d", &n);
	scanf("%s", &s);

	for (int i = 0; i < 26; ++i) {
		nt[n][i] = -1;
		for (int j = n - 1; j >= 0; --j) {
			if (s[j] == 'a' + i) {
				nt[j][i] = j;
			} else {
				nt[j][i] = nt[j + 1][i];
			}
		}
	}

	for (int i = 0; i < 26; ++i) {
		if (nt[0][i] != -1) {
			d[nt[0][i]][1] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= i + 1; ++j) {
			if (d[i][j] == 0) {
				continue;
			}
			add(cnt[j], d[i][j]);
			int q = s[i] - 'a';
			for (int k = 0; k < 26; ++k) {
				if (k != q && nt[i + 1][k] != -1) {
					add(d[nt[i + 1][k]][j + 1], d[i][j]);
				}
			}
		}
	}

	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		res += (long long)(cnt[i]) * cnk(n - 1, i - 1);
		res %= (long long)(P);
	}

	printf("%d\n", (int)(res));

	//cerr << clock() << endl;


	return 0;
}