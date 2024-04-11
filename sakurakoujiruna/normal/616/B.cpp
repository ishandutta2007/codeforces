#include <iostream>
using namespace std;

const int Inf = 0x3f3f3f3f;

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	int ans = 0;
	for(int i = 0; i < n; i ++)
	{
		int now_min = Inf;
		for(int j = 0; j < m; j ++)
		{
			int x;
			cin >> x;
			now_min = min(now_min, x);
		}
		ans = max(ans, now_min);
	}
	cout << ans << '\n';
	return 0;
}