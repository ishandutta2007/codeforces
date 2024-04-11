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

int n, a[N], l[N], r[N], ans = -1, id;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) l[i] = l[i - 1] | a[i];
	for (int i = n; i >= 1; i--) r[i] = r[i + 1] | a[i];
	for (int i = 1; i <= n; i++)
	{
		int w = a[i] ^ (a[i] & (l[i - 1] | r[i + 1]));
		if (w > ans) ans = w, id = i;
	}
	printf("%d ", a[id]);
	for (int i = 1; i <= n; i++) if (i != id) printf("%d ", a[i]);
	return puts(""), 0;
}