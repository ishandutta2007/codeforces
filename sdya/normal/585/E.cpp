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

const int P = 1000000007;

const int maxN = 2000000;
const int maxL = 10100000;
int a[maxL];
int n;

bool p[maxL];
int primes[maxN], m;
long long p2[maxN];

void calc(int index, int p, int sign, int &res) {
	int value = ((p2[a[p] - 1] - 1) * (long long)(a[p])) % P;
	int v2 = ((long long)(value) + (long long)(n - a[p]) * (p2[a[p]] - 1)) % P;
	if (sign > 0) {
		res += value;
		if (res >= P) {
			res -= P;
		}

		res -= v2;
		if (res < 0) {
			res += P;
		}
	} else {
		res -= value;
		if (res < 0) {
			res += P;
		}

		res += v2;
		if (res >= P) {
			res -= P;
		}
	}

	if (index >= m) {
		return;
	}

	if ((long long)(primes[index]) * (long long)(p) >= maxL) {
		return;
	}

	for (int i = index; i < m && primes[i] * p < maxL; ++i) {
		calc(i + 1, primes[i] * p, -sign, res);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	p2[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		p2[i] = p2[i - 1] * 2;
		if (p2[i] >= P) {
			p2[i] -= P;
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		++a[x];
	}

	for (int i = 1; i < maxL; ++i) {
		for (int j = i + i; j < maxL; j += i) {
			a[i] += a[j];
		}
	}

	for (int i = 2; i * i < maxL; ++i) {
		if (!p[i]) {
			for (int j = i * i; j < maxL; j += i) {
				p[j] = true;
			}
		}
	}

	for (int i = 2; i < maxL; ++i) {
		if (!p[i]) {
			primes[m++] = i;
		}
	}

	int g = 1;
	for (int i = 2; i < maxL; ++i) {
		if (a[i] == n) {
			g = i;
		}
	}

	int res = 0;
	calc(0, 1, 1, res);

	printf("%d\n", res);

	cerr << clock() << endl;


	return 0;
}