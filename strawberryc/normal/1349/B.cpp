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

int n, k, a[N];

void work()
{
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	bool is1 = 0, is2 = 0;
	for (int i = 1; i <= n; i++) if (a[i] == k) is1 = 1;
	if (!is1) return (void) puts("no");
	if (n == 1) return (void) puts("yes");
	for (int i = 1; i < n; i++) if (a[i] >= k && a[i + 1] >= k) is2 = 1;
	for (int i = 1; i < n - 1; i++) if (a[i] >= k && a[i + 2] >= k) is2 = 1;
	puts(is2 ? "yes" : "no");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}