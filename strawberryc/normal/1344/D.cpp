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

const int N = 1e5 + 5;

int n, a[N];
ll k, cnt[N];

ll minx(ll n)
{
	ll x = (-3.0 + sqrt(9.0 + 12.0 * (n - 1))) / 6; if (x) x--;
	while (x * (x + 1) * 3 + 1 <= n) x++;
	return x - 1;
}

ll check(ll mid)
{
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = mid >= a[i] ? 0 : minx(a[i] - mid) + 1;
		if (cnt[i] > a[i]) cnt[i] = a[i]; sum += cnt[i];
	}
	return sum;
}

int main()
{
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	ll l = -3.1e18, r = 1e9 + 4;
	while (l <= r)
	{
		ll mid = l + r >> 1;
		if (check(mid) >= k) l = mid + 1;
		else r = mid - 1;
	}
	ll sum = check(r);
	for (int i = 1; i <= n; i++)
	{
		if (sum > k && cnt[i] && a[i] - (cnt[i] - 1) * cnt[i] * 3 - 1 == r)
			cnt[i]--, sum--;
		printf("%d ", cnt[i]);
	}
	return puts(""), 0;
}