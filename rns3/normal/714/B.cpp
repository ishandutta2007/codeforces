#include <stdio.h>

int main() {
	char ans[2][4] = {"NO", "YES"};
	int n, a = -1, b = -1, c = -1, d, tag = 1;
	scanf("%d", &n);
	while (n --) {
		scanf("%d", &d);
		if(a < 0 || a == d) a = d;
		else if (b < 0 || b == d) b = d;
		else if (c < 0 || c == d) c = d;
		else tag = 0;
	}
	if (tag && c >= 0) {
        if (a + c != 2 * b && a + b != 2 * c && b + c != 2 * a) tag = 0;
	}
	puts(ans[tag]);
	return 0;
}