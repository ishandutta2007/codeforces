#include <iostream>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

#define mp make_pair

typedef pair < int, int > pii;
typedef vector < pii > vpii;
typedef vector < int > vi;

vpii a;
vi ans;
int min1, id1;
int n, h;
int res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> h;
	a.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	// 0 - based
	res = a[n - 1].first + a[n - 2].first - (a[0].first + a[1].first);
	ans.assign(n, 1);
	id1 = -1;
	for (int i = 0; i < n; ++i)
	{
		if (n == 2)
		{
			break;
		}
		int cur = 0;
		if (i == 0)
		{
			cur -= min(a[0].first + a[1].first + h, a[1].first + a[2].first);
		}
		else if (i == 1)
		{
			cur -= min(a[0].first + a[1].first + h, a[0].first + a[2].first);
		}
		else
		{
			cur -= min(a[i].first + a[0].first + h, a[0].first + a[1].first);
		}
		if (i == n - 2)
		{
			cur += max(a[n - 2].first + a[n - 1].first + h, a[n - 3].first + a[n - 1].first);
		}
		else if (i == n - 1)
		{
			cur += max(a[n - 2].first + a[n - 1].first + h, a[n - 3].first + a[n - 2].first);
		}
		else
		{
			cur += max(a[i].first + a[n - 1].first + h, a[n - 1].first + a[n - 2].first);
		}
		if (cur < res)
		{
			if (id1 != -1)
			{
				ans[id1] = 1;
			}
			id1 = a[i].second;
			ans[id1] = 2;
			res = cur;
		}
	}
	cout << res << "\n";
	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}