#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = max({max(0, abs(b - c) - a + 1), max(0, abs(a - c) - b + 1), max(0, abs(a - b) - c + 1)});
	printf("%d\n", ans);
	return 0;
}