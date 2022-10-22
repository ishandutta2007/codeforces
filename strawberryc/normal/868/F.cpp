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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 1e5 + 5;
const ll INF = 1e18;

int n, k, a[N], cnt[N];
ll f[N], g[N], now;

void solve(int l, int r, int sl, int sr)
{
	int mid = l + r >> 1, md;
	for (int i = mid; i >= l && i > sr; i--) now += cnt[a[i]]++;
	for (int i = Min(sr, mid); i >= sl; i--)
	{
		now += cnt[a[i]]++;
		if (f[i - 1] + now < g[mid]) g[mid] = f[i - 1] + now, md = i;
	}
	for (int i = Min(sr, mid); i >= sl; i--) now -= --cnt[a[i]];
	for (int i = mid; i >= l && i > sr; i--) now -= --cnt[a[i]];
	if (l < mid)
	{
		for (int i = md + 1; i <= sr && i < l; i++) now += cnt[a[i]]++;
		solve(l, mid - 1, sl, md);
		for (int i = md + 1; i <= sr && i < l; i++) now -= --cnt[a[i]];
	}
	if (mid < r)
	{
		for (int i = mid; i >= l && i > sr; i--) now += cnt[a[i]]++;
		solve(mid + 1, r, md, sr);
		for (int i = mid; i >= l && i > sr; i--) now -= --cnt[a[i]];
	}
}

int main()
{
	read(n); read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) f[i] = (now += cnt[a[i]]++);
	for (int i = 1; i <= n; i++) now -= --cnt[a[i]];
	for (int i = 2; i <= k; i++)
	{
		for (int j = i; j <= n; j++) g[j] = INF;
		solve(i, n, i, n);
		for (int j = i; j <= n; j++) f[j] = g[j];
	}
	return std::cout << f[n] << std::endl, 0;
}