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

ll calc1(int n, ll th)
{
	if (n == -2) return 0;
	ll len = 1ll << n;
	if (th < len) return calc1(n - 2, th);
	else if (th < (len << 1)) return calc1(n - 2, th - len) + (len << 1);
	else if (th < len * 3) return calc1(n - 2, th - (len << 1)) + len * 3;
	else return calc1(n - 2, th - len * 3) + len;
}

ll calc2(int n, ll th)
{
	if (n == -2) return 0;
	ll len = 1ll << n;
	if (th < len) return calc2(n - 2, th);
	else if (th < (len << 1)) return calc2(n - 2, th - len) + len * 3;
	else if (th < len * 3) return calc2(n - 2, th - (len << 1)) + len;
	else return calc2(n - 2, th - len * 3) + (len << 1);
}

int main()
{
	int T; ll n; read(T);
	while (T--)
	{
		read(n); int cnt = 0; ll tmp = 1;
		while (tmp <= n) tmp <<= 2, cnt += 2;
		cnt -= 2; n -= 1ll << cnt;
		if (n % 3 == 0) printf("%lld\n", (1ll << cnt) + n / 3);
		else if (n % 3 == 1) printf("%lld\n", (1ll << cnt + 1) + calc1(cnt, n / 3));
		else printf("%lld\n", (1ll << cnt) * 3 + calc2(cnt, n / 3));
	}
	return 0;
}