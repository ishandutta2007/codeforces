#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int a, b, c, d;

void solve()
{
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", (b>a) + (c>a) + (d>a));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}