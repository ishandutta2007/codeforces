#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e5 + 5;

int n, k;
int a[N];

int lpos[N], lcnt;
long long lreq[N], ladd[N];
int rpos[N], rcnt;
long long rreq[N], radd[N];

void solve()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	a[0] = a[n + 1] = 0;
	lcnt = rcnt = 0;
	long long lcurv = 0, lmin = 0;
	for (int i = k - 1; i >= 0; i--)
	{
		lcurv += a[i];
		lmin = max(-lcurv, lmin);
		if (lcurv >= 0 || i == 0)
		{
			lcnt++;
			lpos[lcnt] = i;
			lreq[lcnt] = lmin;
			ladd[lcnt] = lcurv;
			lcurv = lmin = 0;
		}
	}
	long long rcurv = 0, rmin = 0;
	for (int i = k + 1; i <= n + 1; i++)
	{
		rcurv += a[i];
		rmin = max(-rcurv, rmin);
		if (rcurv >= 0 || i == n + 1)
		{
			rcnt++;
			rpos[rcnt] = i;
			rreq[rcnt] = rmin;
			radd[rcnt] = rcurv;
			rcurv = rmin = 0;
		}
	}
	int lcur = 1, rcur = 1;
	long long cur = a[k];
	while (lcur <= lcnt && rcur <= rcnt)
	{
		if (cur >= lreq[lcur])
		{
			cur += ladd[lcur];
			lcur++;
			continue;
		}
		if (cur >= rreq[rcur])
		{
			cur += radd[rcur];
			rcur++;
			continue;
		}
		break;
	}
	if (lcur > lcnt || rcur > rcnt)
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