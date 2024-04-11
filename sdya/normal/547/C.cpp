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
#include <complex>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 510000;
int n, q;
int a[maxN];
int p[maxN], m;
int d[maxN], cntd, cd[maxN];
int dd[maxN], cntdd;

int c[maxN];

bool used[maxN];

bool isPrime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void getDivisors(int n) {
	cntd = 0;
	for (int i = 0; i < m; ++i) {
		int q = 0;
		while (n % p[i] == 0) {
			++q;
			n /= p[i];
		}
		if (q > 0) {
			cd[cntd] = q;
			d[cntd++] = p[i];
		}
	}
	if (n > 1) {
		cd[cntd] = 1;
		d[cntd++] = n;
	}
}

void rec(int index, int value) {
	if (index == cntd) {
		dd[cntdd++] = value;
		return;
	}

	for (int i = 0; i <= cd[index]; ++i) {
		rec(index + 1, value);
		value *= d[index];
	}
}

void getAllDivisors(int n) {
	cntdd = 0;
	rec(0, 1);
}

void add(int x, long long &res) {
	getDivisors(a[x]);

	for (int i = 0; i < (1 << cntd); ++i) {
		int t = 0, value = 1;
		for (int j = 0; j < cntd; ++j) {
			if (i & (1 << j)) {
				++t;
				value *= d[j];
			}
		}
		if (t % 2 == 0) {
			res += c[value];
		} else {
			res -= c[value];
		}
	}
	getAllDivisors(a[x]);
	for (int j = 0; j < cntdd; ++j) {
		++c[dd[j]];
	}
}

void rem(int x, long long &res) {
	getDivisors(a[x]);
	getAllDivisors(a[x]);
	for (int j = 0; j < cntdd; ++j) {
		--c[dd[j]];
	}

	for (int i = 0; i < (1 << cntd); ++i) {
		int t = 0, value = 1;
		for (int j = 0; j < cntd; ++j) {
			if (i & (1 << j)) {
				++t;
				value *= d[j];
			}
		}
		if (t % 2 == 0) {
			res -= c[value];
		} else {
			res += c[value];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 2; i <= 1000; ++i) {
		if (isPrime(i)) {
			p[m++] = i;
		}
	}

	long long res = 0;
	for (int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		if (!used[x]) {
			used[x] = true;
			add(x, res);
		} else {
			used[x] = false;
			rem(x, res);
		}
		printf("%I64d\n", res);
	}



	return 0;
}