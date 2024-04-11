#include <bits/stdc++.h>
using namespace std;

const int N = 100011;
int d[N], h[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++)
		cin >> d[i] >> h[i];

	bool flag = true;
	int ans = max(h[1] + d[1] - 1, h[m] + n - d[m]);
	for(int i = 1; i < m; i ++)
	{
		if(d[i + 1] - d[i] < abs(h[i + 1] - h[i]))
			flag = false;
		ans = max(ans, (d[i + 1] - d[i] - abs(h[i + 1] - h[i])) / 2 + max(h[i], h[i + 1]));
	}
	if(flag)
		cout << ans << '\n';
	else
		cout << "IMPOSSIBLE\n";
	return 0;
}