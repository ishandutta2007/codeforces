#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n, nxt[N], nxt2[N], m, a[N], sum[N], col[N];

std::vector<int> ans[3];

void work()
{
	scanf("%d", &n);
	if (n >> 1)
	{
		printf("Q %d ", n >> 1);
		for (int i = 1; i < n; i += 2)
			printf("%d %d ", i, i + 1);
		puts("");
		fflush(stdout);
		for (int i = 1; i < n; i += 2)
			scanf("%1d", &nxt[i]);
	}
	if (n - 1 >> 1)
	{
		printf("Q %d ", n - 1 >> 1);
		for (int i = 2; i < n; i += 2)
			printf("%d %d ", i, i + 1);
		puts("");
		fflush(stdout);
		for (int i = 2; i < n; i += 2)
			scanf("%1d", &nxt[i]);
	}
	a[m = 1] = 1;
	for (int i = 1; i < n; i++)
		if (!nxt[i]) a[++m] = 1;
		else a[m]++;
	a[m + 1] = a[m + 2] = 0;
	if (m < 3)
	{
		printf("A %d %d %d\n", a[1], a[2], a[3]);
		for (int i = 1; i <= a[1]; i++) printf("%d ", i);
		puts("");
		for (int i = a[1] + 1; i <= a[1] + a[2]; i++) printf("%d ", i);
		puts("");
		for (int i = a[1] + a[2] + 1; i <= a[1] + a[2] + a[3]; i++)
			printf("%d ", i);
		puts("");
		return (void) fflush(stdout);
	}
	col[1] = 0; col[2] = 1;
	ans[0].clear(); ans[1].clear(); ans[2].clear();
	for (int i = 1; i <= m; i++) sum[i] = a[i] + sum[i - 1];
	int cnt = 0;
	for (int i = 1; i + 2 <= m; i += i & 1 ? 1 : 3) cnt++;
	printf("Q %d ", cnt);
	for (int i = 1; i + 2 <= m; i += i & 1 ? 1 : 3)
		printf("%d %d ", sum[i], sum[i + 2]);
	puts(""); fflush(stdout);
	for (int i = 1; i + 2 <= m; i += i & 1 ? 1 : 3)
		scanf("%1d", &nxt2[i + 2]);
	if (m > 4)
	{
		cnt = 0;
		for (int i = 3; i + 2 <= m; i += i & 1 ? 1 : 3) cnt++;
		printf("Q %d ", cnt);
		for (int i = 3; i + 2 <= m; i += i & 1 ? 1 : 3)
			printf("%d %d ", sum[i], sum[i + 2]);
		puts(""); fflush(stdout);
		for (int i = 3; i + 2 <= m; i += i & 1 ? 1 : 3)
			scanf("%1d", &nxt2[i + 2]);
	}
	for (int i = 3; i <= m; i++)
		if (nxt2[i]) col[i] = col[i - 2];
		else col[i] = 3 - col[i - 2] - col[i - 1];
	for (int i = 1; i <= m; i++)
		for (int j = sum[i - 1] + 1; j <= sum[i]; j++)
			ans[col[i]].push_back(j);
	printf("A %d %d %d\n", ans[0].size(), ans[1].size(), ans[2].size());
	for (int T = 0; T < 3; T++)
	{
		for (int i = 0; i < ans[T].size(); i++)
			printf("%d ", ans[T][i]);
		puts("");
	}
	fflush(stdout);
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}