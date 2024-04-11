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

const int N = 105, M = 2005;

int n, cnt[M], ans;
char s[N];

int main()
{
	read(n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		int x, y; read(x); read(y);
		bool ini = s[i] == '1';
		cnt[0] += ini; 
		for (int j = 1; j <= 2000; j++)
		{
			if (j >= y && (j - y) % x == 0) ini ^= 1;
			cnt[j] += ini;
		}
	}
	for (int i = 0; i <= 2000; i++) if (cnt[i] > ans) ans = cnt[i];
	return std::cout << ans << std::endl, 0;
}