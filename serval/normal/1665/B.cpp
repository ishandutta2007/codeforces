#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
int ans;

int calc(int len)
{
	int ret = 0;
	while (len < n)
	{
		ret++;
		ret += min(len * 2, n) - len;
		len *= 2;
	}
	return ret;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = n + n;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		int j = i;
		while (j < n && a[j + 1] == a[i])
			j++;
		int len = j - i + 1;
		ans = min(ans, calc(len));
		i = j;
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}