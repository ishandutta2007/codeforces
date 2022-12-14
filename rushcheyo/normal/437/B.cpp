#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sum, limit;
	static int ans[100005], n;
	scanf("%d%d", &sum, &limit);
	for (int i = 16; i >= 0; i--)
		for (int a = 1; a << i <= limit && 1 << i <= sum; a += 2)
			ans[++n] = a << i, sum -= 1 << i;
	if (sum > 0) puts("-1");
	else
	{
		printf("%d\n", n);
		for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}