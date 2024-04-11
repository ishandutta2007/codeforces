#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 2005
#define ll long long
using namespace std;
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	ll ans = 0;
	for(int i = 1; i <= m && i <= n; i++)
		for(int j = 1; j <= m && j <= n; j++)
		{
			if((i * i + j * j) % m) continue;
			int n1 = (n - i) / m + 1, n2 = (n - j) / m + 1;
			ans += 1ll * n1 * n2;
		}
	printf("%lld\n", ans);
	return 0;
}