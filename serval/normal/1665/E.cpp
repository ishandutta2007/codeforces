#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 50;
const int C = 32 * N;

int n, q;
int a[N];
int rt[N], nt;
int ch[2][C], cnt[C];

void insert(int &u, int lu, int v, int d = 29)
{
	u = ++nt;
	cnt[u] = cnt[lu];
	cnt[u]++;
	ch[0][u] = ch[0][lu];
	ch[1][u] = ch[1][lu];
	if (d < 0)
		return;
	int curbit = 1 << d;
	if (v & curbit)
		insert(ch[1][u], ch[1][lu], v, d - 1);
	else
		insert(ch[0][u], ch[0][lu], v, d - 1);
}

int getval(int lu, int ru, int d)
{
	if (d < 0)
		return 0;
	int curbit = 1 << d;
	if (cnt[ch[1][ru]] - cnt[ch[1][lu]])
		return curbit | getval(ch[1][lu], ch[1][ru], d - 1);
	else
		return getval(ch[0][lu], ch[0][ru], d - 1);
}

int query(int lu, int ru, int d = 29)
{
	if (d < 0)
		return 0;
	int cnt0 = cnt[ch[0][ru]] - cnt[ch[0][lu]];
	int curbit = 1 << d;
	if (cnt0 >= 2)
		return query(ch[0][lu], ch[0][ru], d - 1);
	if (cnt0 == 0)
		return curbit | query(ch[1][lu], ch[1][ru], d - 1);
	int val = getval(ch[0][lu], ch[0][ru], d - 1);
	int lnt = nt;
	int tmpu = 0;
	insert(tmpu, ch[1][ru], val, d - 1);
	int ret = curbit | query(ch[1][lu], tmpu, d - 1);
	nt = lnt;
	return ret;
}

void solve()
{
	scanf("%d", &n);
	nt = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		insert(rt[i], rt[i - 1], a[i]);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(rt[l - 1], rt[r]));
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}