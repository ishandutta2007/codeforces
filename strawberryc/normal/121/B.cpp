#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 1e5 + 5;

int n, k, a[N];

int main()
{
	int pos = 1;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);
	for (int i = 1; i <= k; i++)
	{
		while (pos < n && (a[pos] != 4 || a[pos + 1] != 7)) pos++;
		if (pos == n) break;
		if (pos & 1)
		{
			a[pos + 1] = 4;
			if (a[pos + 2] == 7)
			{
				if (k - i & 1) a[pos + 1] = 7;
				for (int i = 1; i <= n; i++) printf("%d", a[i]);
				return std::cout << std::endl, 0;
			}
		}
		else
		{
			a[pos] = 7;
			if (a[pos - 1] == 4)
			{
				if (k - i & 1) a[pos] = 4;
				for (int i = 1; i <= n; i++) printf("%d", a[i]);
				return std::cout << std::endl, 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) printf("%d", a[i]);
	std::cout << std::endl;
	return 0;
}