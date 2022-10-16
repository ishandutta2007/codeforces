#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e6 + 5;

int n;
char s[N];

vector <int> factors[N];
int cnt[N];

long long ans;

void pre()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
			factors[j].emplace_back(i);
	}
}

void solve()
{
	ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cnt[i] = 0;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '1')
		{
			for (auto j : factors[i])
				cnt[j]++;
		}
		else
		{
			for (auto j : factors[i])
			{
				if (!cnt[j])
				{
					ans += j;
					break;
				}
			}
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	pre();
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}