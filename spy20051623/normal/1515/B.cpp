#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	if (n % 2) {
		printf("NO\n");
		return;
	}
	while (n % 2 == 0) {
		n /= 2;
	}
	int k = sqrt(n);
	if (k * k == n)
		printf("YES\n");
	else
		printf("NO\n");
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