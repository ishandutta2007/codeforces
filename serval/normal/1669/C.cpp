#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int chk = 0;
	for (int i = 1; i <= n; i += 2)
		chk |= (a[i] ^ a[1]) & 1;
	for (int i = 2; i <= n; i += 2)
		chk |= (a[i] ^ a[2]) & 1;
	if (chk)
		printf("NO\n");
	else
		printf("YES\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}