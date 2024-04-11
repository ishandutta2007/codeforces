#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2011;
typedef long long intl;

bool vis[N];
pair <intl, int> p[2][N];

intl dis2(intl &x1, intl &y1, intl &x2, intl &y2)
{
	intl xx = (x1 - x2) * (x1 - x2);
	intl yy = (y1 - y2) * (y1 - y2);
	return xx + yy;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	intl x[2], y[2];
	cin >> x[0] >> y[0];
	cin >> x[1] >> y[1];
	p[0][0] = {0, 0};
	p[1][0] = {0, 0};
	for(int i = 1; i <= n; i ++)
	{
		intl tx, ty;
		cin >> tx >> ty;
		p[0][i] = {dis2(x[0], y[0], tx, ty), i};
		p[1][i] = {dis2(x[1], y[1], tx, ty), i};
	}
	sort(p[0], p[0] + n + 1);
	sort(p[1], p[1] + n + 1);
	reverse(p[1], p[1] + n + 1);

	intl ans = 0x3f3f3f3f3f3f3f3fLL;
	int r = 0;
	for(int i = 0; i <= n; i ++)
	{
		vis[p[0][i].second] = true;
		while(r < n && vis[p[1][r].second])
			r ++;
		ans = min(ans, p[0][i].first + p[1][r].first);
	}
	cout << ans << '\n';
	return 0;
}