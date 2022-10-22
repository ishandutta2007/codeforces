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

void work()
{
	int a, b; read(a); read(b); b++; if (b > a) b = a;
	ll ans = 0;
	int l = 3, r = b;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (a / mid < mid - 2) r = mid - 1;
		else l = mid + 1;
	}
	for (int i = l; i <= b;)
	{
		int nxt = std::min(a / (a / i), b);
		ans += 1ll * (nxt - i + 1) * (a / i);
		i = nxt + 1;
	}
	l--; if (l > b) l = b;
	for (int i = 3; i <= l;)
	{
		int nxt = std::min(a / (a / i), l);
		ans += 1ll * (i + nxt) * (nxt - i + 1) / 2 - 2ll * (nxt - i + 1);
		i = nxt + 1;
	}
	printf("%lld\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}