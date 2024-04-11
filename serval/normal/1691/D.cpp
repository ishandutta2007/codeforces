#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
const int C = N << 2;

int n;
int a[N];
pair <int, int> mx[C];
long long pre[N], mxp[C], mnp[C];

void build(int u, int l, int r)
{
	if (l == r)
	{
		mx[u] = make_pair(a[l], l);
		mxp[u] = pre[l];
		mnp[u] = pre[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 ^ 1, mid + 1, r);
	mx[u] = max(mx[u << 1], mx[u << 1 ^ 1]);
	mxp[u] = max(mxp[u << 1], mxp[u << 1 ^ 1]);
	mnp[u] = min(mnp[u << 1], mnp[u << 1 ^ 1]);
}

auto getmxa(int ql, int qr, int u = 1, int l = 0, int r = n)
{
	if (ql <= l && r <= qr)
		return mx[u];
	int mid = (l + r) >> 1;
	if (qr <= mid)
		return getmxa(ql, qr, u << 1, l, mid);
	if (ql > mid)
		return getmxa(ql, qr, u << 1 ^ 1, mid + 1, r);
	return max(getmxa(ql, qr, u << 1, l, mid), getmxa(ql, qr, u << 1 ^ 1, mid + 1, r));
}

long long getmxp(int ql, int qr, int u = 1, int l = 0, int r = n)
{
	if (ql <= l && r <= qr)
		return mxp[u];
	int mid = (l + r) >> 1;
	if (qr <= mid)
		return getmxp(ql, qr, u << 1, l, mid);
	if (ql > mid)
		return getmxp(ql, qr, u << 1 ^ 1, mid + 1, r);
	return max(getmxp(ql, qr, u << 1, l, mid), getmxp(ql, qr, u << 1 ^ 1, mid + 1, r));
}

long long getmnp(int ql, int qr, int u = 1, int l = 0, int r = n)
{
	if (ql <= l && r <= qr)
		return mnp[u];
	int mid = (l + r) >> 1;
	if (qr <= mid)
		return getmnp(ql, qr, u << 1, l, mid);
	if (ql > mid)
		return getmnp(ql, qr, u << 1 ^ 1, mid + 1, r);
	return min(getmnp(ql, qr, u << 1, l, mid), getmnp(ql, qr, u << 1 ^ 1, mid + 1, r));
}

int conq(int l, int r)
{
	if (l == r)
		return 1;
	auto mx = getmxa(l, r);
	int p = mx.second;
	long long mnp = getmnp(l - 1, p - 1);
	long long mxp = getmxp(p, r);
	if (mxp - mnp > mx.first)
		return 0;
	int ret = 1;
	if (l < p)
		ret &= conq(l, p - 1);
	if (p < r)
		ret &= conq(p + 1, r);
	return ret;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	build(1, 0, n);
	if (conq(1, n))
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}