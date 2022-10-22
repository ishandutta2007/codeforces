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

int n, w[N], a[N], d[N], tot;

void work()
{
	int x, y;
	read(n); tot = 0;
	for (int i = 1; i <= n; i++) read(w[i]), d[i] = -1;
	for (int i = 1; i < n; i++) read(x), read(y), d[x]++, d[y]++;
	for (int i = 1; i <= n; i++) while (d[i]--) a[++tot] = w[i];
	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += w[i];
	std::sort(a + 1, a + tot + 1, [&](int x, int y) {return x > y;});
	for (int i = 1; i < n; i++) printf("%lld ", sum), sum += a[i];
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}