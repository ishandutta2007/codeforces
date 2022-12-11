#include <bits/stdc++.h>
using namespace std;

vector <int> all;

int main () {
	for (int i = 1; 1ll * i * i <= 2000000000; i++) {
		long long x = 1ll * i * i;
		if (x & 1) all.push_back(x + 1 >> 1);
	}
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int pos = upper_bound(all.begin(), all.end(), n) - all.begin();
		printf("%d\n", pos - 1);
	}
	return 0;
}