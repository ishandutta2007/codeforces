#include <bits/stdc++.h>
#define p2 p << 1
#define p3 p << 1 | 1

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

const int N = (1 << 20) + 5;

int h, g, a[N], dep[N], tot, res[N];
ll ans;

int get_right(int p)
{
	if (p >= (1 << h - 1) || (!a[p2] && !a[p3])) return dep[p];
	return a[p2] > a[p3] ? get_right(p2) : get_right(p3);
}

void del(int p)
{
	if (p >= (1 << h - 1) || (!a[p2] && !a[p3])) return (void) (a[p] = 0);
	if (a[p2] > a[p3]) a[p] = a[p2], del(p2);
	else a[p] = a[p3], del(p3);
}

void dfs(int p)
{
	if (dep[p] > g) return;
	while (get_right(p) > g) res[++tot] = p, ans -= a[p], del(p);
	dfs(p2); dfs(p3);
}

void work()
{
	read(h); read(g); ans = 0; tot = 0;
	for (int i = 1; i < (1 << h); i++) read(a[i]), ans += a[i];
	for (int i = 1; i <= h; i++)
		for (int p = 1 << i - 1; p < (1 << i); p++) dep[p] = i;
	dfs(1);
	printf("%lld\n", ans);
	for (int i = 1; i <= tot; i++) printf("%d ", res[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}