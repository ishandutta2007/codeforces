#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 2e5 + 5;

int n;
long long s;
long long a[N];
int p[N];
int ans, l, r;

set <int> st;

bool cmp(int x, int y)
{
	if (a[x] != a[y])
		return a[x] < a[y];
	return x < y;
}

void solve()
{
	scanf("%d", &n);
	scanf("%lld", &s);
	p[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
		p[i] = i;
	}
	sort(p, p + n + 1, cmp);
	int pl = -1;
	st.clear();
	st.insert(n + 1);
	ans = 0;
	for (int i = 0; i <= n; i++)
	{
		while (pl < n && a[p[pl + 1]] < a[p[i]] - s)
		{
			pl++;
			st.insert(p[pl]);
		}
		auto it = st.lower_bound(p[i]);
		int cur = *it - p[i] - 1;
		if (cur > ans)
		{
			ans = cur;
			l = p[i] + 1;
			r = *it - 1;
		}
	}
	if (ans)
		printf("%d %d\n", l, r);
	else
		printf("-1\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}