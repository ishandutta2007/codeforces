#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = n; i >= 2; i -= 2)
		if (a[i - 1] > a[i])
			swap(a[i - 1], a[i]);
	for (int i = 1; i < n; i++)
		if (a[i] > a[i + 1])
		{
			printf("NO\n");
			return;
		}
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