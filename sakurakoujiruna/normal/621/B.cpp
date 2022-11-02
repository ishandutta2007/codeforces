#include <iostream>
#include <map>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	map <int, int> mp[2];
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		mp[0][x + y] ++;
		mp[1][x - y] ++;
	}

	intl ans = 0;
	for(int i = 0; i < 2; i ++)
		for(auto it = mp[i].begin(); it != mp[i].end(); it ++)
		{
			intl tmp = it -> second;
			ans += tmp * (tmp - 1) / 2;
		}
	cout << ans << '\n';
	return 0;
}