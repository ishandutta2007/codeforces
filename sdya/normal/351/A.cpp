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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5000;
int x[maxN], y[maxN];
int n;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int sx = 0, zeroes = 0, ones = 0;
	for (int i = 0; i < 2 * n; ++i) {
		int u, v;
		scanf("%d.%d", &u, &v);
		if (v == 0) {
			++zeroes;
		} else {
			sx += v;
			++ones;
		}
	}

	int best = 1000000000;
	for (int i = 0; i <= zeroes; ++i) {
		int j = n - i;
		if (j < 0 || j > ones) {
			continue;
		}

		int score = sx - j * 1000;
		best = min(best, abs(score));
	}
	printf("%d.%03d\n", best / 1000, best % 1000);

	return 0;
}