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

int n, q, k, a[N];

int main()
{
	int l, r;
	read(n); read(q); read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	while (q--) read(l), read(r), printf("%d\n", 2 * (k - (r - l + 1))
		- (a[l] - 1) - (k - a[r]));
	return 0;
}