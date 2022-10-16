#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3e5 + 5;

int ans;

int query(int a, int b)
{
	int ret;
	printf("? %d %d\n", a, b);
	fflush(stdout);
	scanf("%d", &ret);
	return ret;
}

void solve()
{
	ans = 0;
	for (int i = 0; i < 30; i++)
	{
		int curbit = 1 << i;
		if (ans == 0)
		{
			if (query(curbit, 3 * curbit) != curbit)
				ans |= curbit;
		}
		else
		{
			if (query(curbit - ans, 3 * curbit - ans) != curbit)
				ans |= curbit;
		}
	}
	printf("! %d\n", ans);
	fflush(stdout);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}