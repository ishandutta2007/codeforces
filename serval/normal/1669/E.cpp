#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 13;

int n;
int cnt[N][N];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cnt[i][j] = 0;
	for (int i = 1; i <= n; i++)
	{
		char s[5];
		scanf("%s", s);
		cnt[s[0] - 'a'][s[1] - 'a']++;
	}
	long long ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
			{
				if (j != k)
					ans += 1ll * cnt[i][j] * cnt[i][k];
				if (i != k)
					ans += 1ll * cnt[i][j] * cnt[k][j];
			}
	ans /= 2;
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}