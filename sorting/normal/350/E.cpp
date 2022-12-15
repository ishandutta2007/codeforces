#include <bits/stdc++.h>

const int N = 307;

int a[N];
bool b[N];

int main ()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m, k;

	std::cin >> n >> m >> k;

	if(k == n)
	{
		std::cout << "-1\n";

		return 0;
	}

	if(m > n*(n-1)/2 - k + 1)
	{
		std::cout << "-1\n";

		return 0;
	}

	for(int i = 0; i < k; i++)
	{
		std::cin >> a[i];
		b[ a[i] ] = true;
	}

	std::sort(a, a+k);

	int v;

	for(v = 1; v <= n; v++)
		if(!b[v])
			break;

	for(int i = 1; i <= n; i++)
		if(i != a[0] && i != a[1])
		{
			std::cout << a[0] << " " << i << "\n";
		}

	std::cout << a[1] << " " << v << "\n";

	m -= n-1;

	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
		{
			if(!m)
				break;

			if(a[0] == i || a[0] == j)
				continue;
			if(a[1] == i || a[1] == j)
				if((b[i] && b[j]) || (i == v || j == v))
					continue;

			std::cout << i << " " << j << "\n";

			m--;
		}

	return 0;
}