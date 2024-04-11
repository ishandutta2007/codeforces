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

void work()
{
	int a, b, n;
	read(a); read(b); read(n);
	if (n % 3 == 0) printf("%d\n", a);
	else if (n % 3 == 1) printf("%d\n", b);
	else printf("%d\n", a ^ b);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}