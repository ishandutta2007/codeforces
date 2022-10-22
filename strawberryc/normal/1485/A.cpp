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

int a, b;

void work()
{
	read(a); read(b); int T = 77, cnt = 0, ans = 99999;
	if (b == 1) b++, cnt++;
	while (T--)
	{
		int tmp = a, c = 0;
		while (tmp) tmp /= b, c++;
		if (c + cnt < ans) ans = c + cnt;
		b++; cnt++;
	}
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}