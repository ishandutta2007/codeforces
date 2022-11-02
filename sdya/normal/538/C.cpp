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

const int maxN = 110000;
const int inf = 1000000000;
int n, m;
pair < int, int > a[maxN];

int calc(int length, int h1, int h2) {
	if (h1 > h2) {
		swap(h1, h2);
	}

	if (h1 + length < h2) {
		return inf;
	}
	return (length + h1 + h2) / 2; 
}

int calc(pair < int, int > a, pair < int, int > b) {
	return calc(b.first - a.first, a.second, b.second);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}

	int res = max(a[0].second + a[0].first - 1, a[m - 1].second + (n - a[m - 1].first));
	for (int i = 0; i + 1 < m; ++i) {
		int value = calc(a[i], a[i + 1]);
		res = max(res, value);
	}
	if (res == inf) {
		printf("IMPOSSIBLE\n");
	} else {
		printf("%d\n", res);
	}

	return 0;
}