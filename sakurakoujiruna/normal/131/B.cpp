#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll cnt[21];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	while(n --)
	{
		int x;
		cin >> x;
		cnt[x + 10] ++;
	}
	ll ans = 0;
	for(int i = 1; i <= 10; i ++)
		ans += cnt[10 - i] * cnt[10 + i];
	ans += cnt[10] * (cnt[10] - 1) / 2;
	cout << ans << '\n';
	return 0;
}