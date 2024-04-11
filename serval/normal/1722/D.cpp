#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int n;
char s[N];
int v[N];
long long ans;

void solve()
{
	scanf("%d", &n);
	scanf("%s", s + 1);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'L')
		{
			ans += i - 1;
			v[i] = max(0, (n - i) - (i - 1));
		}
		else
		{
			ans += n - i;
			v[i] = max(0, (i - 1) - (n - i));
		}
	}
	sort(v + 1, v + n + 1);
	for (int i = n; i; i--)
	{
		ans += v[i];
		printf("%lld%c", ans, " \n"[i == 1]);
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