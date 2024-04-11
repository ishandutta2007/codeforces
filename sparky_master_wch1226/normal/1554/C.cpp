#include <bits/stdc++.h>

int t, n, m;

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int r = 0;
		for (int i = 30; i >= 0; --i) if ((r ^ n | (1 << i) - 1) <= m) r |= 1 << i;
		printf("%d\n", r);
	}
	return 0;
}