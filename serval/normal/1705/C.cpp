#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, c, q;
char s[N];
long long l[N], r[N];
long long len[N];

char get(long long k)
{
	if (k <= n)
		return s[k];
	int id = lower_bound(len + 1, len + c + 1, k) - len;
	k = k - len[id - 1] + l[id] - 1;
	return get(k);
}

void solve()
{
	scanf("%d%d%d", &n, &c, &q);
	scanf("%s", s + 1);
	len[0] = n;
	for (int i = 1; i <= c; i++)
	{
		scanf("%lld%lld", &l[i], &r[i]);
		len[i] = len[i - 1] + r[i] - l[i] + 1;
	}
	while (q--)
	{
		long long k;
		scanf("%lld", &k);
		printf("%c\n", get(k));
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