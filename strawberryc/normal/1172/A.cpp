#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 2e5 + 5;

int n, a[N], pos1, ans, lst;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 1) pos1 = i;
		if (a[i]) lst = i;
	}
	bool is = 1;
	for (int i = pos1; i <= n; i++)
		if (a[i] != i - pos1 + 1) is = 0;
	if (is)
	{
		bool can = 1;
		for (int i = 1; i < pos1; i++) if (a[i] &&
			i - (a[i] - (n - pos1 + 1) - 1) >= 1) can = 0;
		if (can) return std::cout << pos1 - 1 << std::endl, 0;
	}
	pos1 = 2;
	for (int i = 1; i <= n; i++) if (a[i])
		pos1 = std::max(pos1, i - (a[i] - 3));
	std::cout << pos1 + n - 2 << std::endl;
	return 0;
}