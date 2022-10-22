#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 4e5 + 5;

int n, a[N], ans, b[N];

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int T = 26; T >= 0; T--)
	{
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= n; i++)
			if ((a[i] >> T) & 1) c1++; else c0++;
		if ((c0 & 1) && (c1 & 1)) ans |= 1 << T;
	}
	for (int T = 26; T >= 1; T--)
	{
		for (int i = 1; i <= n; i++) b[i] = a[i] & (1 << T) - 1;
		std::sort(b + 1, b + n + 1);
		int cnt = 0;
		for (int i = n, j = 1; i >= 1; i--)
		{
			while (j <= n && b[j] + b[i] < (1 << T)) j++;
			if (j < i) cnt ^= i - j & 1;
			else break;
		}
		if (cnt) ans ^= 1 << T;
	}
	return std::cout << ans << std::endl, 0;
}