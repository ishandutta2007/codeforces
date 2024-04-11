#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>

using namespace std;

const int N = 1e5 + 5;
const int B = 320;

int n;
int a[N];
long long b[N];
int ans;

int main()
{
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = 2;
	for (int i = -B; i <= B; i++)
	{
		for (int j = 1; j <= n; j++)
			b[j] = a[j] + 1ll * j * i;
		sort(b + 1, b + n + 1);
		for (int j = 1; j <= n; j++)
		{
			int k = j;
			while (k < n && b[j] == b[k + 1])
				k++;
			ans = max(ans, k - j + 1);
			j = k;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = max(i - B, 1); j <= min(i + B, n); j++)
			if (i != j)
				if ((a[j] - a[i]) % (j - i) == 0)
				{
					int d = (a[j] - a[i]) / (j - i);
					b[++cnt] = d;
				}
		sort(b + 1, b + cnt + 1);
		for (int j = 1; j <= cnt; j++)
		{
			int k = j;
			while (k < cnt && b[j] == b[k + 1])
				k++;
			ans = max(ans, k - j + 2);
			j = k;
		}
	}
	printf("%d\n", n - ans);
	return 0;
}