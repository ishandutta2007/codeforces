#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4e5 + 5;

int n;
int a[N], al, ar;
int b[N], bl, br;

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (a[1] != n && a[n] != n)
	{
		printf("-1\n");
		return;
	}
	al = 1;
	ar = n;
	bl = n + 1;
	br = n;
	b[++br] = n;
	if (a[1] == n)
		al++;
	if (a[n] == n)
		ar--;
	while (al <= ar)
	{
		if (a[al] > a[ar])
			b[--bl] = a[al++];
		else
			b[++br] = a[ar--];
	}
	for (int i = bl; i <= br; i++)
		printf("%d%c", b[i], " \n"[i == br]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}