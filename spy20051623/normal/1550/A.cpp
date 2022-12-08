#include <bits/stdc++.h>

using namespace std;

void solve() {
	int s;
	scanf("%d", &s);
	for (int i = 0; i < 9999; ++i) {
		if (i * i >= s) {
			printf("%d\n", i);
			return;
		}
	}
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