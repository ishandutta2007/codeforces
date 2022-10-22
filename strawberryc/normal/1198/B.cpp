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

const int N = 2e5 + 5, LogN = 20;

int n, a[N], q, rm[N], Log[N], lst[N];

int main()
{
	int op, x, y;
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	read(q);
	for (int i = 1; i <= q; i++)
	{
		read(op); read(x);
		if (op == 1) read(y), lst[x] = i, a[x] = y;
		else rm[i] = x;
	}
	for (int i = q; i >= 1; i--) rm[i] = std::max(rm[i], rm[i + 1]);
	for (int i = 1; i <= n; i++)
		printf("%d ", std::max(a[i], rm[lst[i] + 1]));
	return puts(""), 0;
}