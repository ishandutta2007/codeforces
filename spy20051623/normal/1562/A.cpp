#include <bits/stdc++.h>

using namespace std;

void solve() {
	int l, r;
	scanf("%d%d", &l, &r);
	if (l * 2 <= r) printf("%d\n", r & 1 ? r - r / 2 - 1 : r / 2 - 1);
	else printf("%d\n", r - l);
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