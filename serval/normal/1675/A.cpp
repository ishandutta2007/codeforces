#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;

int a, b, c, x, y;

void solve()
{
	scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
	int d;
	d = min(a, x);
	a -= d, x -= d;
	d = min(b, y);
	b -= d, y -= d;
	d = min(c, x);
	c -= d, x -= d;
	d = min(c, y);
	c -= d, y -= d;
	if (x + y == 0)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}