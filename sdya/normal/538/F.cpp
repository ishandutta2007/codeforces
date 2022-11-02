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

const int maxN = 210000;
const int maxD = 500;
int n;
int a[maxN];
int s[maxD][maxN];

int calc(int k) {
	int l = 2;
	int res = 0;
	for (int i = 1; i <= n && l <= n; ++i, l += k) {
		for (int j = l; j < l + k && j <= n; ++j) {
			res += (a[j] < a[i]);
		}
	}
	return res;
}

int calcClever(int k) {
	int l = 2;
	int res = 0;
	for (int i = 1; i <= n && l <= n; ++i, l += k) {
		res += s[i][min(n, l + k - 1)] - s[i][l - 1];
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n && i < maxD; ++i) {
		for (int j = i; j <= n; ++j) {
			s[i][j] = (a[j] < a[i]) + s[i][j - 1];
		}
	}

	for (int k = 1; k < n; ++k) {
		int res = 0;
		if (k < maxD) {
			res = calc(k);
		} else {
			res = calcClever(k);
		}
		printf("%d ", res);
	}
	printf("\n");

	return 0;
}