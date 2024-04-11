#include <bits/stdc++.h>

using namespace std;

int p[1000];

void solve() {
	for (int i = 0; i < 4; ++i) {
		scanf("%d", &p[i]);
	}
	if (max(p[0], p[1]) > min(p[2], p[3]) && max(p[2], p[3]) > min(p[0], p[1]))
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