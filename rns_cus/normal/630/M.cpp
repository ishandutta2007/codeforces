#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b) {
	return min(abs(a - b), 360 - abs(a - b));
}

long long d;

int main() {
//	freopen("m.in", "r", stdin);
	scanf("%I64d", &d);
	d = (d % 360 + 360) % 360;
	int ans = 1000;
	for (int i = 0; i < 4; i ++) ans = min(ans, dist(d, 90 * i));
	for (int i = 0; i < 4; i ++) {
		if (dist(d, 90 * i) == ans) {
			printf("%d\n", i); return 0;
		}
	}
	return 0;
}