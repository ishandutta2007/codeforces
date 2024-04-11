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

const int N = 2e5 + 5;

int n, cnt[N], f[N][2];

void work()
{
	int x;
	read(n);
	for (int i = 1; i <= n; i++) read(x), cnt[x]++;
	for (int i = 0; i <= n * 2; i++) f[i][0] = 0, f[i][1] = -1;
	for (int i = 1; i <= n * 2; i++)
	{
		f[i][0] = Max(f[i - 1][0] + (cnt[i] > 0), f[i - 1][1]);
		if (cnt[i] > 1) f[i][1] = Max(f[i - 1][0] + 2,
			f[i - 1][1] >= 0 ? f[i - 1][1] + 1 : -1);
		if (f[i - 1][1] >= 0 && cnt[i])
			f[i][1] = Max(f[i][1], f[i - 1][1] + 1);
	}
	printf("%d\n", Max(f[n * 2][0], f[n * 2][1]));
	for (int i = 1; i <= n * 2; i++) cnt[i] = 0;
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}