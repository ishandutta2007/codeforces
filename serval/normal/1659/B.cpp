#include <cstdio>

using namespace std;

const int N = 2e5 + 5;

int n, k;
char s[N];
int a[N];

void solve()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	if (k & 1)
	{
		for (int i = 1; i <= n; i++)
			s[i] ^= 1;
	}
	for (int i = 1; i <= n; i++)
		if (k && s[i] == '0')
		{
			a[i] = 1;
			s[i] ^= 1;
			k--;
		}
		else
			a[i] = 0;
	a[n] += k;
	if (k & 1)
		s[n] ^= 1;
	printf("%s\n", s + 1);
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[i], " \n"[i == n]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}