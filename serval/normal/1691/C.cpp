#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, k;
char s[N];
int ans;

void solve()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int f1 = n + 1, l1 = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1')
		{
			f1 = min(f1, i);
			l1 = max(l1, i);
		}
	if (l1)
		if (n - l1 <= k)
		{
			k -= n - l1;
			swap(s[n], s[l1]);
		}
	if (f1 < n && s[f1] == '1')
		if (f1 - 1 <= k)
		{
			k -= f1 - 1;
			swap(s[1], s[f1]);
		}
	ans = 0;
	for (int i = 2; i < n; i++)
		ans += (s[i] - '0') * 11;
	ans += (s[1] - '0') * 10;
	ans += (s[n] - '0') * 1;
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