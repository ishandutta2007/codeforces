#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N], b[N], p[N];

bool cmp(int x, int y)
{
	if (a[x] == a[y])
		return x < y;
	return a[x] < a[y];
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		p[i] = i;
	}
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		int r = i;
		while (r < n && a[p[i]] == a[p[r + 1]])
			r++;
		if (i == r)
		{
			printf("-1\n");
			return;
		}
		for (int j = i; j < r; j++)
			b[p[j]] = p[j + 1];
		b[p[r]] = p[i];
		i = r;
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", b[i], " \n"[i == n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}