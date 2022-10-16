#include <bits/stdc++.h>
#define int long long
#define AddModification(t, p, v) mdfy[++m0] = (modification){t, p, v};
#define AddQuery(t, l, r) qry[++q0] = (query){t, l, r};
using namespace std;
const int N = 1e5 + 5, S = 1e6 + 5;
int y[N], lx[N], rx[N], x[N], ly[N], ry[N];
int ans = 1, n, m, o[S], m0, q0;
struct modification
{
	int t, p, v;
	bool operator < (const modification &oth) const { return t < oth.t; }
} mdfy[N << 1];
struct query
{
	int t, l, r;
	bool operator < (const query &oth) const { return t < oth.t; }
} qry[N << 1];
void Modify(modification &opt)
{
	for(int p = opt.p; p < S; p += p & -p)
		o[p] += opt.v;
}
int Query(query &opt)
{
	int res = 0;
	for(int p = opt.r; p; p -= p & -p)
		res += o[p];
	for(int p = opt.l - 1; p; p -= p & -p)
		res -= o[p];
	return res;
}
signed main()
{
	scanf("%lld %lld", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld %lld %lld", &y[i], &lx[i], &rx[i]);
		if(lx[i] == 0 && rx[i] == 1000000) ans++;
		y[i]++; lx[i]++; rx[i]++;
		AddModification(lx[i] - 1, y[i], 1);
		AddModification(rx[i], y[i], -1);
	}
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld %lld %lld", &x[i], &ly[i], &ry[i]);
		if(ly[i] == 0 && ry[i] == 1000000) ans++;
		x[i]++; ly[i]++; ry[i]++;
		AddQuery(x[i], ly[i], ry[i]);
	}
	sort(mdfy + 1, mdfy + m0 + 1);
	sort(qry + 1, qry + q0 + 1);
	int nowm = 1, nowq = 1;
	for(; nowm <= m0 && mdfy[nowm].t == 0; nowm++) Modify(mdfy[nowm]);
	for(int t = 1; t < S; t++)
	{
		for(; nowq <= q0 && qry[nowq].t == t; nowq++) ans += Query(qry[nowq]);
		for(; nowm <= m0 && mdfy[nowm].t == t; nowm++) Modify(mdfy[nowm]);
	}
	printf("%lld\n", ans);
	return 0;
}