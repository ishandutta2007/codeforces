#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 1e5 + 5;
const int p = 26;

int n;
char s[N][10];
int len[N];
set <long long> hv[10];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		hv[i].clear();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
		len[i] = strlen(s[i] + 1);
		long long h = 0;
		for (int j = 1; j <= len[i]; j++)
			h = h * p + s[i][j] - 'a';
		hv[len[i]].insert(h);
	}
	for (int i = 1; i <= n; i++)
	{
		if (len[i] == 1)
		{
			printf("0");
			continue;
		}
		long long lh = 0;
		int chk = 0;
		for (int j = 1; j < len[i]; j++)
		{
			long long rh = 0;
			lh = lh * p + s[i][j] - 'a';
			for (int k = j + 1; k <= len[i]; k++)
				rh = rh * p + s[i][k] - 'a';
			if (hv[j].count(lh) && hv[len[i] - j].count(rh))
			{
				chk = 1;
				break;
			}
		}
		printf("%d", chk);
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}