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
const int inf = 1000000000;
int n, a[maxN], d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	d[0] = -inf;
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
	}
	for (int i=0; i<n; i++) {
		int j = upper_bound (d, d + n + 1, a[i]) - d;
		if (d[j-1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
		}
	}

	for (int i = n; i >= 1; --i) {
		if (d[i] < inf) {
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}