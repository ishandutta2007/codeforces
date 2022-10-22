#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

const int N = 10, INF = 0x3f3f3f3f;

int k, a[N], sum[N];

int getcnt(int st, int len)
{
	if (st + len - 1 <= 7) return sum[st + len - 1] - sum[st - 1];
	int res = sum[7] - sum[st - 1]; len -= 8 - st;
	return res + sum[7] * (len / 7) + sum[len % 7];
}

void work()
{
	int i, ans = INF;
	scanf("%d", &k);
	For (i, 1, 7) scanf("%d", &a[i]);
	For (i, 1, 7) sum[i] = sum[i - 1] + a[i];
	For (i, 1, 7)
	{
		int l = 1, r = INF;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (getcnt(i, mid) >= k) r = mid - 1;
			else l = mid + 1;
		}
		if (l < ans) ans = l;
	}
	printf("%d\n", ans);
}

int main()
{
	int T; std::cin >> T;
	while (T--) work();
	return 0;
}