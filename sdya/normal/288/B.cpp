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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 1000000007LL;

long long powmod(long long a, long long n) {
	if (n == 0) {
		return 1LL % P;
	}
	long long b = powmod(a, n / 2);
	b = (b * b) % P;
	if (n % 2 == 1) {
		b = (b * a) % P;
	}
	return b;
}

const int maxN = 10;
int n, k;
int p[maxN];
long long res = 0;
int used[maxN];

bool check() {
	for (int i = 1; i <= k; ++i) {
		used[i] = 0;
	}
	for (int i = 1; i <= k; ++i) {
		if (used[i]) {
			continue;
		}
		int j = i;
		while (!used[j]) {
			used[j] = i;
			j = p[j];
		}
		if (i == 1) {
			if (j != 1) {
				return false;
			}
			continue;
		}
		if (used[j] == i) {
			return false;
		}
	}
	return true;
}

void rec(int have) {
	if (have == k) {
		if (check()) {
			++res;
		}
		return ;
	}
	for (int i = 1; i <= k; ++i) {
		p[have + 1] = i;
		rec(have + 1);
	}
}

int a[10];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	a[1] = 1;
	a[2] = 2;
	a[3] = 9;
	a[4] = 64;
	a[5] = 625;
	a[6] = 7776;
	a[7] = 117649;
	a[8] = 2097152;

	scanf("%d%d", &n, &k);
	long long coef = powmod(n - k, n - k);
	coef *= (long long)(a[k]);
	coef %= P;
	printf("%d\n", (int)(coef));


	return 0;
}