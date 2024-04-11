#include <bits/stdc++.h>

// 0830

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

const int N = 1005;

int n, h, a[N], b[N];

int main()
{
	n = read(); h = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int T = 1; T <= n; T++)
	{
		for (int i = 1; i <= T; i++) b[i] = a[i];
		std::sort(b + 1, b + T + 1);
		ll sum = 0;
		for (int i = T; i >= 1; i -= 2) sum += b[i];
		if (sum > h) return std::cout << T - 1 << std::endl, 0;
	}
	std::cout << n << std::endl;
	return 0;
}