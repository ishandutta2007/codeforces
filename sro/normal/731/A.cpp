#include <bits/stdc++.h>

int main() {
	char last = 'a', c = getchar();
	int ans = 0;
	while (c >= 'a') {
		ans += std::min(abs(last-c), 26-abs(last-c));
		last = c;
		c = getchar();
	}
	printf("%d\n", ans);
	return 0;
}