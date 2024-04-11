#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1005;
const int M = 26 * 26 * 26;

int n;
int a[N], b[N], c[N];
int sa, sb, sc;
int cnt[M], mapping[10];

char s[10];
int get()
{
	scanf("%s", s + 1);
	return (s[1] - 'a') * 26 * 26 + (s[2] - 'a') * 26 + (s[3] - 'a');
}

void solve()
{
	mapping[1] = 3;
	mapping[2] = 1;
	mapping[3] = 0;
	scanf("%d", &n);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++)
	{
		a[i] = get();
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] = get();
		cnt[b[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		c[i] = get();
		cnt[c[i]]++;
	}
	sa = sb = sc = 0;
	for (int i = 1; i <= n; i++)
	{
		sa += mapping[cnt[a[i]]];
		sb += mapping[cnt[b[i]]];
		sc += mapping[cnt[c[i]]];
	}
	printf("%d %d %d\n", sa, sb, sc);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}