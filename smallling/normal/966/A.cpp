#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010;

int l[N], e[N];

int main()
{
	int n, m, cl, ce, v;
	scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
	for(int i = 1; i <= cl; i++)
		scanf("%d", &l[i]);
	sort(l + 1, l + 1 + cl);
	for(int i = 1; i <= ce; i++)
		scanf("%d", &e[i]);
	sort(e + 1, e + 1 + ce);
	l[0] = e[0] = -1e9;
	l[cl + 1] = e[ce + 1] = 1e9;
	int Q;
	scanf("%d", &Q);
	while(Q--)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 == x2)
		{
			printf("%d\n", abs(y1 - y2));
			continue;
		}
		if(x1 > x2)swap(x1, x2), swap(y1, y2);
		int rx = lower_bound(l + 1, l + 1 + cl, y1) - l;
		int lx = rx - 1;
		long long ans = min(0ll + l[rx] - y1 + abs(y2 - l[rx]), 0ll + y1 - l[lx] + abs(y2 - l[lx])) + x2 - x1;
		rx = lower_bound(e + 1, e + 1 + ce, y1) - e;
		lx = rx - 1;
		int times = (x2 - x1 - 1) / v + 1;
		ans = min(ans, min(0ll + e[rx] - y1 + abs(y2 - e[rx]), 0ll + y1 - e[lx] + abs(y2 - e[lx])) + times);
		printf("%lld\n", ans);
	}
}