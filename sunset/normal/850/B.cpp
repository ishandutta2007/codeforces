#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 2000005;

int n, m, x, y, p, cnt[MAXN];
LL sum[MAXN], ans = LLONG_MAX;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), x = Read(), y = Read(), p = x / y;
	for (int i = 1, x; i <= n; i ++)
		x = Read(), cnt[x] ++, sum[x] += x, m = max(m, x);
	for (int i = 1; i <= m << 1; i ++)
		cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
	for (int d = 2; d <= max(m, 2); d ++)
	{
		LL ret = 0;
		for (int l = 1, r = d; l <= m; l += d, r += d)
		{
			int c = max(l, r - p);
			ret += 1LL * x * (cnt[c - 1] - cnt[l - 1]);
			ret += 1LL * y * (1LL * (cnt[r] - cnt[c - 1]) * r - (sum[r] - sum[c - 1]));
		}
		ans = min(ans, ret);
	}
	cout << ans << endl;
	return 0;
}