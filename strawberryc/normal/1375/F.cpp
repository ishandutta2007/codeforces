#include <bits/stdc++.h>

typedef long long ll;

ll a[4], b[4];

void orz() {b[1] = a[1]; b[2] = a[2]; b[3] = a[3]; std::sort(b + 1, b + 4);}

int main()
{
	int x;
	std::cin >> a[1] >> a[2] >> a[3];
	puts("First"); fflush(stdout); orz();
	do printf("%lld\n", b[3] * 2 - b[1] - b[2]), fflush(stdout),
		scanf("%d", &x), a[x] += b[3] * 2 - b[1] - b[2];
			while (orz(), b[1] + b[3] != b[2] * 2);
	printf("%lld\n", (orz(), b[2] - b[1])); fflush(stdout);
	if (scanf("%d", &x), !x) return 0;
	return 0;
}