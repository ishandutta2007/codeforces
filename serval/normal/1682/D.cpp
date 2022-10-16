#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n;
char a[N];
int b[N], bt;
int u[N], v[N], t;

void ae(int x, int y)
{
	x = (x - 1) % n + 1;
	y = (y - 1) % n + 1;
	t++;
	u[t] = x;
	v[t] = y;
}

void solve()
{
	scanf("%d", &n);
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++)
		a[n + i] = a[i];
	int c1 = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == '1')
		{
			c1 = i;
			break;
		}
	if (!c1)
	{
		printf("NO\n");
		return;
	}
	t = 0;
	bt = 0;
	for (int i = c1; i < c1 + n; i++)
	{
		if (a[i + 1] == '0')
		{
			ae(i, i + 1);
			continue;
		}
		else
			b[++bt] = i;
	}
	if (bt & 1)
	{
		printf("NO\n");
		return;
	}
	for (int i = 2; i <= bt; i++)
		ae(b[1], b[i]);
	printf("YES\n");
	for (int i = 1; i <= t; i++)
		printf("%d %d\n", u[i], v[i]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}