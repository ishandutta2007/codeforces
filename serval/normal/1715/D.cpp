#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const int Q = 2e5 + 5;

int n, q;
int mask[N];
int h[N], to[Q], nx[Q], lim[Q];
int ans[N];

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		mask[i] = (1 << 30) - 1;
	for (int i = 1; i <= q; i++)
	{
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		if (u > v)
			swap(u, v);
		if (u == v)
		{
			mask[u] &= x;
			ans[u] |= x;
			continue;
		}
		to[i] = v;
		nx[i] = h[u];
		h[u] = i;
		lim[i] = x;
		mask[u] &= x;
		mask[v] &= x;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = h[i]; j; j = nx[j])
			ans[i] |= lim[j] ^ (lim[j] & mask[to[j]]);
		for (int j = h[i]; j; j = nx[j])
			ans[to[j]] |= lim[j] ^ (lim[j] & ans[i]);
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}