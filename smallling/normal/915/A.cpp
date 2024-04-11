#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, ans = 1e9;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		int o;
		scanf("%d", &o);
		if(k % o == 0)ans = min(ans, k / o);
	}
	printf("%d\n", ans);
}