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

template <class T>
inline T Abs(const T &a) {return a < 0 ? -a : a;}

const int N = 2e5 + 5;

int n, a[N];

void work()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i < n; i++) if (Abs(a[i] - a[i + 1]) >= 2)
		return (void) printf("YES\n%d %d\n", i, i + 1);
	puts("NO");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}