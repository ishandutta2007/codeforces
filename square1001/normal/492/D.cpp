#include <cstdio>
int q, x, y, a;
int main() {
	scanf("%d %d %d", &q, &x, &y);
	while (q--) {
		scanf("%d", &a);
		long long pos = 0;
		for (int i = 59; i >= 0; i--) {
			long long val = pos + (1LL << i);
			if (val / x + val / y < a) pos = val;
		}
		pos++;
		if (pos % x != 0) printf("Vanya\n");
		else if (pos % y != 0)  printf("Vova\n");
		else printf("Both\n");
	}
	return 0;
}