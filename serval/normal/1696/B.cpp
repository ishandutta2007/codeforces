#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

void solve()
{
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (a[i] && !a[i - 1])
			cnt++;
	sort(a + 1, a + n + 1);
	int mex = 0, mx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == mex)
			mex++;
		mx = max(mx, a[i]);
	}
	if (mx == 0)
	{
		printf("0\n");
		return;
	}
	if (mex == 0 || cnt == 1)
	{
		printf("1\n");
		return;
	}
	printf("2\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}