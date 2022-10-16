#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[10];

void solve()
{
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int v;
		scanf("%d", &v);
		a[v % 10]++;
	}
	for (int i = 0; i < 10; i++)
		if (a[i])
		{
			a[i]--;
			for (int j = 0; j < 10; j++)
				if (a[j])
				{
					a[j]--;
					for (int k = 0; k < 10; k++)
						if (a[k])
							if ((i + j + k) % 10 == 3)
							{
								printf("YES\n");
								return;
							}
					a[j]++;
				}
			a[i]++;
		}
	printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}