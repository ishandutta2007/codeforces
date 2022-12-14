#include <stdio.h>
#include <string.h>

int main() {
//	freopen("a.in", "r", stdin);
	int n, ans = 1, gas = 0;
	char s[100100];
	scanf("%d %s", &n, s);
	for (int i = 1; i < n; i ++) {
		if (s[i] != s[i-1]) ans ++;
		else gas ++;
	}
	if (gas >= 2) ans += 2;
	else ans += gas;
	printf("%d\n", ans);
	return 0;
}