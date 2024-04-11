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

typedef long long ll;

const int N = 2e5 + 5;

int n, a[N];
ll s[N], A[N];

void change(int x, int v)
{
	for (; x <= n; x += x & -x)
		A[x] += v;
}

int firs_grea(ll s)
{
	ll sum = 0; int res = 0;
	for (int i = 18; i >= 0; i--)
		if (res + (1 << i) <= n && sum + A[res + (1 << i)] <= s)
			res += 1 << i, sum += A[res];
	return res + 1;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(s[i]);
	for (int i = 1; i <= n; i++) change(i, i);
	for (int i = n; i >= 1; i--)
		a[i] = firs_grea(s[i]), change(a[i], -a[i]);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return puts(""), 0;
}