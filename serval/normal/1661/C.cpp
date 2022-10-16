#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 3e5 + 5;

int n;
int h[N];

bool chk(long long d, int H)
{
	long long e = d / 2, o = d - e;
	long long ce = 0, co = 0;
	for (int i = 1; i <= n; i++)
	{
		ce += (H - h[i]) / 2;
		co += (H - h[i]) & 1;
	}
	if (ce > e)
	{
		co += (ce - e) * 2;
		ce = e;
	}
	return co <= o;
}

long long calc(int H)
{
	long long l = 0, r = 1e18;
	while (l < r)
	{
		long long mid = (l + r) >> 1;
		if (chk(mid, H))
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	sort(h + 1, h + n + 1);
	printf("%lld\n", min(calc(h[n]), calc(h[n] + 1)));
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}