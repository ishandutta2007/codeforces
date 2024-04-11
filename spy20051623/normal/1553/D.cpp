#include <bits/stdc++.h>

using namespace std;

char s[200005], u[200005];

void solve() {
	scanf("%s%s", s, u);
	int n = strlen(s), m = strlen(u);
	int p = n - 1, q = m - 1;
	while (q >= 0) {
		while (s[p] != u[q]) {
			p -= 2;
			if (p < 0) {
				printf("NO\n");
				return;
			}
		}
		--q;
		--p;
	}
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