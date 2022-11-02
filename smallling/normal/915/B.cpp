#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x, l, r;
	scanf("%d%d%d%d", &n, &x, &l, &r);
	if(l == 1 && r == n)
	{
		puts("0");
		return 0;
	}
	if(l == 1)
	{
		printf("%d\n", abs(x - r) + 1);
		return 0;
	}
	if(r == n)
	{
		printf("%d\n", abs(x - l) + 1);
		return 0;
	}
	printf("%d\n", min(abs(x - l), abs(x - r)) + 1 + r - l + 1);
}