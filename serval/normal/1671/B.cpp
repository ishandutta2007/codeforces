#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (a[n] - a[1] + 1 <= n + 2)
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