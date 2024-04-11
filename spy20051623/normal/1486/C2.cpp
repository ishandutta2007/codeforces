#include <bits/stdc++.h>

using namespace std;

int qry(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int s = qry(1, n);
	int a, l, r, ans;
	if (s == 1) {
		l = 2, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			a = qry(s, mid);
			if (a == s) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
	} else {
		a = qry(1, s);
		if (a == s) {
			l = 1, r = s - 1;
			while (l <= r) {
				int mid = (l + r) >> 1;
				a = qry(mid, s);
				if (a == s) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
		} else {
			l = s + 1, r = n;
			while (l <= r) {
				int mid = (l + r) >> 1;
				a = qry(s, mid);
				if (a == s) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
		}
	}
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}