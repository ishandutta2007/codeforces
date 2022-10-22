#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ax, ay;
	cin >> ax >> ay;
	int bx, by;
	cin >> bx >> by;
	int cx, cy;
	cin >> cx >> cy;
	--ax, --ay, --bx, --by, --cx, --cy;
	auto ok = [&](int x, int y)
	{
		if (x == ax || y == ay)
			return false;
		if (abs(x - y) == abs(ax - ay))
			return false;
		if (x + y == ax + ay)
			return false;
		return true;
	};
	vector<vector<bool>> used(n, vector<bool>(n));
	vector<pair<int, int>> q = {{bx, by}};
	used[bx][by] = true;
	for (int i = 0; i < q.size(); ++i)
	{
		int x = q[i].first, y = q[i].second; 
		for (int x1 = x - 1; x1 <= x + 1; ++x1)
			for (int y1 = y - 1; y1 <= y + 1; ++y1)
			{
				if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= n || used[x1][y1] || !ok(x1, y1))
					continue;
				used[x1][y1] = true;
				q.emplace_back(x1, y1);
			}
	}
	if (used[cx][cy])
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}