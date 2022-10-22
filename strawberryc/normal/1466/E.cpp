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

const int N = 5e5 + 5, EI = 1e9 + 7;

int n, cnt[60], p2[60];
ll x[N];

void work()
{
	memset(cnt, 0, sizeof(cnt));
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x[i]);
		for (int T = 59; T >= 0; T--)
			if ((x[i] >> T) & 1) cnt[T]++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int res1 = 0, res2 = 0;
		for (int T = 59; T >= 0; T--)
			res1 = (1ll * p2[T] * ((x[i] >> T) & 1 ? cnt[T] : 0) + res1) % EI,
			res2 = (1ll * p2[T] * ((x[i] >> T) & 1 ? n : cnt[T]) + res2) % EI;
		ans = (1ll * res1 * res2 + ans) % EI;
	}
	printf("%d\n", ans);
}

int main()
{
	p2[0] = 1;
	for (int i = 1; i <= 59; i++) p2[i] = (p2[i - 1] << 1) % EI;
	int T; read(T);
	while (T--) work();
	return 0;
}