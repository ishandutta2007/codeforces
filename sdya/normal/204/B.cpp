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
int n, a[maxN], b[maxN];

map < int, int > A, B;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	vector < int > current;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		current.push_back(a[i]);
		current.push_back(b[i]);

		++A[a[i]];
		if (b[i] != a[i]) {
			++B[b[i]];
		}
	}

	int res = 1000000000;
	for (int i = 0; i < current.size(); ++i) {
		int x = A[current[i]];
		int y = B[current[i]];
		if (2 * (x + y) >= n) {
			if (2 * x >= n) {
				res = min(res, 0);
				continue;
			}
			int z = (n - 2 * x + 1) / 2;
			res = min(res, z);
		}
	}
	if (res == 1000000000) {
		res = -1;
	}
	printf("%d\n", res);


	return 0;
}