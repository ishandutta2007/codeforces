#include <bits/stdc++.h>

using namespace std;

void solve() {
	int l, r;
	scanf("%d%d", &l, &r);
	if (l > r * 0.5) printf("YES\n");
	else printf("NO\n");
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