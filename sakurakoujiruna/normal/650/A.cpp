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
	map <pair <int, int>, int> sp;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y;
		mp[0][x] ++;
		mp[1][y] ++;
		sp[{x, y}] ++;
	}

	intl ans = 0;
	for(int t = 0; t < 2; t ++)
		for(auto it = mp[t].begin(); it != mp[t].end(); it ++)
		{
			intl tt = it -> second;
			ans += tt * (tt - 1) / 2;
		}
	for(auto it = sp.begin(); it != sp.end(); it ++)
	{
		intl tt = it -> second;
		ans -= tt * (tt - 1) / 2;
	}
	cout << ans << '\n';
	return 0;
}