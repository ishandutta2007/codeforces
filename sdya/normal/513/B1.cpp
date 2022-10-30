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

int calc(vector < int > a) {
	int n = a.size();
	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int x = n;
			for (int k = i; k <= j; ++k) {
				x = min(x, a[k]);
			}
			res += x;
		}
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}
	int res = 0;
	do {
		res = max(res, calc(a));
		/*for (int i = 0; i < n; ++i) {
			printf("%d, ", a[i]);
		}
		printf(": %d\n", calc(a));*/
	} while (next_permutation(a.begin(), a.end()));

	sort(a.begin(), a.end());
	do {
		if (calc(a) == res) {
			--m;
		}
		if (m == 0) {
			for (int i = 0; i < a.size(); ++i) {
				printf("%d ", a[i]);
			}
			printf("\n");
			return 0;
		}
	} while (next_permutation(a.begin(), a.end()));

	return 0;
}