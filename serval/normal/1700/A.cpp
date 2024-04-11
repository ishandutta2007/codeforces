#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

long long n, m;
long long ans;

void solve()
{
	scanf("%lld%lld", &n, &m);
	ans = (1 + m) * m / 2 + (m + n * m) * n / 2 - m;
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