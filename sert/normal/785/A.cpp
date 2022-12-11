#include <cstdio>

int main() {
	int n, ans = 0;
	char s[20];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		if (s[0] == 'T') ans += 4;
		if (s[0] == 'C') ans += 6;
		if (s[0] == 'O') ans += 8;
		if (s[0] == 'D') ans += 12;
		if (s[0] == 'I') ans += 20;
	}
	printf("%d\n", ans);
	return 0;
}