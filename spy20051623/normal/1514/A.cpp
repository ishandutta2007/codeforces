#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	bool ok = false;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		int m = sqrt(k);
		if (m * m != k)
			ok = true;
	}
	if (!ok)
		printf("NO\n");
	else
		printf("YES\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}