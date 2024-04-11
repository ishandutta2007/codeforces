#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

int l, ans, last;

bool f[150];

char s[10000];

int main() {
	scanf("%s", s + 1);
	l = strlen(s + 1);
	f['A'] = f['E'] = f['I'] = f['O'] = f['U'] = f['Y'] = 1;
	last = 0;
	for (int i = 1; i <= l; i ++) {
		if (f[s[i]]) ans = max(ans, i - last), last = i;
	}
	ans = max(ans, l + 1 - last);
	printf("%d\n", ans);
	return 0;
}