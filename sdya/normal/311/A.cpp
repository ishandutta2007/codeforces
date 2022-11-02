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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);
	vector < int > x(n), y(n);
	for (int i = 0; i < n; ++i) {
		x[i] = 0;
		y[i] = i;
	}

	int d = 1000000000;
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			++tot;
			if (x[j] - x[i] >= d) {
				break;
			}
			d = min(d, y[j] - y[i]);
		}
	}

	if (tot > k) {
		for (int i = 0; i < n; ++i) {
			printf("%d %d\n", x[i], y[i]);
		}
	} else {
		printf("no solution\n");
	}

	return 0;
}