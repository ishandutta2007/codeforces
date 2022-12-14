#include <bits/stdc++.h>
using namespace std;

int n, x, y, z, m, t;

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &m);
	assert(n);
	assert(m);
	int tot = 0;
	x = 4 * n;
	for (int i = 1, a; i <= m; i ++) {
		scanf("%d", &a);
		tot += a;
		t += a / 4;
		x -= 2 * (a / 4);
		a %= 4;
        if (a == 3) x -= 2, t ++;
        else if (a == 2) z ++, x --;
        else if (a == 1) y ++, x --;
	}//printf("%d %d %d\n", x, y, z);
	//assert(x + y + z ==
	assert(tot <= 8 * n);
    if (tot < n || x < 0) {
		puts("NO");
		return 0;
    }
    if (t < n && x + y < n - t) {
		bool flag = 0;
		while (x > 0) {
			x --;
			z --;
			y += 2;
			if (x + y >= n - t) flag = 1;
		}
		if (flag) puts("YES");
		else puts("NO");
    }
    else puts("YES");

	return 0;
}