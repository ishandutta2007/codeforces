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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 1e5 + 5, M = 64, INF = 0x3f3f3f3f;

int n, f[M][N], id[N], tmp0[N], tmp1[N];
ll a[N], mx;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), mx = Max(mx, a[i]);
	for (int i = 1; i <= n; i++) a[i] = mx - a[i];
	for (int T = 0; T <= 60; T++)
		for (int i = 0; i <= n; i++)
			f[T][i] = INF;
	f[0][0] = 0;
	for (int i = 1; i <= n; i++) id[i] = i;
	for (int T = 1; T <= 60; T++)
	{
		int t = T - 1, cnt0 = 0, cnt1 = 0, cnti = 0;
		for (int i = 1; i <= n; i++)
			if ((a[i] >> t) & 1) cnt1++;
			else cnt0++;
		for (int i = 0; i <= n; i++)
		{
			if (i)
			{
				((a[id[i]] >> t) & 1 ? cnt1 : cnt0)--;
				((a[id[i]] >> t) & 1 ? cnti : cnt1)++;
			}
			f[T][cnti] = Min(f[T][cnti], f[T - 1][i] + cnt1);
			f[T][cnt1 + cnti] = Min(f[T][cnt1 + cnti], f[T - 1][i] + cnt0 + cnti);
		}
		int tot0 = 0, tot1 = 0;
		for (int i = 1; i <= n; i++)
			if ((a[id[i]] >> t) & 1) tmp1[++tot1] = id[i];
			else tmp0[++tot0] = id[i];
		for (int i = 1; i <= tot1; i++) id[i] = tmp1[i];
		for (int i = 1; i <= tot0; i++) id[i + tot1] = tmp0[i];
	}
	return std::cout << f[60][0] << std::endl, 0;
}