#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;

int n, a[maxN];
long long add[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	long long score = 0;
	for (int i = 1; i < n; ++i) {
		int length = n - i;
		for (int j = 30; j >= 0; --j)
			if (length & (1 << j)) {
				score += (long long)(a[i]);
				a[i + (1 << j)] += a[i];
				break;
			}
		printf("%I64d\n", score);
	}
	return 0;
}