#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10;
int t, n, a[N], b[N], aa[N], bb[N];
int sum = 0;
bool check(int x) {
	for (int i = 1; i <= n; i ++) bb[i] = b[i], aa[i] = a[i];
	aa[1] = x;
	for (int i = 1; i <= n; i ++) {
		bb[i] -= aa[i];
		//printf("i = %d\n", i);
		//printf("bb %d -> %d\n", bb[i] + aa[i], bb[i]);
		if (bb[i] < 0) return false;
		//printf("aa %d -> %d\n", aa[i], max(aa[i+1] - bb[i], 0));
		aa[i+1] -= bb[i]; aa[i + 1] = max(aa[i + 1], 0);
		if (i == n) sum = x + bb[i];
	}
	return true;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
		//check(2); return 0;
		int lef = 0, rig = b[1] + 1;
		while (rig - lef > 1) {
			int mid = (lef + rig) >> 1;
			if (check(mid)) lef = mid; else rig = mid;
		}
		//printf("lef = %d\n", lef);
		if (! check(lef)) {
			printf("NO\n"); continue;
		}
		if (sum < a[1]) {
			printf("NO\n"); continue;
		}
		printf("YES\n");
	}
}