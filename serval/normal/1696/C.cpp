#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, m, k;
int a[N], b[N];
int v[N], cnt;
long long l[N];

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &b[i]);
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int cur = a[i], len = 1;
		while (cur % m == 0)
			cur /= m, len *= m;
		if (cur != v[cnt])
		{
			v[++cnt] = cur;
			l[cnt] = 0;
		}
		l[cnt] += len;
	}
	for (int i = k; i; i--)
	{
		int cur = b[i], len = 1;
		while (cur % m == 0)
			cur /= m, len *= m;
		if (!cnt || v[cnt] != cur || l[cnt] < len)
		{
			printf("No\n");
			return;
		}
		l[cnt] -= len;
		if (!l[cnt])
			cnt--;
	}
	if (cnt)
		printf("No\n");
	else
		printf("Yes\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}