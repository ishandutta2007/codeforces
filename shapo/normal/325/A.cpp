#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

int l, r, t, b;
int n;
int cl, cr, ct, cb;

int main()
{
	scanf("%d", &n);
	int sq = 0;
	l = 31401, r = -1,
	   t = -1, b = 31401;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d", &cl, &cb, &cr, &ct);
		sq += (cr - cl) * (ct - cb);
		l = min(l, cl), r = max(r, cr);
		t = max(t, ct), b = min(b, cb);
	}
	if (r - l == t - b && sq == (r - l) * (t - b))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}