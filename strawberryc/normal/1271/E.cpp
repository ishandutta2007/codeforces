#include <bits/stdc++.h>

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 63;

int tot, a[N];
ll k, n, ans;

void chkmax(bool is, ll num, ll o)
{
	if (o >= k) ans = Max(ans, num);
	if (o - 1 >= k) ans = Max(ans, num << 1);
}

int main()
{
	std::cin >> n >> k; ll tmp = n;
	while (tmp) a[++tot] = tmp & 1, tmp >>= 1;
	for (int i = 1; i <= tot; i++)
	{
		ll hop = n >> tot - i, sum;
		if (hop != (1ll << i - 1))
		{
			sum = 0;
			for (int j = 0; j <= tot - i; j++)
				sum += 1ll << j;
			chkmax(i < tot, hop - 1, sum);
		}
		sum = (n & (1ll << tot - i) - 1) + 1;
		for (int j = 0; j < tot - i; j++) sum += 1ll << j;
		if (sum >= k) chkmax(i < tot, hop, sum);
		if (hop != (1ll << i) - 1)
		{
			sum = 0;
			for (int j = 0; j < tot - i; j++) sum += 1ll << j;
			if (sum >= k) chkmax(i < tot, (1ll << i) - 1, sum);
		}
	}
	return std::cout << ans << std::endl, 0;
}