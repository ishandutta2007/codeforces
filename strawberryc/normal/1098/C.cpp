#include <bits/stdc++.h>

// 20030830

typedef long long ll;

const int N = 1e5 + 5;

int n, d[N], cnt[N]; ll s;

bool check(int mid)
{
	if ((1ll * n * (n + 1) >> 1) < s) return 0;
	int lst = n, full = 2;
	for (int i = 1; i <= n; i++) d[i] = 1;
	ll tmp = (1ll * n * (n + 1) >> 1) - s;
	while (1)
	{
		while (1ll * d[full - 1] * mid == d[full]) full++;
		while (!d[lst]) lst--;
		if (full >= lst) return 0;
		while (tmp < lst - full) full++;
		tmp -= lst - full;
		d[full]++; d[lst]--;
		if (!tmp) return 1;
	}
	return 0;
}

int main()
{
	std::cin >> n >> s;
	int l = 1, r = n - 1;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	puts(l == n ? "No" : "Yes");
	if (l == n) return 0;
	check(l);
	for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + d[i];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= d[i]; j++)
			printf("%d ", cnt[i - 2] + (j - 1) / l + 1);
	return puts(""), 0;
}