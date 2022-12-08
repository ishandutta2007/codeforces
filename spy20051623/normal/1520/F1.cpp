#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

void ans(int x) {
	printf("! %d\n", x);
	fflush(stdout);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, t;
	scanf("%d%d", &n, &t);
	while (t--) {
		int l = 1;
		int r = n;
		int k;
		scanf("%d", &k);
		while (r != l) {
			int m = (l + r) >> 1;
			int p = ask(l, m);
			if ((m - l + 1) - p < k) {
				k -= (m - l + 1) - p;
				l = m + 1;
			} else {
				r = m;
			}
		}
		ans(l);
	}
	return 0;
}