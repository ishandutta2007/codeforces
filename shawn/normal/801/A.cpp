#include <cstdio>
#include <string.h>

using namespace std;

int n, ans;
bool fg, v[110];
char s[110];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 2; i <= n; i ++) {
		if (v[i - 1] || v[i]) continue;
		if (s[i - 1] == 'V' && s[i] == 'K') ans ++, v[i - 1] = v[i] = 1;
	}
	for (int i = 2; i <= n; i ++) {
		if (v[i - 1] || v[i]) continue;
		if (s[i - 1] == 'V' || s[i] == 'K') fg = 1;
		if (fg) break;
	}
	printf("%d", ans + fg);
	return 0;
}