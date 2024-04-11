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

const int maxN = 3100;
int n, p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}
	int m = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (p[i] > p[j]) {
				++m;
			}
		}
	}

	int res = 0;
	while (m > 1) {
		res += 4;
		m -= 2;
	}
	if (m == 1) {
		++res;
	}
	printf("%.10lf\n", (double)(res));


	return 0;
}