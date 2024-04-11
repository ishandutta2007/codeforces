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

const int maxN = 210000;
int n, a[maxN], l[maxN], r[maxN];
int res[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			l[i] = i;
			continue;
		}
		int j = i - 1;
		while (j >= 0 && a[j] >= a[i]) {
			j = l[j] - 1;
		}
		l[i] = j + 1;
	}

	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1) {
			r[i] = i;
			continue;
		}
		int j = i + 1;
		while (j < n && a[j] >= a[i]) {
			j = r[j] + 1;
		}
		r[i] = j - 1;
	}

	for (int i = 0; i < n; ++i) {
		res[r[i] - l[i] + 1] = max(res[r[i] - l[i] + 1], a[i]);
	}

	for (int i = n - 1; i >= 0; --i) {
		res[i] = max(res[i], res[i + 1]);
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d ", res[i]);
	}
	printf("\n");


	return 0;
}