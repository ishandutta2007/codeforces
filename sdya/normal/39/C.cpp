#include <iostream>
#include <set>
#include <map>
#include <vector>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int d[4100][4100];
int n;

pair < int, int > p[2100];

set < int > S;
map < int, int > MP;

vector < int > start[4100];
vector < int > finish[4100];

int solve(int l, int r)
{
	if (d[l][r] != -1) return d[l][r];
	d[l][r] = 0;
	if (l == r) return d[l][r];
	d[l][r] = max(solve(l, r - 1), solve(l + 1, r));
	int add = 0;
	for (int i = 0; i < start[l].size(); i ++)
	{
		int v = start[l][i];
		if (p[v].second == r) add = 1; else
			if (p[v].second < r)
				d[l][r] = max(d[l][r], solve(l, p[v].second) + solve(p[v].second, r));
	}
	for (int i = 0; i < finish[r].size(); i ++)
	{
		int v = finish[r][i];
		if (p[v].first == l) add = 1; else
			if (p[v].first > l)
				d[l][r] = max(d[l][r], solve(l, p[v].first) + solve(p[v].first, r));
	}
	d[l][r] += add;
	return d[l][r];
}

vector < int > ans;

void get(int l, int r)
{
	if (d[l][r] == 0) return ;
	int add = 0, g = 0;
	for (int i = 0; i < start[l].size(); i ++)
	{
		int v = start[l][i];
		if (p[v].second == r) add = 1, g = v;
	}
	if (d[l][r] == solve(l, r - 1) + add)
	{
		get(l, r - 1);
		if (add != 0) 
			ans.push_back(g);
		return ;
	}
	if (d[l][r] == solve(l + 1, r) + add)
	{
		get(l + 1, r);
		if (add != 0) 
			ans.push_back(g);
		return ;
	}
	for (int i = 0; i < start[l].size(); i ++)
	{
		int v = start[l][i];
		if (p[v].second < r && d[l][r] == solve(l, p[v].second) + solve(p[v].second, r) + add)
		{
			get(l, p[v].second);
			get(p[v].second, r);
			if (add != 0)
				ans.push_back(g);
			return ;
		}
	}
	for (int i = 0; i < finish[r].size(); i ++)
	{
		int v = finish[r][i];
		if (p[v].first > l && d[l][r] == solve(l, p[v].first) + solve(p[v].first, r) + add)
		{
			get(l, p[v].first);
			get(p[v].first, r);
			if (add != 0)
				ans.push_back(g);
			return ;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		int a, b;
		cin >> a >> b;
		p[i] = make_pair(a - b, a + b);
		S.insert(a - b);
		S.insert(a + b);
	}

	int t = 0;
	for (set < int > :: iterator it = S.begin(); it != S.end(); it ++)
		t ++, MP[* it] = t;
	for (int i = 1; i <= n; i ++)
		p[i].first = MP[p[i].first], p[i].second = MP[p[i].second];

	for (int i = 1; i <= n; i ++)
		start[p[i].first].push_back(i),
		finish[p[i].second].push_back(i);

	for (int i = 1; i <= t; i ++)
		for (int j = 1; j <= t; j ++)
			d[i][j] = -1;

	int res = solve(1, t);
	printf("%d\n", res);
	get(1, t);
	for (int i = 0; i < ans.size(); i ++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}