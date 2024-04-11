#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	if (a < b)
		swap(a, b);
	int c = (a - 1) / b;
	if (c > d)
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