#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 3e5 + 5;

int n;
int a[N];
long long m;

long long calc(int a, int x)
{
	long long w = 0;
	int o = a / x, r = a % x;
	w += 1ll * r * (o + 1) * (o + 1);
	w += 1ll * (x - r) * o * o;
	return w;
}

long long check(int d)
{
	long long w = 0;
	for (int i = 1; i <= n; i++)
	{
		int x = a[i] - a[i - 1];
		int y = 1ll * (x + d - 1) / d;
		w += calc(x, y);
	}
	return w;
}

class Division
{
public:
	int a, x;
	int mx;
	long long cur, nx;
	Division(int a, int x)
	{
		this->a = a;
		this->x = x;
		cur = calc(a, x);
		if (x == a)
			nx = cur;
		else
			nx = calc(a, x + 1);
		int o = a / x;
		mx = a / o;
	}
};

bool operator < (const Division &a, const Division &b)
{
	return a.cur - a.nx < b.cur - b.nx;
}

priority_queue <Division> pq;

int ans;
long long curw;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%lld", &m);

	int l = 1, r = a[n];
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid) <= m)
			l = mid + 1;
		else
			r = mid;
	}

	long long bound = 2 * l;
	for (int i = 1; i <= n; i++)
	{
		int x = a[i] - a[i - 1];
		int y = 1ll * (x + bound - 1) / bound;
		if (x != y)
			pq.push(Division(x, y));
		ans += y - 1;
		curw += calc(x, y);
	}
	while (curw > m && !pq.empty())
	{
		Division d = pq.top();
		pq.pop();
		long long dw = curw - m;
		int cur = max(min(dw / (d.cur - d.nx), 1ll * d.mx - d.x), 1ll);
		ans += cur;
		curw += cur * (d.nx - d.cur);
		if (d.x + cur < d.a)
			pq.push(Division(d.a, d.x + cur));
	}
	printf("%d\n", ans);
	return 0;
}