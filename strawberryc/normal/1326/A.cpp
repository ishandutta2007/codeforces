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

int n;

void work()
{
	read(n);
	if (n == 1) puts("-1");
	else
	{
		putchar('2');
		for (int i = 1; i < n; i++) putchar('9');
		puts("");
	}
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}