#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, sum[N], cnt, f[N], cur;
char s[N];

int main()
{
	std::cin >> n;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) if (s[i] == '(') cnt++; else cnt--;
	if (cnt) return puts("-1"), 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
	for (int i = 1; i <= n; i++)
		if (f[i] = std::min(sum[i - 1] < 0 ? n << 1 : f[i - 1], cur + i), sum[i] >= 0)
			cur = std::min(cur, f[i] - i);
	return std::cout << f[n] << std::endl, 0;
}