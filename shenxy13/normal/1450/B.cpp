#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, k;
		scanf("%d %d", &n, &k);
		int x[n], y[n];
		for (int i = 0; i < n; ++i) scanf("%d %d", &x[i], &y[i]);
		bool must = false;
		for (int i = 0; i < n; ++i) {
			bool can = true;
			for (int j = 0; j < n; ++j) {
				if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) can = false;
			}
			if (can) must = true;
		}
		printf(must ? "1\n" : "-1\n");
	}
	return 0;
}