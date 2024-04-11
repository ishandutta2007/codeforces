#include <bits/stdc++.h>

using namespace std;

int rd() {
	char c = getchar(); int x = 0, f = 1;
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

int main() {
	int l = rd(), r = rd(), x = rd(), y = rd(), k = rd();
	for (int i = x; i <= y; i ++) {
		long long t = 1ll * i * k;
		if (l <= t && t <= r) return puts("YES"), 0;
	}
	puts("NO");
}