#include <bits/stdc++.h>
using namespace std;

const int N = 5011;
const int Mod = (int)1e9 + 7;

struct Point
{
	int x, y;
	Point operator -(Point p) {
		return {x - p.x, y - p.y};
	}
	int len() {
		return abs(x) + abs(y);
	}
}p[N];

int c[N];
vector <int> edges[N];

bool dfs(int cur)
{
	for(auto &x : edges[cur])
		if(c[x] == -1)
		{
			c[x] = c[cur] ^ 1;
			if(dfs(x))
				return true;
		}
		else if(c[x] != (c[cur] ^ 1))
			return true;
	return false;
}

int cnt = 0;
bool solve(int lim, int n)
{
	for(int i = 0; i < n; i ++)
		edges[i].clear();
	for(int i = 0; i < n; i ++)
		for(int j = i + 1; j < n; j ++)
			if((p[i] - p[j]).len() > lim)
			{
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
	cnt = 0;
	fill(c, c + n, -1);
	for(int i = 0; i < n; i ++)
		if(c[i] == -1)
		{
			cnt ++;
			c[i] = 0;
			if(dfs(i))
				return false;
		}
	return true;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y;

	int left = 0, right = 1e4 + 2;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		if(solve(mid - 1, n))
			right = mid;
		else
			left = mid;
	}
	cout << left << '\n';
	solve(left, n);
	int ans = 1;
	for(int i = 0; i < cnt; i ++)
	{
		ans *= 2;
		ans %= Mod;
	}
	cout << ans << '\n';
	return 0;
}