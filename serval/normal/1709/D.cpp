#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, m;
int a[N];
int q;

int mx[N << 2];
int sx, sy, fx, fy, k;

void build(int u = 1, int l = 1, int r = m)
{
	if (l == r)
	{
		mx[u] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 ^ 1, mid + 1, r);
	mx[u] = max(mx[u << 1], mx[u << 1 ^ 1]);
}

int getmax(int ql, int qr, int u = 1, int l = 1, int r = m)
{
	if (ql <= l && r <= qr)
		return mx[u];
	int mid = (l + r) >> 1;
	if (qr <= mid)
		return getmax(ql, qr, u << 1, l, mid);
	if (ql > mid)
		return getmax(ql, qr, u << 1 ^ 1, mid + 1, r);
	return max(getmax(ql, qr, u << 1, l, mid),
		getmax(ql, qr, u << 1 ^ 1, mid + 1, r));
}

bool solve()
{
	scanf("%d%d%d%d%d", &sx, &sy, &fx, &fy, &k);
	if (abs(fy - sy) % k != 0)
		return 0;
	if (abs(fx - sx) % k != 0)
		return 0;
	int mx = sx + (n - sx) / k * k;
	if (getmax(min(fy, sy), max(fy, sy)) >= mx)
		return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	build();
	scanf("%d", &q);
	while (q--)
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}