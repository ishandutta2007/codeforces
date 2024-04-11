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
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 3e5 + 5, M = 1e6 + 5;

int n, a[N], q, tot, pri[M], mp[M], cnt[M];
bool mark[M], vis[M];

void sieve(int n)
{
	mark[0] = mark[mp[1] = 1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) pri[++tot] = mp[i] = i;
		for (int j = 1; j <= tot; j++)
		{
			if (1ll * i * pri[j] > n) break;
			mark[i * pri[j]] = 1;
			if (i % pri[j] == 0)
			{
				mp[i * pri[j]] = mp[i] % pri[j] == 0 ?
					mp[i] / pri[j] : mp[i] * pri[j];
				break;
			}
			else mp[i * pri[j]] = mp[i] * pri[j];
		}
	}
}

void work()
{
	read(n); ll w;
	for (int i = 1; i <= n; i++) read(a[i]), cnt[mp[a[i]]]++;
	int fis = 0, fes = 0, d = n;
	for (int i = 1; i <= n; i++) fis = Max(fis, cnt[mp[a[i]]]);
	for (int i = 1; i <= n; i++)
	{
		int x = mp[a[i]];
		if (x > 1 && (cnt[x] & 1) && !vis[x]) d -= cnt[x], vis[x] = 1,
			fes = Max(fes, cnt[x]);
	}
	fes = Max(fes, d);
	read(q);
	while (q--) read(w), printf("%d\n", w ? fes : fis);
	for (int i = 1; i <= n; i++) cnt[mp[a[i]]] = 0, vis[mp[a[i]]] = 0;
}

int main()
{
	int T; read(T); sieve(1e6);
	while (T--) work();
	return 0;
}