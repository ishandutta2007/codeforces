#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

typedef long long ll;

const int N = 5e5 + 5;

int S, n, m;
ll f[N];

int main()
{
	std::cin >> n;
	S = sqrt(n);
	for (int i = 1; i <= S; i++)
	{
		if (n % i) continue;
		f[++m] = (1ll * (n / i) * (n / i - 1) >> 1) * i + n / i;
		if (1ll * i * i != n)
			f[++m] = (1ll * i * (i - 1) >> 1) * (n / i) + i;
	}
	std::sort(f + 1, f + m + 1);
	for (int i = 1; i <= m; i++) printf("%I64d ", f[i]);
	std::cout << std::endl;
	return 0;
}