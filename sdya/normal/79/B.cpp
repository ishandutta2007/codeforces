#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int n, m, k, t;
vector < int > a[maxN];
int start[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &k, &t);
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; ++i) {
		sort(a[i].begin(), a[i].end());
	}

	int current = 0;
	start[1] = current;
	for (int i = 1; i + 1 <= n; ++i) {
		current += m - a[i].size();
		current %= 3;
		start[i + 1] = current;
	}

	for (int i = 0; i < t; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (binary_search(a[x].begin(), a[x].end(), y)) {
			printf("Waste\n");
			continue;
		}

		int missed = upper_bound(a[x].begin(), a[x].end(), y) - a[x].begin();
		int value = (start[x] + (y - missed - 1)) % 3;
		if (value == 0) {
			printf("Carrots\n");
		} else if (value == 1) {
			printf("Kiwis\n");
		} else {
			printf("Grapes\n");
		}
	}

	return 0;
}