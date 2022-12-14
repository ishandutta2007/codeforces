#include <bits/stdc++.h>

using namespace std;

int c, v0, v1, a, l;
int main() {
	scanf("%d%d%d%d%d", &c, &v0, &v1, &a, &l);
	int now = v0, ans = 1;
	while (true) {
		if (now >= c) break;
		v0 += a;
		now += min(v0, v1) - l;
		ans ++;
	}
	printf("%d\n", ans);
}