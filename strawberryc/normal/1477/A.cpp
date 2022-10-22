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

int n;
ll k, a[N];

void work()
{
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	ll g = a[2] - a[1];
	for (int i = 3; i <= n; i++)
		g = std::__gcd(g, a[i] - a[i - 1]);
	puts((k % g + g) % g == (a[1] % g + g) % g ? "YES" : "NO");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}