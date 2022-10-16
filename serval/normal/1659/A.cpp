#include <cstdio>

using namespace std;

const int N = 105;

void solve()
{
	int n, r, b;
	scanf("%d%d%d", &n, &r, &b);
	for (int i = 1; i <= b + 1; i++)
	{
		int o = r / (b + 1);
		if (i <= r % (b + 1))
			o++;
		while (o--)
			printf("R");
		if (i <= b)
			printf("B");
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