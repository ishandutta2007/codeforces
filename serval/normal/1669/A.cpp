#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

void solve()
{
	int r;
	scanf("%d", &r);
	int ans = 1;
	if (r < 1900)
		ans++;
	if (r < 1600)
		ans++;
	if (r < 1400)
		ans++;
	printf("Division %d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}