#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b;
	scanf("%d%d", &a, &b);
	if (abs(a - b) % 2) printf("-1\n");
	else if (!a && !b) printf("0\n");
	else if (abs(a) == abs(b)) printf("1\n");
	else printf("2\n");
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