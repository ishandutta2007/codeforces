#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5e5 + 5;
const int oo = 1e9;

int n;
int a[N];
int pre[N], suf[N];
int ans;

void calpre()
{
	int p = 1, r = 1, mp;
	while (r < n)
	{
		int c = (a[p + 1] > a[p]);
		mp = ++r;
		while (r < n && (a[r + 1] > a[p]) == c)
		{
			r++;
			if ((a[r] > a[mp]) == c)
				mp = r;
		}
		pre[mp] = pre[p] + 1;
		p = mp;
	}
}
void calsuf()
{
	int p = n, l = n, mp;
	while (l > 1)
	{
		int c = (a[p - 1] > a[p]);
		mp = --l;
		while (l > 1 && (a[l - 1] > a[p]) == c)
		{
			l--;
			if ((a[l] > a[mp]) == c)
				mp = l;
		}
		suf[mp] = suf[p] + 1;
		p = mp;
	}
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pre[i] = suf[i] = oo;
	}
	pre[1] = suf[n] = 0;
	calpre();
	calsuf();
	ans = oo;
	for (int i = 1; i <= n; i++)
		ans = min(ans, pre[i] + suf[i]);
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}