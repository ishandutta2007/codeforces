#include <bits/stdc++.h>
using namespace std;

bool ok(int a) {
	for (int i = 3; i <= 360; i ++) {
		if (i * a == (i - 2) * 180) return 1;
	}
	return 0;
}

int t, a;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &a);
		if (ok(a)) puts("YES");
		else puts("NO");
	}
	return 0;
}