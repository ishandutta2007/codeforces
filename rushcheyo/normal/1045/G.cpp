#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int64;

const int maxn = 100005, M = 35 * maxn, MAX = 1000000000;
int n, k, tot, ls[M], rs[M], size[M];
struct node
{
	int x, r, q;
} a[maxn];
bool operator<(const node &u, const node &v)
{
	return u.r > v.r;
}
unordered_map<int, int> rt;

int query(int x, int l, int r, int ql, int qr)
{
	if (!x) return 0;
	if (l >= ql && r <= qr) return size[x];
	int mid = (l + r) >> 1, ret = 0;
	if (ql <= mid) ret += query(ls[x], l, mid, ql, qr);
	if (qr > mid) ret += query(rs[x], mid + 1, r, ql, qr);
	return ret;
}
void update(int &x, int l, int r, int p)
{
	if (!x) x = ++tot;
	size[x]++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (p <= mid) update(ls[x], l, mid, p);
	else update(rs[x], mid + 1, r, p);
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i].x, &a[i].r, &a[i].q);
	sort(a + 1, a + 1 + n);
	int64 ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i].q - k; j <= a[i].q + k; j++)
			ans += query(rt[j], 1, MAX, max(1, a[i].x - a[i].r), min(MAX, a[i].x + a[i].r));
		int x = rt[a[i].q];
		update(x, 1, MAX, a[i].x);
		rt[a[i].q] = x;
	}
	printf("%lld\n", ans);
}