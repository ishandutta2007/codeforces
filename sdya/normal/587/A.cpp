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

const int maxN = 1100000;
int n, a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int w;
		scanf("%d", &w);
		++a[w];
	}

	for (int i = 0; i + 1 < maxN; ++i) {
		if (a[i] > 1) {
			int k = a[i] / 2;
			a[i] -= k * 2;
			a[i + 1] += k;
		}
	}
	int res = 0;
	for (int i = 0; i < maxN; ++i) {
		res += a[i];
	}
	printf("%d\n", res);

	return 0;
}