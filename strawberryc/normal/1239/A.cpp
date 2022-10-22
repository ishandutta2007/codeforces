#include <bits/stdc++.h>

const int N = 1e5 + 5, rqy = 1e9 + 7;

int n, m, f[N];

int main()
{
	std::cin >> n >> m;
	f[0] = 1;
	for (int i = 1; i <= n || i <= m; i++)
	{
		f[i] = f[i - 1];
		if (i > 1) f[i] = (f[i] + f[i - 2]) % rqy;
	}
	std::cout << (2ll * (f[n] + f[m]) + rqy - 2) % rqy << std::endl;
	return 0;
}