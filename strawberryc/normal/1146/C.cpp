#include <bits/stdc++.h>

const int N = 105;

int n;

void work()
{
	scanf("%d", &n);
	int l = 2, r = n, d, t, ans;
	printf("1 %d 1 ", r - l + 1);
	for (int i = l; i <= r; i++) printf("%d ", i);
	puts(""); fflush(stdout);
	scanf("%d", &d);
	while (l < r)
	{
		int mid = l + r >> 1;
		printf("1 %d 1 ", mid - l + 1);
		for (int i = l; i <= mid; i++) printf("%d ", i);
		puts(""); fflush(stdout);
		scanf("%d", &t);
		if (t == d) r = mid; else l = mid + 1;
	}
	printf("1 %d %d ", n - 1, l);
	for (int i = 1; i <= n; i++) if (i != l) printf("%d ", i);
	puts(""); fflush(stdout);
	scanf("%d", &ans);
	printf("-1 %d\n", ans); fflush(stdout);
}

int main()
{
	int T;
	std::cin >> T;
	while (T--) work();
	return 0;
}