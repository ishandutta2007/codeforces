#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

long long a, b;

void solve()
{
	scanf("%lld%lld", &a, &b);
	if (a * 3 <= b)
	{
		printf("%lld\n", a);
		return;
	}
	if (b * 3 <= a)
	{
		printf("%lld\n", b);
		return;
	}
	printf("%lld\n", (a + b) / 4);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}