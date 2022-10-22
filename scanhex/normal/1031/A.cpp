#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int w, h, k;
	cin >> w >> h >> k;
	int ans = 0;
	for (int i = 0; i < k; ++i)
	{
		ans += (w + h - 2) * 2;
	 	w -= 4;
		h -= 4;
	}
	cout << ans << '\n';
	return 0;
}