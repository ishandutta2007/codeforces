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

const int N = 5e5 + 5, djq = 1e9 + 7, zyy = 998244353;

int n, m, pd[N], pz[N];
ll sum[N];

struct hash
{
	int d, z; ll c;
} a[N];

inline bool comp(hash a, hash b)
{
	return a.d < b.d || (a.d == b.d && a.z < b.z);
}

void work()
{
	int x, y;
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(a[i].c), a[i].d = a[i].z = 0;
	while (m--) read(x), read(y),
		a[y].d = (a[y].d + pd[x]) % djq, a[y].z = (a[y].z + pz[x]) % zyy;
	std::sort(a + 1, a + n + 1, comp);
	ll res = 0;
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i].c;
	for (int i = 1; i <= n;)
	{
		int j = i;
		while (j <= n && a[i].d == a[j].d && a[i].z == a[j].z) j++;
		if (a[i].d || a[i].z) res = std::__gcd(res, sum[j - 1] - sum[i - 1]);
		i = j;
	}
	printf("%lld\n", res);
}

int main()
{
	pd[0] = pz[0] = 1;
	for (int i = 1; i <= 500000; i++)
		pd[i] = 2ll * pd[i - 1] % djq, pz[i] = 2ll * pz[i - 1] % zyy;
	int T; read(T);
	while (T--) work();
	return 0;
}