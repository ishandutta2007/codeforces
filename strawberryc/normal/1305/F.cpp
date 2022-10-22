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

const int N = 2e5 + 5, M = N << 1, T = 1234567;

int n, ans, m;
ll a[N], L, R, num[M];
bool mark[T];

void calc(ll num)
{
	if (num == 1) return;
	ll res = 0;
	for (int i = 1; i <= n; i++)
		if ((res += Min(a[i] < num ? num : a[i] % num,
			(num - a[i] % num) % num)) >= n) return;
	ans = Min(ans, (int) res);
}

int main()
{
	read(n); ans = n;
	for (int i = 1; i <= n; i++) read(a[i]);
	L = a[1] - n; R = a[1] + n;
	if (L < 1) L = 1; m = R - L + 1;
	for (int i = 1; i <= m; i++) num[i] = L + i - 1;
	for (int i = 2; i <= 2000; i++) if (!mark[i])
		for (int j = i * i; j <= 1100000; j += i)
			mark[j] = 1;
	for (int x = 2; x <= 1100000; x++) if (!mark[x])
	{
		int st = L % x ? x - L % x + 1 : 1;
		for (int j = st; j <= m; j += x)
			while (num[j] % x == 0) num[j] /= x;
	}
	std::sort(num + 1, num + m + 1);
	m = std::unique(num + 1, num + m + 1) - num - 1;
	for (int x = 2; x <= 1100000; x++) if (!mark[x]) calc(x);
	for (int i = 1; i <= m; i++) calc(num[i]);
	return std::cout << ans << std::endl, 0;
}