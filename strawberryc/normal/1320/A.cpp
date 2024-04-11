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
ll ans;

std::map<int, ll> f;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		ll x;
		read(a[i]); ans = std::max(ans, x = f[i - a[i]] + a[i]);
		f[i - a[i]] = std::max(f[i - a[i]], x);
	}
	return std::cout << ans << std::endl, 0;
}