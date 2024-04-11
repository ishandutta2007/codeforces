#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int d[maxN];
int n, a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		vector < int > b;
		for (int j = 1; j * j <= a[i]; ++j) {
			if (a[i] % j == 0) {
				if (j != 1) {
					b.push_back(j);
				}
				if (a[i] / j != 1) {
					b.push_back(a[i] / j);
				}
			}
		}

		int current = 0;
		for (int j = 0; j < b.size(); ++j) {
			current = max(current, d[b[j]]);
		}
		++current;
		res = max(res, current);

		for (int j = 0; j < b.size(); ++j) {
			d[b[j]] = max(d[b[j]], current);
		}
	}

	printf("%d\n", res);

	return 0;
}