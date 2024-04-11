#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	set<int> fValues;
	vector<int> latestApp(20, -1);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		for (int k = 0; k < 20; ++k) {
			if ((x & (1 << k)) > 0) latestApp[k] = i;
		}
		map<int, int> adder;
		for (int b = 0; b < 20; ++b) {
			if (latestApp[b] > -1) {
				adder[-latestApp[b]] |= (1 << b);
				// printf("bit %d app %d\n", b, latestApp[b]);
			}
		}
		int cur = 0;
		for (auto pp : adder) {
			cur |= pp.second;
			fValues.insert(cur);
			// printf("dval %d %d\n", i, cur);
		}
		if (x == 0) fValues.insert(0);
	}
	printf("%lu\n", fValues.size());
	return 0;
}