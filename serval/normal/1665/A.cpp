#include <cstdio>

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	printf("%d %d %d %d\n", n - 3, 1, 1, 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}