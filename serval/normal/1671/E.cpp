#include <cstdio>
#include <algorithm>

using namespace std;

const int N = (1 << 18) + 5;
const int mod = 998244353;

int n;
int l[N], r[N];
char s[N];
int ans;

int cmp(int u, int v)
{
	if (s[u] != s[v])
		return s[u] - s[v];
	if (!u || !v)
		return 0;
	int c = cmp(l[u], l[v]);
	if (c)
		return c;
	return cmp(r[u], r[v]);
}

int main()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i < (1 << n - 1); i++)
	{
		l[i] = 2 * i;
		r[i] = 2 * i + 1;
	}
	ans = 1;
	for (int i = (1 << n - 1) - 1; i; i--)
	{
		int c = cmp(l[i], r[i]);
		if (c == 0)
			continue;
		ans = ans * 2 %mod;
		if (c >= 1)
			swap(l[i], r[i]);
	}
	printf("%d\n", ans);
	return 0;
}