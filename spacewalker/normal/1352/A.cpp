#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<int> digs;
		while (n > 0) {
			digs.push_back(n % 10);
			n /= 10;
		}
		int multiplier = 1;
		vector<int> ans;
		for (int k : digs) {
			if (k > 0) ans.push_back(k * multiplier);
			multiplier *= 10;
		}
		printf("%lu\n", ans.size());
		for (int k : ans) printf("%d ", k);
		printf("\n");
	}
	return 0;
}