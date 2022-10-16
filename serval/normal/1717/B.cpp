#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, k, r, c;
int tar;

void solve()
{
	scanf("%d%d%d%d", &n, &k, &r, &c);
	tar = (r + c) % k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%c", ".X"[(i + j) % k == tar]);
		printf("\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}