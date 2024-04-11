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

const int N = 105;

int n, ans;
bool a[N];

int main()
{
	int x;
	read(n);
	for (int i = 1; i <= n; i++) read(x), a[x] = 1;
	for (int i = 1; i <= 100; i++)
	{
		bool is = 1;
		for (int j = 1; j < i; j++) if (i % j == 0 && a[j]) is = 0;
		if (is && a[i]) ans++;
	}
	return std::cout << ans << std::endl, 0;
}