#include <stdio.h>
#include <algorithm>
using namespace std;

int a, b, st, en;

int tag(int k) {
	int rlt = (k - 1) / (a + b);
	if ((k - 1) % (a + b) < a) return rlt*2+1;
	return rlt*2+2;
}

int solve(int st, int en) {
	int u = tag(st), v = tag(en);
	if (v > u + 4) return max(a + 1, 2 * a - b);
	if (v == u) return u & 1 ? en - st + 1 : 1;
	if (v == u + 1) return u & 1 ? a - ((st - 1) % (a + b)) : ((en - 1) % (a + b)) + 2;
	if (v == u + 2) {
		int x = a - ((st - 1) % (a + b)), y = (en - 1) % (a + b) + 1;
		return u & 1 ? max(min(x + y, a), max(x, y + max(1, min(x, a - b)))) : a + 1;
	}
	return max(solve(a * (tag(st) & 1) + 1 + (a + b) * (tag(st) >> 1), en), solve(st, (a + b) * ((tag(en) - 1) >> 1) + a * ((tag(en) - 1) & 1)));
}

main() {
	scanf("%d%d%d%d", &a, &b, &st, &en);
	printf("%d\n", solve(st, en));
}