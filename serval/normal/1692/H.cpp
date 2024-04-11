#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
map <int, int> las;
int f[N], l[N];
int ans;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		las[a[i]] = 0;
	}
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;
		l[i] = i;
		if (las[a[i]] > 0)
		{
			int ll = las[a[i]];
			if (f[ll] - (i - ll - 1) + 1 > f[i])
			{
				f[i] = f[ll] - (i - ll - 1) + 1;
				l[i] = l[ll];
			}
		}
		if (f[i] > f[ans])
			ans = i;
		las[a[i]] = i;
	}
	printf("%d %d %d\n", a[ans], l[ans], ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}