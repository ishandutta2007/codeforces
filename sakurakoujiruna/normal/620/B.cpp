#include <iostream>
using namespace std;

typedef long long intl;

int cnt[10] = {6, 2, 5, 5, 4,
				5, 6, 3, 7, 6};

int solve(int n)
{
	int ret = 0;
	while(n > 0)
	{
		ret += cnt[n % 10];
		n /= 10;
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int l, r;
	cin >> l >> r;
	intl ans = 0;
	for(int i = l; i <= r; i ++)
		ans += solve(i);
	cout << ans << '\n';
	return 0;
}