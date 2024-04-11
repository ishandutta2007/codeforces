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
const ll INF = 5e18;

int nr, ng, nb, r[N], g[N], b[N];

ll sqr(int x) {return 1ll * x * x;}

ll solve(int na, int nb, int nc, int *a, int *b, int *c)
{
	ll ans = INF;
	for (int i = 1, j = 1, k = 1; j <= nb; j++)
	{
		while (i <= na && a[i] <= b[j]) i++;
		while (k <= nc && b[j] > c[k]) k++;
		if (i > 1 && k <= nc) ans = std::min(ans,
			sqr(a[i - 1] - b[j]) + sqr(b[j] - c[k]) + sqr(c[k] - a[i - 1]));
	}
	return ans;
}

void work()
{
	read(nr); read(ng); read(nb);
	for (int i = 1; i <= nr; i++) read(r[i]);
	for (int i = 1; i <= ng; i++) read(g[i]);
	for (int i = 1; i <= nb; i++) read(b[i]);
	std::sort(r + 1, r + nr + 1); std::sort(g + 1, g + ng + 1);
	std::sort(b + 1, b + nb + 1);
	ll ans = solve(nr, ng, nb, r, g, b);
	ans = std::min(ans, solve(nr, nb, ng, r, b, g));
	ans = std::min(ans, solve(nb, nr, ng, b, r, g));
	ans = std::min(ans, solve(nb, ng, nr, b, g, r));
	ans = std::min(ans, solve(ng, nr, nb, g, r, b));
	ans = std::min(ans, solve(ng, nb, nr, g, b, r));
	printf("%lld\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}