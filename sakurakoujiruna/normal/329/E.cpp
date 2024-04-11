#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100011;
typedef long long intl;
const intl Inf = 0x3f3f3f3f;

int x[N], y[N];
pair <int, int> sx[N], sy[N];
bool vis[2][2];
int px[N], py[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> x[i] >> y[i];
		sx[i] = {x[i], i};
		sy[i] = {y[i], i};
	}
	sort(sx + 1, sx + n + 1);
	sort(sy + 1, sy + n + 1);
	for(int i = 1; i <= n; i ++)
	{
		px[sx[i].second] = i;
		py[sy[i].second] = i;
	}

	int mid = n / 2 + n % 2;
	for(int i = 1; i <= n; i ++)
		vis[px[i] <= mid][py[i] <= mid] = true;

	if(n % 2 == 0)
	{
		intl ans = 0;
		for(int i = 1; i <= mid; i ++)
		{
			ans -= 2 * sx[i].first;
			ans -= 2 * sy[i].first;
		}
		for(int i = mid + 1; i <= n; i ++)
		{
			ans += 2 * sx[i].first;
			ans += 2 * sy[i].first;
		}
		if(vis[0][0] && vis[0][1])
			ans -= 2 * min(sx[mid + 1].first - sx[mid].first,
							sy[mid + 1].first - sy[mid].first);
		cout << ans << '\n';
	}
	else
	{
		intl ans = 0;
		for(int i = 1; i < mid; i ++)
		{
			ans -= 2 * sx[i].first;
			ans -= 2 * sy[i].first;
		}
		for(int i = mid + 1; i <= n; i ++)
		{
			ans += 2 * sx[i].first;
			ans += 2 * sy[i].first;
		}
		if(vis[0][0] && vis[0][1] && sx[mid].second == sy[mid].second)
			ans -= 2 * min(min(sx[mid + 1].first - sx[mid].first,
							sx[mid].first - sx[mid - 1].first),
						min(sy[mid + 1].first - sy[mid].first,
							sy[mid].first - sy[mid - 1].first));
		cout << ans << '\n';
	}
	return 0;
}