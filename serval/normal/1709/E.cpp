#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int N = 2e5 + 5;
const int E = N << 1;

int n;
int a[N];
int h[N], nx[E], to[E], et;
int deg[N];
int ans;
int bel[N], msk[N];
set <int> s[N];

void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
	deg[v]++;
}

int merge(int bu, int bv, int trig)
{
	if (!bu)
		return 0;
	if (!bv)
		return bu;
	if (s[bu].size() > s[bv].size())
		swap(bu, bv);
	for (auto v : s[bu])
		if (s[bv].count(v ^ trig ^ msk[bu] ^ msk[bv]))
			return 0;
	for (auto v : s[bu])
		s[bv].insert(v ^ msk[bu] ^ msk[bv]);
	return bv;
}

void solve(int u, int p = 0)
{
	bel[u] = u;
	s[u].insert(0);
	for (int i = h[u]; i; i = nx[i])
		if (to[i] != p)
		{
			solve(to[i], u);
			bel[u] = merge(bel[u], bel[to[i]], a[u]);
		}
	if (bel[u])
		msk[bel[u]] ^= a[u];
	else
		ans++;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ae(u, v);
		ae(v, u);
	}
	int mx = 1;
	for (int i = 1; i <= n; i++)
		if (deg[i] > deg[mx])
			mx = i;
	solve(mx);
	printf("%d\n", ans);
	return 0;
}