#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
long long ans;

void solve()
{
	scanf("%d", &n);
	ans = n + (n / 3) * 2 + (n / 2) * 2;
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