#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3e5 + 5;

int n;
int deg[N];

int check(int mid)
{
	int sum = 0;
	for (int i = n, j = mid - 1; i; i--, j--)
		if (deg[i])
			sum += max(deg[i] - max(j, 0), 1);
	return sum + 1 <= mid;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		deg[i] = 0;
	for (int i = 2; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		deg[p]++;
	}
	sort(deg + 1, deg + n + 1);
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", l);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}