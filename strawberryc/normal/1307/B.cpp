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

const int N = 1e5 + 5;

int n, x, a[N];

void work()
{
	read(n); read(x);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) if (a[i] == x)
		return (void) puts("1");
	std::sort(a + 1, a + n + 1);
	printf("%d\n", std::max(2, (x + a[n] - 1) / a[n]));
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}