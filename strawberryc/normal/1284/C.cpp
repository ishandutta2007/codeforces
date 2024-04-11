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

const int N = 250005;

int n, rqy, fac[N], ans;

int main()
{
	std::cin >> n >> rqy;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % rqy;
	for (int i = 1; i <= n; i++)
		ans = (1ll * (n - i + 1) * (n - i + 1) % rqy * fac[i] % rqy
			* fac[n - i] + ans) % rqy;
	return std::cout << ans << std::endl, 0;
}